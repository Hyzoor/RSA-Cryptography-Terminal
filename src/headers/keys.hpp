#pragma once
#include<string>

// Keys Generator for RSA from 2 prime numbers (p,q)
//          and alphabet codification
// 
// CONSTRUCTION: (prime1, prime2, alphabetcodi)
// 
//  ***********************  PUBLIC OPERATIONS ***********************

//  unsinged int getClavePublica( )     -->     Return clave publica para cifrar    (e)
//  unsigned int getClavePrivada( )     -->     Return clave privada para descifrar (d)
//  unsigned int getModulo( )           -->     Return Modulo M = pq. Forma parte de la clave publica (e, m)
//  const string& getCodificacion( )    -->     Return la codificacion, para poder acceder

//  *********************** PRIVATE OPERATIONS ***********************

//  void setFi( )               -->     Set number fi = (p - 1)(q - 1)
//  void setClavePublica( )     -->     Set public key  (e) = coprimo con fi <-> mcd(e,fi) = 1
//  void setClavePrivada( )     -->     Set private key (d) => ed = 1 mod(fi)   Inverso de (e) en mod fi
//  void setCodificacion( )     -->     Set codificacion on construction

// *******************************************************************

class key{

    public:
        //Constructores
        key();
        key(unsigned int, unsigned int);

        //Metodos
        unsigned int getClavePrivada() const;
        unsigned int getClavePublica() const;
        unsigned int getModulo() const;
        const std::string& getCodificacion() const;

        //Metodos para introducir claves
        void setClavePublica(unsigned int);
        void setModulo(unsigned int);
        void setClavePrivada(unsigned int);
        void setCodificacion(const std::string &);

    private:
    
        //Metodos para calcular claves
        void setFi();
        void setClavePublica();
        void setClavePrivada();


        //Atributos
        unsigned int p, q, m;           //Numeros primos privados
        unsigned int fi;                      //Numero para crear las claves (fi de euler)
        unsigned int publica,privada;   //Claves      
        std::string codificacion;       //Orden del abecedario

};

#include "../keys.cpp"