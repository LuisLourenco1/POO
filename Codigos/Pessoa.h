#ifndef PESSOA_H
#define PESSOA_H

#include<iostream>
#include<string>
using namespace std;

namespace poo {
    class Pessoa {
        friend ostream &operator<<(ostream &, const Pessoa &);
    private:
        string nome;
        string CPF;
    public:
        Pessoa(string, string);
        ~Pessoa();
        string getNome() const;
        string getCPF() const;
    };
}

#endif