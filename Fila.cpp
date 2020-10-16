#include "Fila.h"

Fila::Fila(int tamanho): tamanho(tamanho) {
    this->cabeca = 0;
    this->calda = 0;
    this->n_elementos = 0;
    vetor = new Datagrama*[tamanho];
}

bool Fila::enqueue(Datagrama* d) {
    if (n_elementos == tamanho) return false;
    else {
        vetor[calda] = d;
        n_elementos ++;
        calda = (calda + 1) % tamanho;
        return true;
    }
}

Datagrama* Fila::dequeue() {
    if (n_elementos == 0) return NULL;
    else {
        n_elementos--;
        int retirar = cabeca;
        cabeca = (cabeca + 1) % tamanho;
        return vetor[retirar];
    }
}

bool Fila::isEmpty() {
    return !(n_elementos);
}

void Fila::imprimir() {
    cout << "Ha " << n_elementos << " datagramas na fila" << endl;
    int j = cabeca;
    for (int i = 0; i < n_elementos; i++) {
        vetor[j]->imprimir();
        j = (j + 1) % tamanho;
    }
}

Fila::~Fila() {
    delete[] vetor;
}
