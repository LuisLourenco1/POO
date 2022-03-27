#include"Professor.h"

namespace poo {
    // sobrecarga do operador << para imprimir objetos da classe Professor
    ostream &operator<<(ostream &output, const Professor &professor) {
        output << "Nome: " << professor.getNome() << endl << "CPF: " << professor.getCPF() << endl << "Universidade: " << professor.getUniversidade() << endl;
        return output;
    }

    // construtor da classe Professor, que também chama o construtor da classe Pessoa para setar o nome e cpf
    Professor::Professor(string nome, string cpf, string universidade) : Pessoa(nome, cpf) {
        this->universidade = universidade;
    }

    // destrutor
    Professor::~Professor() {
        //cout << "Chamada do destrutor" << endl;
    }

    // retorna a universidade
    string Professor::getUniversidade() const {
        return this->universidade;
    }
}