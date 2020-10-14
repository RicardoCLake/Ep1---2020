#include "Datagrama.h"


Datagrama::Datagrama(int origem, int destino, int ttl, string dado):
origem (origem), destino (destino), ttl (ttl), dado (dado) {
}

Datagrama::~Datagrama() {

}


int Datagrama::getOrigem() {
    return this->origem;
}

int Datagrama::getDestino() {
    return this->destino;
}

int Datagrama::getTtl() {
    return this->ttl;
}

string Datagrama::getDado() {
    return this->dado;
}

void Datagrama::processar() {
    this->ttl -= 1;
}

bool Datagrama::ativo() {
    if (ttl > 0) return true;
    else return false;
}

void Datagrama::imprimir() {
    cout << "De: " << getOrigem() << " - Para: " << getDestino() << endl;
    cout << "TTL: " << getTtl() << " vezes" << endl;
    cout << "Dado: " << getDado() << endl;
}
