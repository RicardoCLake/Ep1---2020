#ifndef ROTEADOR_H
#define ROTEADOR_H

#include "TabelaDeRepasse.h"
#include "Fila.h"

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
};

#endif // ROTEADOR_H
