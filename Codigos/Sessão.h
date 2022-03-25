#ifndef SESSAO_H
#define SESSAO_H
#include "DataHorario.h"
#include <iostream>
#include<string>

using namespace std;

namespace poo {
	class Sessao{
	public:
		Sessao(string, DataHorario&);
		~Sessao();
		int getNome_Peca() const;
		string proximoLivre();
		bool verifica(string);
		bool ocupa(string, Pessoa&);
		bool desocupa(string);
		int vagas();
		Operador << 
	private:
		string nome_peca;
		int Poltronas[15][15];
	}
};

#endif
