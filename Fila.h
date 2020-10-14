#ifndef FILA_H
#define FILA_H

#include "Datagrama.h"

class Fila {
    public:
        Fila(int tamanho);
        ~Fila();
        bool enqueue(Datagrama* d);
        Datagrama* dequeue();
        bool isEmpty();
        void imprimir();

    protected:

    private:
        int cabeca;
        int calda;
        int n_elementos;
        int tamanho;
        Datagrama** vetor;
};

#endif // FILA_H
