#include"Estudante.h"

namespace poo {
    ostream &operator<<(ostream &output, const Estudante &estudante) {
        output << "Nome: " << estudante.getNome() << endl << "CPF: " << estudante.getCPF() << endl << "Média Final: " << estudante.media() << endl;
        return output;
    }

    Estudante::Estudante(string nome, string cpf, int ra, double nota1P, double nota2P, double nota1T, double nota2T) : Pessoa(nome, cpf) {
        RA = (ra >= 0) ? ra : 0;
        nota1Prova = (nota1P >= 0 && nota1P <= 10) ? nota1P : 0;
        nota2Prova = (nota2P >= 0 && nota2P <= 10) ? nota2P : 0;
        nota1Trabalho = (nota1T >= 0 && nota1T <= 10) ? nota1T : 0;
        nota2Trabalho = (nota2T >= 0 && nota2T <= 10) ? nota2T : 0;
    }

    Estudante::~Estudante() {
        cout << "Chamada do destrutor" << endl;
    }

    int Estudante::getRA() const {
        return this->RA;
    }

    double Estudante::media() const {
        double MP = (nota1Prova + nota2Prova) / 2;
        double MT = (nota1Trabalho + nota2Trabalho) / 2;
        double MF = (MP * 8 + MT * 2) / 10;
        return MF;
    }

    bool Estudante::aprovado() const {
        return (media() >= 6);
    }

    bool Estudante::sac() const {
        double m = media();
        return (m >= 5 && m < 6);
    }

    double Estudante::notaSAC() const {
        if (sac()) {
            double SAC = 12 - media();
            return SAC;
        } else {
            return 0;
        }
    }
}