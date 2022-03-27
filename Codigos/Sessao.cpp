#include "Sessao.h"
#include "DataHorario.h"
#include <string.h>
#include <iostream>

namespace poo {
    Sessao::Sessao(string nomeDaPeca, DataHorario &h) : 
        nomeDaPeca(nomeDaPeca), dataHorario(h) {

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 14; j++) {
                poltronas[i][j] = NULL;
            }
        }
        qtdVagasLivres = 15*14;
    }

    Sessao::~Sessao()
    {
        
    }

    ostream &operator<<(ostream &output, const Sessao &sessao) {
        cout << endl;
        cout << "Nome da peça: " << sessao.getNomeDaPeca() << endl;
        cout << "Horário: " << sessao.dataHorario;

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 14; j++) {
                if (sessao.verifica(i, j)) {
                    cout << endl;
                    cout << sessao.pessoaDaPoltrona(i, j);
                    cout << "Poltrona: " << sessao.posicaoDeLinhaColuna(i, j) << endl;
                }
            }
        }
        return output;
    }

    string Sessao::getNomeDaPeca() const {
        return this->nomeDaPeca;
    }

    Pessoa& Sessao::pessoaDaPoltrona(int linha, int coluna) const {
        return *poltronas[linha][coluna];
    }

    int Sessao::vagas() const {
        return this->qtdVagasLivres;
    }

    //Retorna a primeira poltrona livre.
    string Sessao::proximoLivre() const {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 14; j++) {
                if (!verifica(i, j)) { // se não estiver ocupado
                    return posicaoDeLinhaColuna(i, j);
                }
            }
        }
        return "cheio";
    }

    // Pega uma posição e calcula a linha int para a matriz
    int Sessao::calcularLinha(string posicao) const{
        int l = posicao[0] - 'A';
        return l;
    }

    // Pega uma posição e calcula a coluna int para a matriz
    int Sessao::calcularColuna(string posicao) const {
        int c = stoi(posicao.substr(1)) - 1;
        return c;
    }

    // Transforma uma posicao da matriz (int, int) em uma posição string
    // Ex: linha 0, coluna 4 fica: A5
    string Sessao::posicaoDeLinhaColuna(int linha, int coluna) const {
        char cLinha = 'A' + linha;
        string posicao;
        posicao.push_back(cLinha);
        posicao += to_string(coluna + 1);
        return posicao;
    }

    // Verifica se uma poltrona está ocupada
    bool Sessao::verifica(string posicao) const {
        int linha = calcularLinha(posicao);
        int coluna = calcularColuna(posicao);

        //Posições inválidas para linha e coluna
        if (!linhaEColunaValidas(linha, coluna)) {
            return false;
        }
        return poltronas[linha][coluna] 
        == NULL ? false : true;
    }

    // Sobrecarga
    bool Sessao::verifica(int linha, int coluna) const {
        //Posições inválidas para linha e coluna
        if (!linhaEColunaValidas(linha, coluna)) {
            return false;
        }
        return poltronas[linha][coluna] == NULL ? false : true;
    }

    bool Sessao::linhaEColunaValidas(int linha, int coluna) const {
        if ((linha > 14 || linha < 0) || (coluna > 13 || coluna < 0)) {
            return false;
        }
        return true;
    }


    bool Sessao::ocupa(string posicao, Pessoa &p) {
        // Se estiver ocupado, não pode ocupar.
        if (verifica(posicao)){
            cout << "Poltrona já ocupada!" << endl;
            return false;
        }

        int linha = calcularLinha(posicao);
        int coluna = calcularColuna(posicao);

        poltronas[linha][coluna] = &p;

        //Se estiver ocupada, então a ocupação deu certo.
        if (verifica(posicao)) {
            qtdVagasLivres--;
            return true;
        }
        //Se deu erro ao ocupar a poltrona.
        return false;
    }

    bool Sessao::desocupa(string posicao) {
        int linha = calcularLinha(posicao);
        int coluna = calcularColuna(posicao);
        delete poltronas[linha][coluna];
        poltronas[linha][coluna] = NULL;

        //Se deu erro ao desocupar a poltrona e ela ainda estiver ocupada
        if (verifica(posicao)) {
            return false;
        }
        qtdVagasLivres++;
        return true;
    }

    // POLTRONAS POSSÍVEIS
    /*
    A1 A2 A3 A4 A5 A6 A7 A8 A9 A10 A11 A12 A13 A14
    B1 B2 B3 B4 B5 B6 B7 B8 B9 B10 B11 B12 B13 B14
    C1 C2 C3 C4 C5 C6 C7 C8 C9 C10 C11 C12 C13 C14
    D1 D2 D3 D4 D5 D6 D7 D8 D9 D10 D11 D12 D13 D14
    E1 E2 E3 E4 E5 E6 E7 E8 E9 E10 E11 E12 E13 E14
    F1 F2 F3 F4 F5 F6 F7 F8 F9 F10 F11 F12 F13 F14
    G1 G2 G3 G4 G5 G6 G7 G8 G9 G10 G11 G12 G13 G14
    H1 H2 H3 H4 H5 H6 H7 H8 H9 H10 H11 H12 H13 H14
    I1 I2 I3 I4 I5 I6 I7 I8 I9 I10 I11 I12 I13 I14
    J1 J2 J3 J4 J5 J6 J7 J8 J9 J10 J11 J12 J13 J14
    K1 K2 K3 K4 K5 K6 K7 K8 K9 K10 K11 K12 K13 K14
    L1 L2 L3 L4 L5 L6 L7 L8 L9 L10 L11 L12 L13 L14
    M1 M2 M3 M4 M5 M6 M7 M8 M9 M10 M11 M12 M13 M14
    N1 N2 N3 N4 N5 N6 N7 N8 N9 N10 N11 N12 N13 N14
    O1 O2 O3 O4 O5 O6 O7 O8 O9 O10 O11 O12 O13 O14
    */
}
