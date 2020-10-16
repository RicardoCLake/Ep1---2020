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
    Datagrama* dat = this->fila->dequeue();

    if (dat != NULL) {
        dat->processar();
        Roteador* rot = tab->getDestino(dat->getDestino());

        cout << "Roteador " << this->endereco << endl;

        if (dat->getTtl() <= 0) {
            cout << "\tDestruido por TTL: Origem: " << dat->getOrigem()
                << ", Destino: " << dat->getDestino() << ", TTL: " << dat->getTtl()
                << ", " << dat->getDado() << endl;
            delete dat;
        } else if (dat->getDestino() == this->endereco) {
            cout << "\tRecebido: " << dat->getDado() << endl;

            this->ultimoDadoRecebido = dat->getDado();
            delete dat;
        } else if (rot != NULL) {
            cout << "\tEnviado para " << rot->getEndereco() << " " <<
                "Origem: " << dat->getOrigem()
                << ", Destino: " << dat->getDestino() << ", TTL: " << dat->getTtl()
                << ", " << dat->getDado() << endl;

            rot->receber(dat);
        } else
            delete dat;
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
