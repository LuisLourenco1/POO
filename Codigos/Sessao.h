#ifndef SESSAO_H
#define SESSAO_H
#include "Pessoa.h"
#include "DataHorario.h"
using namespace std;

namespace poo {
	class Sessao
	{
		// sobrecarga do operador << para imprimir as informações da sessão de teatro 
		friend ostream &operator<<(ostream& output, Sessao &sessao);
		public:
		// Construtor com parâmetros
			Sessao(string, DataHorario&);
		// Destrutor
			~Sessao();
		// Método que verifica o número da próxima poltrona livre
			string proximoLivre();
		// Método boolean para verificar se a poltrona está ocupada
			bool verifica(string) const;
		// Método boolean que ocupa a poltrona recebida por parâmetro
			bool ocupa(string, Pessoa&);
		// Método boolean que desocupa a poltrona recebida por parâmetro
			bool desocupa(string); 
		// Método que retorna o número de assentos disponíveis
			int vagas();
		// Método que retorna o nome da peça
			string getNomeDaPeca() const;
		private:
		
			string nomeDaPeca;
			DataHorario &dataHorario;
			Pessoa *poltronas[15][14]; 
			int qtdVagasLivres;
	};
}
#endif
