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
    //************************************DECLARACOES INICIAIS**********************************
    int opcao = 0;
    int end_origem, end_destino, ttl;
    string mensagem;

    Roteador** roteadores = new Roteador*[6]; //Vetor de roteadores
    Roteador* r1 = (roteadores[0] = new Roteador(1));
    Roteador* r2 = (roteadores[1] = new Roteador(2));
    Roteador* r3 = (roteadores[2] = new Roteador(3));
    Roteador* r4 = (roteadores[3] = new Roteador(4));
    Roteador* r5 = (roteadores[4] = new Roteador(5));
    Roteador* r6 = (roteadores[5] = new Roteador(6));


    Rede* rede = new Rede(roteadores, 6);

    r1->getTabela()->setPadrao(r2);
    r2->getTabela()->setPadrao(r5);
    r3->getTabela()->setPadrao(r2);
    r4->getTabela()->setPadrao(r5);
    r5->getTabela()->setPadrao(r2);
    r6->getTabela()->setPadrao(r5);

    r1->getTabela()->mapear(4, r4);
    r2->getTabela()->mapear(1, r1);
    r2->getTabela()->mapear(3, r3);
    r3->getTabela()->mapear(6, r6);
    r4->getTabela()->mapear(1, r1);
    r5->getTabela()->mapear(4, r4);
    r5->getTabela()->mapear(6, r6);
    r6->getTabela()->mapear(3, r3);

    //************************************ INTERFACE COM O USUARIO E OPCOES**********************************


    while(opcao != 3){
        if(opcao == 0){
            imprimir_inicio();
            cin >> opcao;
            cout << endl;
        }

        if(opcao == 1){
            cout << "Endereco do roteador de origem: ";
            cin >> end_origem;
            cout << "Endereco de destino: ";
            cin >> end_destino;
            cout << "TTL: ";
            cin >> ttl;
            cout << "Mensagem: ";
            cin >> mensagem;
            cout << endl;

            int endereco_roteador_origem;

            bool tem_end_origem = false;
            for(int i = 0; i < 6; i++){
                if(end_origem == roteadores[i]->getEndereco()){
                    tem_end_origem = true;
                    endereco_roteador_origem = i;
                }
            }
            if(tem_end_origem){
                rede->enviar(mensagem, roteadores[endereco_roteador_origem], end_destino, ttl);
                opcao = 0;
            }else{
                cout << "Erro: origem desconhecida" << endl;
                opcao = 0;
            }

        }else if(opcao == 2){
            int tempo;

            cout << "Quantidade de tempo: ";
            cin >> tempo;

            for(int i = 0; i < tempo; i++){
                cout << endl;
                cout << "Instante " << i+1 << endl;
                cout << "---" << endl;
                rede->passarTempo();
                cout << endl;
            }

            opcao = 0;
        }
    }

    return 0;
}
