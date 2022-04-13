#include"ObraDeArte.h"

namespace catalogo {
    // não houve verificação de anoCriacao ser maior que 0 pois o ano pode ser a.C.
    ObraDeArte::ObraDeArte(string titulo, string artista, string material, int anoCriacao) : titulo(titulo), artista(artista), material(material), ano(anoCriacao) {}

    ObraDeArte::~ObraDeArte() {
        cout << "Destrutor" << endl;
    }

    string ObraDeArte::getTitulo() const {
        return this->titulo;
    }

    string ObraDeArte::getArtista() const {
        return this->artista;
    }

    string ObraDeArte::getMaterial() const {
        return this->material;
    }

    int ObraDeArte::getAno() const {
        return this->ano;
    }

    void ObraDeArte::setTitulo(string titulo) {
        this->titulo = titulo;
    }

    void ObraDeArte::setArtista(string artista) {
        this->artista = artista;
    }

    void ObraDeArte::setMaterial(string material) {
        this->material = material;
    }

    void ObraDeArte::setAno(int ano) {
        this->ano = ano;
    }

    // procedimento que imprime os dados genéricos da obra (os específicos são implementados em suas classes filhas)
    void ObraDeArte::imprimeFicha() const {
        cout << "Título: " << getTitulo() << endl;
        cout << "Artista: " << getArtista() << endl;
        cout << "Material: " << getMaterial() << endl;
        cout << "Ano: " << getAno() << endl;
    }
}