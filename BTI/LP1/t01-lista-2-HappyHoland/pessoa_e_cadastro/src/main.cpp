#include <iostream>
#include <fstream>
#include <vector>
#include "Pessoa.hpp"
#include "Cadastro.hpp"

using namespace std;

int main(){
    setlocale(LC_ALL, "portuguese");
    Cadastro CadastroUnico("Cadastro único");
    Cadastro sus("Sistema único de Saúde"), ce("Cadastro Estadual"), cm("Cadastro Municipal");
    fstream lista ("../data/CadastroUnico.txt");
    string nome, cpf, end, cadastro;
    Pessoa * aux;

    if (lista.is_open()) {
        while (getline(lista, nome)) {
            getline(lista, cpf);
            getline(lista, end);

            aux = new Pessoa(nome, cpf);
            aux->setEndereco(end);

            CadastroUnico.adicionaPessoa(aux);
            aux = nullptr;
        }

        lista.close();
    }

    while (getline(cin,cpf, ' ')){
        getline(cin, cadastro, '\n');

        if (cadastro == "SUS") {
            aux = CadastroUnico.encontraPessoa(cpf);
            if (aux != nullptr) 
                sus.adicionaPessoa(aux);

        } else if (cadastro == "CE") {
            aux = CadastroUnico.encontraPessoa(cpf);
            if (aux != nullptr) 
                ce.adicionaPessoa(aux);

        } else {
            aux = CadastroUnico.encontraPessoa(cpf);
            if (aux != nullptr) 
                cm.adicionaPessoa(aux);

        }

        aux = nullptr;
    }

    sus.printCadastro();
    sus.limpaCadastro(false);

    cout << endl;
    
    ce.printCadastro();
    ce.limpaCadastro(false);
    
    cout << endl;
    
    cm.printCadastro();
    cm.limpaCadastro(false);

    CadastroUnico.limpaCadastro(true);

    return EXIT_SUCCESS;
}