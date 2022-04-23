#ifndef MUSEU_H
#define MUSEU_H

#include <iostream>
#include <string>
#include <vector>

#include "ObraDeArte.h"
#include "Pintura.h"
#include "Escultura.h"

using namespace std;

namespace catalogo{
    class Museu{
        friend bool operator==(const ObraDeArte &, const ObraDeArte &); // sobrecarga do operador == para comparar obras de arte
    private:
        string nome; 
        vector<ObraDeArte*> obras; //Armazena todas as obras no catálogo do museu.  
    public:
        Museu(string); //Construtor.
        ~Museu(); //Destrutor.
        void setNome(string); //método setter para nome do museu.
        string getNome() const; //Método getter para nome do museu.
        bool adicionaObra(ObraDeArte *); //Método para adicionar obra ao catalogo.
        bool removeObra(string); //Método para remover obra do catalogo.
        ObraDeArte* obtemObra(string); //Método retorna obra com titulo igual dentro do catalogo.
        int qt(int); //Método auxiliar para as funções qtdeObras, qtdeEsculturas e qtdepinturas. 
        int qtdeObras(); //Método retorna quantidade de obras no catalogo.
        int qtdePinturas(); //Método retona quantidade de pinturas no catalogo.
        int qtdeEsculturas(); //Métode retorna quantidade de esculturas no catalogo.
        void bubbleSort(); //procedimento auxiliar a função imprime.
        void imprime(int); //Procedimento imprime a ficha de obras no catálogo de acordo com a categoria.
    };
}
#endif