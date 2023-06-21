#include "BingoRand.hpp"
#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    BingoRand sorteio;
    string line;
    unsigned long seed;
    unsigned int num_jogadores;
    vector <Jogador*> jogadores;
    vector <string> ganhadores;
    vector <int> nums_sorteados;
    Jogador *aux;
    int num;

    cin >> seed;

    sorteio.setSeed(seed);

    cin >> num_jogadores;
    getline(cin, line);

    for (int i = 0; i < num_jogadores; i++) {
        getline(cin, line);

        aux = new Jogador(line, &sorteio);

        cout << "Jogador " << aux->getNome() << endl;
        cout << "Cartela: " << aux->stringCartela() << endl;

        jogadores.push_back(aux);
    }

    while (ganhadores.size() == 0) {
        num = sorteio.rand();

        while (find(nums_sorteados.begin(), nums_sorteados.end(), num) != nums_sorteados.end()) {
            num = sorteio.rand();
        }

        cout << "Bola sorteada foi: " << num << endl;

        nums_sorteados.push_back(num);

        auto it = jogadores.begin();

        for (; it < jogadores.end(); it++) {
            if ((*it)->searchCartela(num)) {
                if ((*it)->getAcertos() == 24) {
                    std::cout << "Jogador: " << (*it)->getNome() << " Bingo!!" << std::endl;

                    ganhadores.push_back((*it)->getNome());

                } else {

                  std::cout << "Jogador: " << (*it)->getNome() << " marcou!" << std::endl;
                }
            }
        }
    }

    cout << "Foram sorteados " << nums_sorteados.size() << " números:" << endl;

    for (int i = 0; i < nums_sorteados.size(); i++) {
        cout << nums_sorteados[i];
        
        if (i < nums_sorteados.size() - 1) {
            cout << ", ";
        } else {
            cout << endl;
        }
    }

    cout << "Vencedores" << endl;

    for (int i = 0; i < ganhadores.size(); i++) {
        cout << ganhadores[i] << endl;
    }

    return 0;
}