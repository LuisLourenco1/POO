#include"Pessoa.h"

namespace poo {
    // sobrecarga do operador << para imprimir objetos da classe Pessoa
    ostream &operator<<(ostream &output, const Pessoa &pessoa) {
        output << "Nome: " << pessoa.getNome() << endl << "CPF: " << pessoa.getCPF() << endl;
        return output;
    }
    
    // construtor
    Pessoa::Pessoa(string nome, string cpf) {
        this->nome = nome;
        this->CPF = cpf;
    }
    
    // destrutor
    Pessoa::~Pessoa() {
        cout << "Chamada do destrutor" << endl;
    }

    // retorna o nome
    string Pessoa::getNome() const {
        return this->nome;
    }
    
    // retorna o CPF
    string Pessoa::getCPF() const {
        return this->CPF;
    }
}