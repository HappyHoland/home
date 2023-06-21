#include <iostream>
#include <string>
#include "Casa.hpp"
#include "misc.hpp"
#include "rua.hpp"

using namespace std;

int main(){
    string nome, cep, lado, area1, area2, ocupada;
    Casa *aux;
    vector<Casa*> desocupadas, aux_del;
    tuple<Casa*, Casa*, Casa*> vizinhos;

    getline(cin, nome);
    getline(cin, cep);

    rua rua(nome, cep);

    while (getline(cin, lado)) {
        getline(cin, area1, ' ');
        getline(cin, area2);
        getline(cin, ocupada);

        aux = new Casa(stod(area1), stod(area2));
        aux_del.push_back(aux);
        
        if (ocupada[0] == 'o') {
            aux->setOcupada(true);
        }

        if (lado[0] == 'A') {
            rua.adiciona_casa(aux, rua::LADO_A);
        } else {
            rua.adiciona_casa(aux, rua::LADO_B);
        }
    }
    
    cout << "Casas Desocupadas" << endl;
    
    desocupadas = rua.get_desocupadas();

    if (desocupadas.size() == 0) {
        cout << "<nenhuma>" << endl;

    } else {
        for (long unsigned int i = 0; i < desocupadas.size(); i++) {
            int num = desocupadas[i]->getNumero();
            Casa *viz[3];
            
            cout << rua.endereco(num) << endl;

            cout << "Vizinhos" << endl;

            vizinhos = rua.vizinhos(num);

            viz[0] = get<0>(vizinhos);
            viz[1] = get<1>(vizinhos);
            viz[2] = get<2>(vizinhos);


            for (int i = 0; i < 3; i++) {
                switch (i)
                {
                case 0:
                    cout << "Frente: ";
                    break;
                
                case 1:
                    cout << "Esquerda: ";
                    break;

                case 2:
                    cout << "Direita: ";
                    break;
                }

                if (viz[i] != nullptr) {
                    cout << rua.endereco(viz[i]->getNumero());

                    if (viz[i]->isOcupada()) cout << " (ocupada)" << endl;
                    else cout << " (desocupada)" << endl;

                } else cout << "<nenhum>" << endl;
            }
        }

        desocupadas.clear();
        rua.clear_rua();
    }

    for (unsigned int i = 0; i < aux_del.size(); i++) {
        delete(aux_del[i]);
    }

    aux_del.clear();


    return EXIT_SUCCESS;
}