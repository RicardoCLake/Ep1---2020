#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "TabelaDeRepasse.h"
#include "Fila.h"
#include <string>
#include <iostream>

using namespace std;

#define TAMANHO_FILA 3

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
        Datagrama* d;
        TabelaDeRepasse* tab = new TabelaDeRepasse();
        Fila* fila = new Fila(TAMANHO_FILA);
};

#endif // ROTEADOR_H
