#ifndef SESSAO_H
#define SESSAO_H
#include "Pessoa.h"
#include "DataHorario.h"
using namespace std;

namespace poo {
	class Sessao
	{
		friend ostream &operator<<(ostream& output, Sessao &sessao);
		public:
			Sessao(string, DataHorario&);
			~Sessao();
			string proximoLivre();
			bool verifica(string);
			bool ocupa(string, Pessoa&);
			bool desocupa(string); 
			int vagas();
		private:
			string nomeDaPeca;
			DataHorario &dataHorario;
			Pessoa *poltronas[15][14]; 
	};
}
#endif
