#pragma once
#include <string>
#include "keys.hpp"
#include "funciones.hpp"


// Encrypter. From string --> encrypted numbers 
// 
//  **********************************************  FUNCTIONS **********************************************
// 
//  void mensajeToUpper( mensaje )                  -->     Rewrites mensaje to uppercase. "Hello" --> "HELLO"
//  int cifrarLetra( A , claves )                   -->     Returns number = encrypted letter with keys
//  void cifrarMensaje( mensaje , cifrado , keys)   -->     Writes on 'cifrado' encrypted 'mensaje' with keys

// **********************************************************************************************************

void mensajeToUpper(std::string&);
int  cifrarLetra(int, const key&);
void cifrarMensaje(std::string&, std::string&, const key&);


#include "../cifrado.cpp"