#include"Pessoa.h"

namespace poo {
    ostream &operator<<(ostream &output, const Pessoa &pessoa) {
        output << "Nome: " << pessoa.nome << endl << "CPF: " << pessoa.CPF << endl;
        return output;
    }
    
    Pessoa::Pessoa(string nome, string cpf) {
        this->nome = nome;
        CPF = cpf;
    }
    
    Pessoa::~Pessoa() {
        cout << "Chamada do destrutor" << endl;
    }

    string Pessoa::getNome() const {
        return this->nome;
    }
    
    string Pessoa::getCPF() const {
        return this->CPF;
    }
}