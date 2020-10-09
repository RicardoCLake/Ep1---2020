#ifndef FILA_H
#define FILA_H


class Fila
{
    public:
        Fila(int tamanho);
        ~Fila();
        bool enqueue(Datagrama* d);
        Datagrama* dequeue();
        bool isEmpty();
        void imprimir();

    protected:

    private:
};

#endif // FILA_H
