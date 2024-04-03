#include <iostream>
#include "headers/funciones.hpp"


int mcd(int a, int b){
    int m {1};
    int aux;

    if(a < b) aux = a;
    else aux = b;

    for(int i{2}; i < aux; i++){
        if(a % i == 0 && b % i == 0){
            m = i;
            break;
        }  
    }

    return m;
}

unsigned long long int  power(int base, int exponente){
    
    unsigned long long int resultado {0};
    resultado += base;

    for(int i {1}; i < exponente; i++){
        resultado *= base;
    }

    return resultado;
}


unsigned long long int calcularPotenciaModuloM(int letra, int exponente, int modulo){

    int n = exponente / 2;
    unsigned long long int resultado {1};

    for(int i{0}; i < n; i++){
        resultado *= (power(letra, 2) % modulo);
        resultado %= modulo;
    }

    if(exponente % 2 == 0){}
    else{
        resultado *= (letra % modulo);
        resultado %= modulo;
    }

    return resultado;
}

void Menu(unsigned int &_p, unsigned int &_q){
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n\n";
    std::cout << "\tBienvenido a mi herramienta de Criptofrafia RSA :)\n";
    std::cout << "\tAqui generaremos las claves necesarias para cifrar y descifrar\n";
    std::cout << "\tIntroduce por favor dos numeros primos para generar las claves: \n\n";
    std::cout << "\tNumero primo p = "; std::cin >> _p;
    std::cout << "\tNumero primo q = "; std::cin >> _q;
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
}

void Menu(int& op){
    std::cout << "\n\t\t1 - Cifrar un mensaje\n\t\t2 - Descifrar un mensaje\n\t\t0 - Salir y cerrar la herramienta\n\n";
    std::cout << "\tPor favor introduzca que desea realizar: "; std::cin >> op;
    std::cout << "\n-----------------------------------------------------------------------------------------------------------------------\n";
}

void IntroducirClavesPublicas(unsigned int& pub, unsigned int& mod){
    system("cls");
    std::cout << "\n\tIntroduce tu clave publica para cifrar el mensaje: "; std::cin >> pub;
    std::cout << "\tIntroduce el modulo: "; std::cin >> mod;
}

void IntroducirClavesPrivadas(unsigned int& priv, unsigned int& mod){
    system("cls");
    std::cout << "\n\tIntroduce tu clave privada para descifrar el mensaje: "; std::cin >> priv;
    std::cout << "\tIntroduce el modulo: "; std::cin >> mod;
}

