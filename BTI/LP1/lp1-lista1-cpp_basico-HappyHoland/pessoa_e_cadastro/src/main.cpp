#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "database.hpp"

using namespace std;

int main(){
    
    ifstream database;
    database.open("C:/Users/lucas/Documents/Tecnologia e Informacao/2022.1/LP1/lp1-lista1-cpp_basico-HappyHoland/pessoa_e_cadastro/data/CadastroUnico.txt");
    string nome, cpf, endereco;
    string line;

    if (database.good()) {
        while (getline(database, nome,'\n')) {
            getline(database, cpf, '\n');
            getline(database, endereco, '\n');

            base.push_back(criar_pessoa(nome, cpf, endereco));
        }
    }

    while (getline(cin, line, '\n')) {
        if (line == "procurar_cpf") {
            getline(cin, cpf, '\n');

            Pessoa * aux = procurar_cpf(base, cpf);

            if (aux != nullptr) {
                cout << "encontrada!" << endl;
                cout << aux->cpf << endl;
                cout << aux->endereco << endl;
                cout << aux->nome << endl;
            
            } else {
                cout << "Pessoa com cpf " << cpf << " não encontrada!" << endl;
            
            }      
        } else if (line == "inserir_pessoa") {
            getline(cin, cpf, '\n');
            getline(cin, endereco, '\n');
            getline(cin, nome, '\n');

            Pessoa * aux = criar_pessoa(nome, cpf, endereco);

            if (inserir_pessoa(base, aux)) {
                cout << "cpf " << cpf << " inserido!" << endl;

            } else {
                cout << "cpf " << cpf << " já existe no banco!" << endl;

                delete aux;
            }

            aux = nullptr;

        } else if (line == "remover_pessoa") {
            getline(cin, cpf);

            Pessoa * aux = remover_pessoa(base, cpf);

            if (aux != nullptr) {
                cout << "Pessoa " << aux->nome << " removida!" << endl;

                delete aux;
            } else {
                cout << "Pessoa com cpf " << aux->cpf << " não encontrada!" << endl;
            }

        } else if (line == "procurar_nome") {
            getline(cin, nome, '\n');

            vector<Pessoa*> v_aux = procurar_nome(base, nome);
            auto it = v_aux.begin();

            cout << "Pessoas:" << endl;
            
            if (v_aux.begin() != v_aux.end()) {    
                for (; it != v_aux.end(); it++) {
                    cout << (*it)->nome <<", cpf: " << (*it)->cpf << endl;
                }

                v_aux.clear();
            } else {
                cout << "Nenhuma" << endl;
            }
        } else {break;}
    }

    auto it = base.begin();

    for (; it != base.end(); it++) {
        delete *it;
    }
    
    return EXIT_SUCCESS;
}