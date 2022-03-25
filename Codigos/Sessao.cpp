#include "Sessao.h"
#include "DataHorario.h"
#include <iostream>
#include<string>

using namespace std;

Sessao::Sessao(string nome_Peca, DataHorario&){
  this->nome_Peca = nome_peca;   
}

string Sessao::getNome_Peca() const {
        return this->nome_peca;
 }

Sessao::~Sessao(){
  cout << "Chamada do destrutor" << endl;
}

string proximoLivre(){
  if(pessoa[210] == 

