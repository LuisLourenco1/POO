#include"Professor.h"

namespace poo {
    ostream &operator<<(ostream &output, const Professor &professor) {
        output << "Nome: " << professor.getNome() << endl << "CPF: " << professor.getCPF() << endl << "Universidade: " << professor.getUniversidade() << endl;
        return output;
    }

    Professor::Professor(string nome, string cpf, string universidade) : Pessoa(nome, cpf) {
        this->universidade = universidade;
    }

    Professor::~Professor() {
        cout << "Chamada do destrutor" << endl;
    }

    string Professor::getUniversidade() const {
        return this->universidade;
    }
}