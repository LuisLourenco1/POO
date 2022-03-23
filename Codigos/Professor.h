#ifndef PROFESSOR_H
#define PROFESSOR_H

#include<iostream>
#include<string>
using namespace std;

#include"Pessoa.h"

namespace poo {
    class Professor : public Pessoa {
        friend ostream &operator<<(ostream &, const Professor &);
    private:
        string universidade;
    public:
        Professor(string, string, string);
        ~Professor();
        string getUniversidade() const;
    };
}

#endif