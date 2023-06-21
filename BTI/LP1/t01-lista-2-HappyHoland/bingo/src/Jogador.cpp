#include "Jogador.hpp"
#include "BingoRand.hpp"
#include <vector>
#include <algorithm>
#include <sstream>

Jogador::Jogador(std::string nome, BingoRand *Brnd){
    m_nome = nome;
    m_acertos = 0;
    m_cartela = Brnd->getNDifferent(1, 99, 24);
}

std::string Jogador::getNome(){
    return m_nome;
}

unsigned int Jogador::getAcertos(){
    return m_acertos;
}

bool Jogador::searchCartela(int num){
    auto it = std::find(m_cartela.begin(), m_cartela.end(), num);

    if (it != m_cartela.end()) {
        m_cartela.erase(it);
        m_acertos++;

        return true;

    } else {
        return false;

    }

    return false;
}

std::string Jogador::stringCartela() {
    std::ostringstream sstream;
    auto it = m_cartela.begin();

    sstream << "[";

    for (; it < m_cartela.end(); it++) {
        if (it < m_cartela.end()-1) {
            sstream << *it << ", ";
        } else {
            sstream << *it << "]";
        }
    }

    return sstream.str();
}