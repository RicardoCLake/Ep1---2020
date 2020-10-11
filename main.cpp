#include <iostream>
#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"
#include "Roteador.h"



using namespace std;

int main() {
    Datagrama* d1 = new Datagrama(1, 7, 5, "primeiro");
    Datagrama* d2 = new Datagrama(2, 7, 5, "segundo");
    Datagrama* d3 = new Datagrama(3, 7, 5, "terceiro");
    Datagrama* d4 = new Datagrama(4, 7, 5, "quarto");
    Datagrama* d5 = new Datagrama(5, 7, 5, "quinto");
    Datagrama* d6 = new Datagrama(6, 7, 5, "sexto");
    Fila* fila = new Fila(4);

    if(fila->dequeue() != NULL) cout <<"tirei" << endl;
    else cout << "nao tirei" << endl;

    if (fila->enqueue(d1)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    if(fila->dequeue() != NULL) cout <<"tirei" << endl;
    else cout << "nao tirei" << endl;

    if(fila->dequeue() != NULL) cout <<"tirei" << endl;
    else cout << "nao tirei" << endl;

    if (fila->enqueue(d2)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    if (fila->enqueue(d3)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    if (fila->enqueue(d4)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    if (fila->enqueue(d5)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    if (fila->enqueue(d6)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    if(fila->dequeue() != NULL) cout <<"tirei" << endl;
    else cout << "nao tirei" << endl;

    if (fila->enqueue(d1)) cout <<"coloquei" << endl;
    else cout << "nao coloquei" << endl;

    fila->imprimir();

    delete d2;
    delete d1;
    delete d3;
    delete d6;
    delete d4;
    delete d5;

}
