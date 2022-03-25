#include"Estudante.h"

namespace poo {
    // sobrecarga do operador << para imprimir objetos da classe Estudante
    ostream &operator<<(ostream &output, const Estudante &estudante) {
        output << "Nome: " << estudante.getNome() << endl << "CPF: " << estudante.getCPF() << endl << "Média Final: " << estudante.media() << endl;
        return output;
    }

    // construtor da classe Estudante, que também chama o construtor da classe Pessoa para setar o nome e cpf
    Estudante::Estudante(string nome, string cpf, int ra, double nota1P, double nota2P, double nota1T, double nota2T) : Pessoa(nome, cpf) {
        RA = (ra >= 0) ? ra : 0;
        nota1Prova = (nota1P >= 0 && nota1P <= 10) ? nota1P : 0;
        nota2Prova = (nota2P >= 0 && nota2P <= 10) ? nota2P : 0;
        nota1Trabalho = (nota1T >= 0 && nota1T <= 10) ? nota1T : 0;
        nota2Trabalho = (nota2T >= 0 && nota2T <= 10) ? nota2T : 0;
    }

    // destrutor
    Estudante::~Estudante() {
        cout << "Chamada do destrutor" << endl;
    }

    // retorna o RA
    int Estudante::getRA() const {
        return this->RA;
    }

    // calcula e retorna a média
    double Estudante::media() const {
        double MP = (nota1Prova + nota2Prova) / 2;
        double MT = (nota1Trabalho + nota2Trabalho) / 2;
        double MF = (MP * 8 + MT * 2) / 10;
        return MF;
    }

    // retorna se o aluno foi aprovado
    bool Estudante::aprovado() const {
        return (media() >= 6);
    }

    // retorna se o aluno ficou de sac
    bool Estudante::sac() const {
        double m = media();
        return (m >= 5 && m < 6);
    }

    // retorna a nota necessária para o estudante que ficou de sac ser aprovado
    double Estudante::notaSAC() const {
        if (sac()) {
            double SAC = 12 - media();
            return SAC;
        } else {
            return 0;
        }
    }
}