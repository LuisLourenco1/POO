#ifndef SESSAO_H
#define SESSAO_H
#include "DataHorario.h"

class Sessao
{
	public:
		Sessao(string, DataHorario&);
		~Sessao();
		string proximoLivre()
		bool verifica(string) 
		bool ocupa(string, Pessoa&)
		bool desocupa(string) 
		int vagas()
		Operador << 
	protected:
};

#endif
