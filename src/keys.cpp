#include <ctime>
#include "headers/keys.hpp"
#include "headers/funciones.hpp"

//Metodos para obtener las claves de cifrado y descifrado
unsigned int key::getClavePublica() const{
    return publica;
}
unsigned int key::getClavePrivada() const{
    return privada;
}

unsigned int key::getModulo() const{
    return m;
}

const std::string& key::getCodificacion() const{
    return codificacion;
}   


//Metodos de calculo de claves
void key::setClavePublica(){

    srand(time(NULL));


    while(mcd(publica, fi) != 1){
        publica = rand()%fi;
    }
}

void key::setClavePrivada(){

    for(int i{1}; true; i++){

        int resultado = ((publica * i) - 1) % fi;

        if(resultado == 0){
            privada = i;
            break;
        }
    }
}

void key::setCodificacion(const std::string &_codificacion){
    codificacion = _codificacion;
}


//Constructores
key::key(){
    p = 0;
    q = 0;
    m = 0;
    setFi();
}

key::key(unsigned int _p, unsigned int _q){
    p = _p;
    q = _q;
    m = p * q;
    setFi();
    setClavePublica();
    setClavePrivada();
}

void key::setFi(){
    fi = (p-1)*(q-1);
}

//Metodos para introducir claves

void key::setClavePublica(unsigned int pu){
    publica = pu;
}

void key::setClavePrivada(unsigned int pri){
    privada = pri;
}

void key::setModulo(unsigned int _m){
    m = _m;
}