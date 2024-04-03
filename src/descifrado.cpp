#include <string>
#include "headers/keys.hpp"


// 184.835. 12.3434.564.


char descifrarLetra(unsigned int letracifrada, const key &claves){

    int letradescifrada;
    letradescifrada = calcularPotenciaModuloM(letracifrada, claves.getClavePrivada(), claves.getModulo());
    return claves.getCodificacion().at(letradescifrada);

}

void descifrarMensaje(std::string &mensaje, std::string &descifrado, const key &claves){

    std::string numero;
    unsigned int letracifrada;

    for(auto elem : mensaje){

        if(elem != ' ' && elem != '.'){
            numero.push_back(elem);
        }
        else if(elem == '.'){
            letracifrada = std::stoi(numero); //Convierto a int
            descifrado += descifrarLetra(letracifrada, claves);
            numero.clear();
        }
        else{
            descifrado.push_back(' ');
        }

    }


}
