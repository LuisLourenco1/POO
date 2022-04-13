#ifndef ESCULTURA_H
#define ESCULTURA_H

// Bibliotecas
#include<iostream>
#include<string>
#include"ObraDeArte.h"

using namespace std;

namespace catalogo {
    class Escultura : public ObraDeArte {
    private:
        double altura; // armazena a altura da escultura
    public:
        Escultura(string, string, string, int, double); // construtor
        ~Escultura(); // destrutor
        virtual int getCategoria() const; // método que retorna a categoria
        double getAltura() const; // método que retorna a altura
        void setAltura(double); // procedimento que seta a altura
        virtual void imprimeFicha() const; // procedimento que imprime os dados da escultura
    };
}

#endif