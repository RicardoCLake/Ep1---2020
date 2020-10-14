#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "TabelaDeRepasse.h"
#include "Fila.h"
#include <iostream>

using namespace std;

#define TAMANHO_FILA 3

class TabelaDeRepasse;

class Roteador {
    public:
        Roteador(int endereco);
        ~Roteador();
        TabelaDeRepasse* getTabela();
        Fila* getFila();
        int getEndereco();
        void receber(Datagrama* d);
        void processar();
        string getUltimoDadoRecebido();
        void imprimir();

    protected:

    private:
        int endereco;
        string ultimoDadoRecebido;
        TabelaDeRepasse* tab;
        Fila* fila;
};

#endif // ROTEADOR_H
