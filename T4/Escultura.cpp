#include"Escultura.h"

namespace catalogo {
    Escultura::Escultura(string titulo, string artista, string material, int anoCriacao, double altura) : ObraDeArte(titulo, artista, material, anoCriacao) {
        setAltura(altura); // como precisa verificar se é maior que 0, chama-se o método que seta a altura
    }

    Escultura::~Escultura() {
        cout << "Destrutor" << endl;
    }

    // como o objeto dessa classe será sempre uma Escultura, então esse método sempre retorna 2
    int Escultura::getCategoria() const {
        return 2;
    }

    double Escultura::getAltura() const {
        return this->altura;
    }

    void Escultura::setAltura(double altura) {
        this->altura = altura > 0 ? altura : 1;
    }

    // procedimento que imprime os dados de uma Escultura
    void Escultura::imprimeFicha() const {
        cout << "Categoria: Escultura" << endl;
        ObraDeArte::imprimeFicha(); // chama o procedimento de ObraDeArte que imprime titulo, artista, material e ano
        cout << "Altura: " << getAltura() << endl;
    }
}