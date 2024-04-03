#include <iostream>
#include <fstream>
#include "headers/funciones.hpp"
#include "headers/keys.hpp"
#include "headers/cifrado.hpp"
#include "headers/descifrado.hpp"




using namespace std;

int main(){

    /*----------------------------------------------------------------------------------------------------------------------------------------*/

    unsigned int privada {0};           // Clave publica para cifrar
    unsigned int publica {0};           // Clave privada para descifrar
    unsigned int modulo {0};            // Modulo para ambos (publico)

    key claves;
    string linea;
    string textoResultado;

    string codificacion = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};   // Orden del alfabeto para la codificacion
    claves.setCodificacion(codificacion);

    /*----------------------------------------------------------------------------------------------------------------------------------------*/

    bool correct{true};
    int opcion = {1};
    system("cls");
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
    std::cout << "\tBienvenido a mi herramienta de Criptofrafia RSA :)\n";
    std::cout << "\tAqui cifraremos y descifraremos los mensajes que desees.\n";

    while(true){

        linea.clear();
        textoResultado.clear();

        Menu(opcion);

        if(opcion == 1){    //Cifrado

            IntroducirClavesPublicas(publica, modulo);
            claves.setClavePublica(publica);
            claves.setModulo(modulo);

            cout << "\tAntes de continuar escriba el mensaje a cifrar en mensaje.txt";
            cout << "\n\n\t"; system("pause");

            ofstream outputFile("mensajefinal.txt");
            ifstream inputFile("mensaje.txt");

            if(inputFile.is_open() && outputFile.is_open()){
        
                while(getline(inputFile, linea)){
                    cifrarMensaje(linea, textoResultado, claves);
                    textoResultado.push_back('\n');
                    linea.clear();
                }

                outputFile << textoResultado;
                cout << "\n\tSu texto cifrado se encuentra en el archivo mensajefinal.txt";
                cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";

                   
            } 
        }else if(opcion == 2){  //Descifrado

            IntroducirClavesPrivadas(privada, modulo);
            claves.setClavePrivada(privada);
            claves.setModulo(modulo);

            cout << "\tAntes de continuar escriba el mensaje a descifrar en mensaje.txt";
            cout << "\n\n\t"; system("pause");

            ofstream outputFile("mensajefinal.txt");
            ifstream inputFile("mensaje.txt");

            if(inputFile.is_open() && outputFile.is_open()){
        
                while(getline(inputFile, linea)){
                    try{
                        descifrarMensaje(linea, textoResultado, claves);
                    }catch(...){
                        cout << "\tExcepcion. Claves incorrectas";
                        correct = false;
                    }
                    
                    textoResultado.push_back('\n');
                    linea.clear();
                }

                if(correct){
                    cout << "\n\tSu texto descifrado se encuentra en el archivo mensajefinal.txt";
                    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
                }else{
                    cout << "\n\tSu texto no se ha descifrado debido a un fallo en las credenciales";
                    cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
                }

                outputFile << textoResultado;

            }

        }else{
            cout << "\n\tCerrando la herramienta de RSA";
            cout << "\n\n\t"; system("pause");
            break;
        }
    }


    return 0;
}