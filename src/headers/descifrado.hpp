#pragma once
#include <string>
#include "keys.hpp"
#include "funciones.hpp"




char descifrarLetra(unsigned int, const key &claves);
void descifrarMensaje(std::string &, std::string &, const key &);




#include "../descifrado.cpp"