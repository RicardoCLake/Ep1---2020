#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, int ttl, string dado)
{
    this->origem = origem;
    this->destino = destino;
    this->ttl = ttl;
    this->dado = dado;
}

Datagrama::~Datagrama()
{

}


int Datagrama::getOrigem()
{
    return this->origem;
}

int Datagrama::getDestino()
{
    return this->destino;
}

int Datagrama::getTtl()
{
    return this->ttl;
}

string Datagrama::getDado()
{
    return this->dado;
}

void Datagrama::processar()
{
    this->ttl = ttl - 1;
}

bool Datagrama::ativo()
{
    if(ttl <= 0){
        return false;
    }else{
        return true;
    }
}

void Datagrama::imprimir()
{
    cout << "Origem: " << getOrigem() << endl;
    cout << "Destino: " << getDestino() << endl;
    cout << "TTL: " << getTtl() << endl;
    cout << "Dado: " << getDado() << endl;
}
