#ifndef SESSAO_H
#define SESSAO_H
#include "Pessoa.h"
#include "DataHorario.h"
using namespace std;

namespace poo {
	class Sessao
	{
		friend ostream &operator<<(ostream& output, const Sessao &sessao);
		public:
			Sessao(string, DataHorario&);
			~Sessao();
			string proximoLivre() const;
			bool verifica(string) const;
			bool verifica(int, int) const;
			bool ocupa(string, Pessoa&);
			bool desocupa(string); 
			int vagas() const;
			string getNomeDaPeca() const;
			string posicaoDeLinhaColuna(int linha, int coluna) const;
			int calcularLinha(string posicao) const;
			int calcularColuna(string posicao) const;
			bool linhaEColunaValidas(int, int) const;
			Pessoa& pessoaDaPoltrona(int, int) const;
		private:
			string nomeDaPeca;
			DataHorario &dataHorario;
			Pessoa *poltronas[15][14]; 
			int qtdVagasLivres;		
	};
}
#endif
