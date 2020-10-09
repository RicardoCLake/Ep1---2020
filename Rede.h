#ifndef REDE_H
#define REDE_H


class Rede
{
    public:
        Rede(Roteador** roteadores, int quantidadeDeRoteadores);
        ~Rede();
        Roteador* getRoteador(int endereco);
        void enviar(string texto, Roteador* origem, int destino, int ttl);
        void passarTempo();
        void imprimir();

    protected:

    private:
};

#endif // REDE_H
