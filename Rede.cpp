#include "Rede.h"

Rede::Rede(Roteador** roteadores, int quantidadeDeRoteadores):
quantidadeDeRoteadores(quantidadeDeRoteadores), roteadores(roteadores) {

}

Roteador* Rede::getRoteador(int endereco) {
    for (int i = 0; i < quantidadeDeRoteadores; i++) {
        if (roteadores[i]->getEndereco() == endereco)
            return roteadores[i];
    }
    return NULL;
}

void Rede::enviar(string texto, Roteador* origem, int destino, int ttl) {
    Datagrama* data = new  Datagrama(origem->getEndereco(), destino, ttl, texto);
    origem->receber(data);
}

void Rede::passarTempo() {
    for (int i = 0; i < quantidadeDeRoteadores; i++) {
        roteadores[i]->processar();
    }
}

void Rede::imprimir() {
}

Rede::~Rede() {
}
