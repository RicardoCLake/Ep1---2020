#include "Roteador.h"

Roteador::Roteador(int endereco) : endereco (endereco) {
    tab = new TabelaDeRepasse();
    fila = new Fila(TAMANHO_FILA);
    ultimoDadoRecebido = "";

}

TabelaDeRepasse* Roteador::getTabela() {
    return this->tab;
}

Fila* Roteador::getFila() {
    return this->fila;
}

int Roteador::getEndereco() {
    return this->endereco;
}

void Roteador::receber(Datagrama* d) {
    if (this->fila->enqueue(d) == false)
        cout << "\tFila em " << this->getEndereco() << " estourou" << endl;
}

void Roteador::processar() {
    Datagrama* dd = this->fila->dequeue();

    if (dd != NULL) {
        if (dd->getTtl() <= 0) {
            delete dd;
        } else if (dd->getDestino() == this->endereco) {
            this->ultimoDadoRecebido = dd->getDado();
            delete dd;
        } else if (tab->getDestino(dd->getDestino()) != NULL) {
            tab->getDestino(dd->getDestino())->receber(dd);
        } else
            delete dd;
    }
}

string Roteador::getUltimoDadoRecebido() {
    return ultimoDadoRecebido;
}

void Roteador::imprimir() {
    cout << "Ultimo dado recebido foi: " << getUltimoDadoRecebido() << endl;
    this->tab->imprimir();
    this->fila->imprimir();
}

Roteador::~Roteador() {
    delete tab;
    delete fila;
}
