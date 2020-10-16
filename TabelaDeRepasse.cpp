#include "TabelaDeRepasse.h"

TabelaDeRepasse::TabelaDeRepasse() {
    this->enderecos = new int[MAXIMO_TABELA];
    this->adjacentes =  new Roteador*[MAXIMO_TABELA];
    this->n_enderecos = 0;
    this->padrao = NULL;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente) {
    if (n_enderecos == MAXIMO_TABELA)
        return false;
    for (int i = 0; i < n_enderecos; i++) {
        if (endereco == enderecos[i]) {
            adjacentes[i] = adjacente;
            return true;
        }
    }
    enderecos[n_enderecos] = endereco;
    adjacentes[n_enderecos] = adjacente;
    n_enderecos++;
    return true;
}

Roteador** TabelaDeRepasse::getAdjacentes() {
    return this->adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes() {
    return this->n_enderecos;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao) {
    this->padrao = padrao;
}

Roteador* TabelaDeRepasse::getDestino(int endereco) {
    for (int i = 0; i < n_enderecos; i++) {
        if (enderecos[i] == endereco) {
            return adjacentes[i];
        }
    }
    return padrao;
}

void TabelaDeRepasse::imprimir() {
    cout << "Ha " << n_enderecos << " enderecos" << endl;
    for (int i = 0; i < n_enderecos; i++) {
        cout << "Endereco: " << enderecos[i] << " - Roteador: ";
        adjacentes[i]->imprimir();
    }
}

TabelaDeRepasse::~TabelaDeRepasse() {
    delete[] adjacentes;
    delete[] enderecos;
}
