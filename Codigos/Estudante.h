#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include<iostream>
#include<string>
using namespace std;

#include"Pessoa.h"

namespace poo {
    class Estudante : public Pessoa {
        friend ostream &operator<<(ostream &, const Estudante &);
    private:
        int RA;
        double nota1Prova, nota2Prova;
        double nota1Trabalho, nota2Trabalho;
    public:
        Estudante(string, string, int, double, double, double, double);
        ~Estudante();
        int getRA() const;
        double media() const;
        bool aprovado() const;
        bool sac() const;
        double notaSAC() const;
    };
}

#endif