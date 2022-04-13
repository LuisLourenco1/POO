#ifndef PINTURA_H
#define PINTURA_H

// Bibliotecas
#include<iostream>
#include<string>
#include"ObraDeArte.h"

using namespace std;

namespace catalogo {
    class Pintura : public ObraDeArte {
    private:
        string tipo; // armazena o tipo de pintura
    public:
        Pintura(string, string, string, int, string); // construtor
        ~Pintura(); // destrutor
        virtual int getCategoria() const; // método que retorna a categoria
        string getTipo() const; // método que retorna o tipo
        void setTipo(string); // procedimento que seta o tipo
        virtual void imprimeFicha() const; // procedimento que imprime os dados da pintura
    };  
}

#endif