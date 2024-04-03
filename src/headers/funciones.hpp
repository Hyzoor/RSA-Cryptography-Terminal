#pragma once

// **********************************************
// 
// int mcd(a, b)                -->     Return Maximum common divisor (a,b)
// int power(b, exp)            -->     Return b^exp
// int calcularPotenciaModulo   -->     Return x^y mod(m). Needed for big numbers
// int Menu(p, q)               -->     Start Menu. Options(Encrypt, Decrypt) And user sets the prime numbers p, q
// 
// **********************************************

int mcd(int, int);
unsigned long long int power(int, int);
unsigned long long int calcularPotenciaModuloM(int, int, int);
void Menu(unsigned int &, unsigned int &);
void Menu(int&);

void IntroducirClavesPublicas(unsigned int&, unsigned int&);
void IntroducirClavesPrivadas(unsigned int&, unsigned int&);

#include "../funciones.cpp"