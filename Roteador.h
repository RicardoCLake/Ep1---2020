#ifndef ROTEADOR_H
#define ROTEADOR_H

#define TAMANHO_FILA 3

class Roteador
{
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
