#include "DataHorario.h"

namespace poo {
    ostream &operator<<(ostream &output, const DataHorario &dataHorario) {  
        output << dataHorario.dia << " de " << dataHorario.mes << " de " << dataHorario.ano << " - " << dataHorario.hora 
        << "horas, " << dataHorario.minuto << "minutos, " << dataHorario.segundo << "segundos." << endl;
        return output;
    }

    DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) :
    dia(dia), mes(mes), ano(ano), hora(hora), minuto(minuto), segundo(segundo) {
    }    

    DataHorario::~DataHorario(){
        cout << "Chamada do destrutor" << endl;
    }

    int DataHorario::getDia() const{
        return this->dia;
    }

    int DataHorario::getMes() const{
        return this->mes;
    }

    int DataHorario::getAno() const{
        return this->ano;
    }

    int DataHorario::getHora() const{
        return this->hora;
    }

    int DataHorario::getMinuto() const{
        return this->minuto;
    }

    int DataHorario::getSegundo() const{
        return this->segundo;
    }

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

    bool DataHorario::operator<(const DataHorario &dataHorario) const {
        return compare(dataHorario) < 0;
    }

    bool DataHorario::operator==(const DataHorario &dataHorario) const {
        return compare(dataHorario) == 0;
    }

    bool DataHorario::operator<=(const DataHorario &dataHorario) const {
        return (*this < dataHorario || *this == dataHorario);
    }

    bool DataHorario::operator!=(const DataHorario &dataHorario) const {
        return !(*this == dataHorario);
    }

    bool DataHorario::operator>(const DataHorario &dataHorario) const {
        return !(*this <= dataHorario);
    }

    bool DataHorario::operator>=(const DataHorario &dataHorario) const {
        return (*this > dataHorario || *this == dataHorario);
    }
}

