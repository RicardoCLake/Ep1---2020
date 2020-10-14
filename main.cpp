#include <iostream>
#include <string>
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

    int end_origem, end_destino, ttl;
    string mensagem;

    Datagrama* d1 = new Datagrama()

    Roteador** roteadores = new Roteador*[6];

    Roteador* r1 = (roteadores[0] = new Roteador(1));
    Roteador* r2 = (roteadores[1] = new Roteador(2));
    Roteador* r3 = (roteadores[2] = new Roteador(3));
    Roteador* r4 = (roteadores[3] = new Roteador(4));
    Roteador* r5 = (roteadores[4] = new Roteador(5));
    Roteador* r6 = (roteadores[5] = new Roteador(6));

    TabelaDeRepasse* tab = new TabelaDeRepasse();

    Rede* rede = new Rede(roteadores, 6);

    while(opcao != 3 || opcao == 0){
        if(opcao == 0){
            imprimir_inicio();
            cin >> opcao;
            cout << endl;
        }
        
        if(opcao == 1){
            cout << "Endereco do roteador de origem: ";
            cin >> end_origem;
            cout << "\nEndereco de destino: ";
            cin >> end_destino;
            cout << "\nTTL: ";
            cin >> ttl;
            cout << "\nMensagem: ";
            cin >> mensagem;
            cout << endl;

            bool tem_end_origem = false;
            for(int i = 0; i < 6; i++){
                if(end_origem == roteadores[i]){
                    tem_end_origem = true;
                    break;
                }
            }

            if(tem_end_origem){
                rede->enviar(mensagem, end_origem, end_destino, ttl);
                opcao = 0;
                break;
            }else{
                cout << "Erro: origem desconhecida" << endl;
                opcao = 0;
                break;
            }
        }else if(opcao == 2){
            int tempo;

            cout << "Quantidade de tempo: ";
            cin >> tempo;


        }
    }

    return 0;
}