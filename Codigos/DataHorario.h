#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <iostream>

using namespace std;

namespace poo {
    class DataHorario {
        friend ostream &operator<<(ostream &output, const DataHorario &dataHorario);
    public:
        DataHorario(int Dia, int Mes, int Ano, int Hora, int Minuto, int Segundo);
        ~DataHorario();

        int getDia() const;
        int getMes() const;
        int getAno() const;
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        bool operator<(const DataHorario &dataHorario) const; 
        bool operator==(const DataHorario &dataHorario) const; 
        bool operator<=(const DataHorario &dataHorario) const; 
        bool operator!=(const DataHorario &dataHorario) const; 
        bool operator>(const DataHorario &dataHorario) const; 
        bool operator>=(const DataHorario &dataHorario) const; 
    private:
        int dia, mes, ano, hora, minuto, segundo;
        int compare(const DataHorario operando) const;
    };
}

#endif
