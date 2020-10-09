#ifndef DATAGRAMA_H
#define DATAGRAMA_H


class Datagrama
{
    public:

        Datagrama(int origem, int destino, int ttl, string dado);
        ~Datagrama();
        int getOrigem();
        int getDestino();
        int getTtl();
        string getDado();
        void processar();
        bool ativo();
        void imprimir();

    protected:

    private:
};

#endif // DATAGRAMA_H
