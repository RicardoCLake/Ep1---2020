#include "Fila.h"

Fila::Fila(int tamanho):
tamanho(tamanho) {
    this->cabeca = 0;
    this->calda = 0;
    this->n_elementos = 0;
    vetor = new Roteador*[tamanho];
}

bool Fila::enqueue(Datagrama* d) {

}

Datagrama* Fila::dequeue() {

}

bool Fila::isEmpty() {

}

void Fila::imprimir() {

}

Fila::~Fila() {
    //dtor
}
