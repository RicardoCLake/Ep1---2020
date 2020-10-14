#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "Roteador.h"
#define MAXIMO_TABELA 5

class Roteador;

class TabelaDeRepasse {
    public:
        TabelaDeRepasse();
        ~TabelaDeRepasse();
        bool mapear(int endereco, Roteador* adjacente);
        Roteador** getAdjacentes();
        int getQuantidadeDeAdjacentes();
        void setPadrao(Roteador* padrao);
        Roteador* getDestino(int endereco);
        void imprimir();

    protected:

    private:
        int n_enderecos;
        Roteador* padrao;
        int* enderecos;
        Roteador** adjacentes;
};

#endif // TABELADEREPASSE_H
