#include<string>
#include "headers/keys.hpp"
#include "headers/funciones.hpp"


void mensajeToUpper(std::string& mensaje){
    for(auto &elem: mensaje){
        elem = toupper(elem);
    }
}

int cifrarLetra(int letra , const key &claves){

    int letracifrada { 0 };
    
    letracifrada = calcularPotenciaModuloM(letra, claves.getClavePublica(), claves.getModulo());

    //unsigned long long int mensaje = power(letra, claves.getClavePublica());
    //letracifrada = mensaje % claves.getModulo();

    return letracifrada;
}

void cifrarMensaje(std::string &mensaje, std::string &cifrado, const key &claves){

    mensajeToUpper(mensaje);

    for(auto elem : mensaje){

        if(elem == ' '){cifrado.push_back(elem);}
        else
        {

        int letra = claves.getCodificacion().find(elem);  //Transforma la letra elem en su respectivo numero segun la codificacion
        int letracifrada = cifrarLetra(letra, claves);    //Me cifra la letra en valor numerico aplicando el rsa.

        cifrado += std::to_string(letracifrada);    //Concateno al mensaje cifrado                
        cifrado += (".");

        }
    }

}