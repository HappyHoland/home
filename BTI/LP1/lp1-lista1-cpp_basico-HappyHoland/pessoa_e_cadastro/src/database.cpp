#include "database.hpp"
#include <algorithm>

Pessoa* criar_pessoa(std::string nome, std::string cpf, std::string endereco) {
    Pessoa *new_pessoa = new Pessoa;

    new_pessoa->nome = nome;
    new_pessoa->cpf = cpf;
    new_pessoa->endereco = endereco;

    return new_pessoa;
}

Pessoa* procurar_cpf(const std::vector<Pessoa*> &base, const std::string cpf) {
    std::vector<Pessoa*>::const_iterator it;

    for (it = base.begin(); it != base.end(); it++) {
        if ((*it)->cpf == cpf) {
            return *it;
        }
    }

    return nullptr;
}

bool inserir_pessoa(std::vector<Pessoa*> &base, Pessoa* p) {
    std::vector<Pessoa*>::iterator it;

    for (it = base.begin(); it != base.end(); it++) {
        if ((*it)->cpf == p->cpf) {
            return false;
        }
    }

    base.push_back(p);

    return true;
}

std::vector<Pessoa*> procurar_nome(const std::vector<Pessoa*> &base, std::string nome) {
    std::vector<Pessoa*>::const_iterator it;
    std::vector<Pessoa*> match;

    for (it = base.begin(); it != base.end(); it++) {
        if ((*it)->nome == nome) {
            match.push_back(*it);
        }
    }

    return match;
}

Pessoa* remover_pessoa(std::vector<Pessoa*> &base, std::string cpf) {
    std::vector<Pessoa*>::iterator it;
    Pessoa * aux;

    for (it = base.begin(); it != base.end(); it++) {
        if((*it)->cpf == cpf) {
            aux = *it;
            base.erase(it);
            
            return aux;
        }
    }

    return nullptr;
}