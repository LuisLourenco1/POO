#include"Pintura.h"
#include "Categoria.h"

namespace catalogo {
    Pintura::Pintura(string titulo, string artista, string material, int anoCriacao, string tipo) : ObraDeArte(titulo, artista, material, anoCriacao), tipo(tipo) {}

    Pintura::~Pintura() {
        cout << "Destrutor" << endl;
    }

    // como o objeto dessa classe será sempre uma pintura, então esse método sempre retorna 1
    int Pintura::getCategoria() const {
        return PINTURA;
    }

    string Pintura::getTipo() const {
        return this->tipo;
    }

    void Pintura::setTipo(string) {
        this->tipo = tipo;
    }

    // procedimento que imprime os dados de uma pintura
    void Pintura::imprimeFicha() const {
        cout << "Categoria: Pintura" << endl;
        ObraDeArte::imprimeFicha(); // chama o procedimento de ObraDeArte que imprime titulo, artista, material e ano
        cout << "Tipo: " << getTipo() << endl;
    }
}