#include "Museu.h"
#include "Categoria.h"

namespace catalogo{

    bool operator==(const ObraDeArte &obra1, const ObraDeArte &obra2) {
        if (obra1.getTitulo() != obra2.getTitulo())
            return false;
        if (obra1.getMaterial() != obra2.getMaterial())
            return false;
        if (obra1.getArtista() != obra2.getArtista())
            return false;
        if (obra1.getAno() != obra2.getAno())
            return false;
        return true;
    }

    Museu::Museu(string nome) : nome(nome){}

    Museu::~Museu(){
        cout << "Destrutor" << endl;
    }

    void Museu::setNome(string nome){
        this->nome = nome;
    }

    string Museu::getNome() const{
        return this->nome;
    }

    bool Museu::adicionaObra(catalogo::ObraDeArte * obra){
        int i = 0;
        while(i < obras.size()){
            //Se a obra já existe no catalogo, método retorna false.
            if(obras[i] == obra)
                return false;
            i++;
        }
        //Se a função não retornou, obra é inserida no catalogo e função retorna true.
        obras.push_back(obra);
        return true;
    }

    bool Museu::removeObra(string titulo){
        int i = 0;
        //Procurando o título passado como parâmetro.
        while(i < obras.size() && obras[i]->getTitulo().string::compare(titulo)){
            i++;
        }
        if(i != obras.size()){
            //Removendo a obra do catalogo.
            obras.erase(obras.begin() + i);
            return true;
        }
        //Se o título não foi encontrado, método retrona false.
        return false;
    }

    ObraDeArte * Museu::obtemObra(string titulo){
        int i = 0;
        while(i < obras.size() && obras[i]->getTitulo().string::compare(titulo)){
            i++;
        }
        //Retornando obra com titulo igual ao passado por parâmetro.
        if(i != obras.size()){
            return obras[i];
        }
        //Retornando null caso a obra não esteja no catalogo.
        return nullptr;
    }

    int Museu::qt(int categoria){
        int i = 0;
        int pinturas, esculturas;
        pinturas = esculturas = 0;
        while(i < obras.size()){
            //Contador de pinturas.
            if(obras[i]->getCategoria() == 1)
                pinturas++;
            //Contador de esculturas.
            else
                esculturas++;
            i++;
        }
        //Retorna a quantidade de acordo com a categoria passada por parâmetro.
        switch(categoria){
            case TODOS:
                return pinturas+esculturas;
            case PINTURA:
                return pinturas;
            case ESCULTURA:
                return esculturas;
            default:
                return 0;
        }
    }

    int Museu::qtdeObras(){
        return qt(0);
    }

    int Museu::qtdePinturas(){
        return qt(1);
    }

    int Museu::qtdeEsculturas(){
        return qt(2);
    }

   //Algoritmo de ordenação bubble sort modificado para comparação entre classes. 
    void Museu::bubbleSort(){
        int i, j;
        i = j = 0; 
        ObraDeArte * temp;
        while(i < obras.size() - 1){
            // Last i elements are already in place
            while(j < obras.size() - i - 1){
                //Ordenação de acordo com o ano.
                if (obras[j]->getAno() > obras[j + 1]->getAno()){
                    temp = obras[j];
                    obras[j] = obras[j+1];
                    obras[j+1] = temp;
                }
                //Caso o ano for o mesmo, ordenação em ordem alfabética.
                else if(obras[j]->getAno() == obras[j + 1]->getAno()){
                    //Função compare retorna positiva se a segunda string [j+1] for "menor" alfabeticamente.
                    if(obras[j]->getTitulo().compare(obras[j + 1]->getTitulo()) > 0){
                        temp = obras[j];
                        obras[j] = obras[j+1];
                        obras[j+1] = temp;
                    }
                }
                j++;
            }
            i++;
        }
    }

    void Museu::imprime(int categoria){
        int i = 0;
        //Ordenando a lista pelo critério ano + título.
        bubbleSort();
        while(i < obras.size()){
            switch(categoria){
                //Caso categoria passada por parâmetro seja 0, imprime todos.
                case TODOS:
                    obras[i]->imprimeFicha();
                    i++;
                    break;
                case PINTURA:
                    //Apenas imprime pinturas.
                    if(obras[i]->getCategoria() == 1)
                        obras[i]->imprimeFicha();
                    i++;
                    break;
                case ESCULTURA:
                    //Apenas imprime esculturas.
                    if(obras[i]->getCategoria() == 2)
                        obras[i]->imprimeFicha();
                    i++;
                    break;
            }
        }
    }
}

