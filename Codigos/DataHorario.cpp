#include "DataHorario.h"

namespace poo {
    //Sobrecarga do operador de impressão.
    ostream &operator<<(ostream &output, const DataHorario &dataHorario) {  
        output << dataHorario.dia << " de " << dataHorario.mes << " de " << dataHorario.ano << " - " << dataHorario.hora 
        << "horas, " << dataHorario.minuto << "minutos, " << dataHorario.segundo << "segundos." << endl;
        return output;
    }
    //Construtor com verificação da data.
    DataHorario::DataHorario(int Dia, int Mes, int Ano, int Hora, int Minuto, int Segundo) {
        //Verificação do limite máximo de "dia" de acordo com o mes.
        if(Mes == 2){
            //Verificação de ano bissexto apenas em fevereiro.
            if (((Ano % 4 == 0) && (Ano % 100 != 0)) || (Ano % 400 == 0))
                dia = (Dia > 0 && Dia <= 29) ? Dia : 1;
            else
                dia = (Dia > 0 && Dia <= 28) ? Dia : 1;
        }   
        else{
            if(Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11)
                dia = (Dia > 0 && Dia <= 30) ? Dia : 1;
            else
                dia = (Dia > 0 && Dia <= 31) ? Dia : 1;
        }
        //Verificação das demais informações.
        mes = (Mes > 0 && Mes <= 12) ? Mes : 1;
        ano = (Ano > 0  && Ano <= 2022) ? Ano : 1;
        hora = (Hora >= 0 && Hora < 24) ? Hora : 0;
        minuto = (Minuto >= 0 && Minuto < 60) ? Minuto : 0;
        segundo = (Segundo >= 0 && Segundo <60) ? Segundo : 0;
    }    
    //Destrutor.
    DataHorario::~DataHorario(){
        cout << "Chamada do destrutor" << endl;
    }
    //Retorna o dia.
    int DataHorario::getDia() const{
        return this->dia;
    }
    //Retorna o mes.
    int DataHorario::getMes() const{
        return this->mes;
    }
    //Retorna o ano.
    int DataHorario::getAno() const{
        return this->ano;
    }
    //Retrona a hora.
    int DataHorario::getHora() const{
        return this->hora;
    }
    //Retorna o minuto.
    int DataHorario::getMinuto() const{
        return this->minuto;
    }
    //Retorna o segundo.
    int DataHorario::getSegundo() const{
        return this->segundo;
    }
    //Função compare facilita a implementação da sobrecarga de 
    //outros operadores modulando o código comum entre eles. 
    int DataHorario::compare(const DataHorario operando) const{
        if(this->ano != operando.ano){
            return this->ano - operando.ano;
        }
        else if(this->mes != operando.mes){
            return this->mes - operando.mes;
        }
        else if(this->dia != operando.dia){
            return this->dia - operando.dia;
        }
        else if(this->hora != operando.hora){
            return this->hora - operando.hora;
        }
        else if(this->minuto != operando.minuto){
            return this->minuto - operando.minuto;
        }
        else return this->segundo - operando.segundo;
    }
    //Sobrecarga do operador < usando função compare.
    bool DataHorario::operator<(const DataHorario &dataHorario) const {
        return compare(dataHorario) < 0;
    }
    //Sobrecarga do operador == usando função compare.
    bool DataHorario::operator==(const DataHorario &dataHorario) const {
        return compare(dataHorario) == 0;
    }
    //Sobrecarga do operador <= usando operadores < e ==.
    bool DataHorario::operator<=(const DataHorario &dataHorario) const {
        return (*this < dataHorario || *this == dataHorario);
    }
    //Sobrecarga do operador != usando operado ==.
    bool DataHorario::operator!=(const DataHorario &dataHorario) const {
        return !(*this == dataHorario);
    }
    //Sobrecarga do operador > usando operador <=.
    bool DataHorario::operator>(const DataHorario &dataHorario) const {
        return !(*this <= dataHorario);
    }
    //Sobrecarga do operador >= usando operadores > e ==.
    bool DataHorario::operator>=(const DataHorario &dataHorario) const {
        return (*this > dataHorario || *this == dataHorario);
    }
}

