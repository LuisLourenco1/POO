#ifndef OBRADEARTE_H
#define OBRADEARTE_H

// Bibliotecas
#include<iostream>
#include<string>

using namespace std;

namespace catalogo {
    class ObraDeArte {
    private:
        string titulo; // armazena o título da obra de arte
        string artista; // armazena o nome do artista que fez a obra
        string material; // armazena o material com que foi feita a obra
        int ano; // armazena o ano em que a obra foi produzida
    public:
        ObraDeArte(string, string, string, int); // construtor
        ~ObraDeArte(); // destrutor
        string getTitulo() const; // método que retorna o título
        string getArtista() const; // método que retorna o artista
        string getMaterial() const; // método que retorna o material
        int getAno() const; // método que retorna o ano
        void setTitulo(string); // procedimento que seta o título
        void setArtista(string); // procedimento que seta o artista
        void setMaterial(string); // procedimento que seta o material
        void setAno(int); // procedimento que seta o ano
        virtual int getCategoria() const = 0; // método puro que retorna a categoria da obra de arte
        // P.S: não fiz imprimeFicha() como sendo procedimento puro pois tanto pintura como escultura têm essas propriedades, então achei melhor imprimi-las aqui e chamar esse procedimento no imprimeFicha() das classes filhas
        virtual void imprimeFicha() const; // procedimento que imprime os dados da obra de arte
    };
}

#endif