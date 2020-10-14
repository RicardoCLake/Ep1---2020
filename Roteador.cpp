#include "Roteador.h"

Roteador::Roteador(int endereco) : endereco (endereco) {
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
    if(this->fila->enqueue(d) == false)
        cout << "\tFila em " << getEndereco() << " estourou" << endl;
    else
    {
        this->fila->enqueue(d);
    }   
}

void Roteador::processar() {
    Datagrama* dd = this->fila->dequeue();
    
    if(dd == NULL)
    {
        break;
    }
    else
    {
        if(dd->getTtl() <= 0)
        {
            delete dd;    
        }else if (dd->getDestino() == this->endereco)
        {
            this->getUltimoDadoRecebido();
            delete dd;
        }else
        {
            
        }
        
    }
    
}

string Roteador::getUltimoDadoRecebido() {
    
}

void Roteador::imprimir() {

}

Roteador::~Roteador() {
    delete tab;
    delete fila;
    //dtor
}
