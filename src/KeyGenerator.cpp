#include <iostream>
#include <fstream>
#include "headers/keys.hpp"
#include "headers/funciones.hpp"
#include "headers/KeyGenerator.hpp"

using namespace std;

void KeyGen(){

    /*----------------------------------------------------------------------------------------------------------------------------------------*/

    unsigned int p = {0};                                   // Numeros primos necesarios                                                
    unsigned int q = {0};                                   // para generar las claves
    ofstream keysFile("keys.txt");                // Fichero para guardar las claves
    
    /*----------------------------------------------------------------------------------------------------------------------------------------*/

    Menu(p,q);
    key claves(p, q);


    if(keysFile.is_open()){

        keysFile << "\n\tClaves generadas [NO COMPARTIR] : \n\n";
        keysFile << "\tClave publica para cifrar: " << claves.getClavePublica();
        keysFile << "\n\tClave privada para descifrar: " << claves.getClavePrivada();
        keysFile << "\n\tModulo publico para cifrar/descifrar: " << claves.getModulo();

        keysFile.close();
    }

    cout << "\n\tClaves generadas con exito! :)";

    cout << "\n\n\t"; system("pause");
}