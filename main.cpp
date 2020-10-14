#include <iostream>
#include "Datagrama.h"
#include "Fila.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"
#include "Roteador.h"

using namespace std;

void imprimir_inicio(){
    cout << "Simulador de Rede" << endl;
    cout << "---" << endl;
    cout << "1) Enviar um datagrama" << endl;
    cout << "2) Passar tempo" << endl;
    cout << "3) Sair" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    int opcao = 0;

    imprimir_inicio();


    return 0;
}
