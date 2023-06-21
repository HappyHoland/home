#include "Database.hpp"

using namespace std;

Database::Database(const string &caminho) {
    m_caminho = caminho;
    carregar_palavras();
    ordem_alfabetica();
    ordem_tamanho_palavra();
}


Database::reference_palavras Database::get_palavras_ordem_alfabetica() {
    return m_palavras_ordem_alfabetica;
}

Database::reference_palavras Database::get_palavras_ordem_tamanho() {
    return m_palavras_ordem_tamanho;
}

void Database::ordem_alfabetica() {
    m_palavras_ordem_alfabetica = m_palavras;
    sort(m_palavras_ordem_alfabetica.begin(), m_palavras_ordem_alfabetica.end(), 
        [](peso_palavra a, peso_palavra b) {
            return a.second < b.second;
        }
    );
}

void Database::ordem_tamanho_palavra() {
    m_palavras_ordem_tamanho = m_palavras;
    sort(m_palavras_ordem_tamanho.begin(), m_palavras_ordem_tamanho.end(), 
        [](peso_palavra a, peso_palavra b) {
            return a.second.size() < b.second.size();
        }
    );
}

bool Database::carregar_palavras() {
    ifstream ifs;

    ifs.open(m_caminho);
    
    if (!ifs.is_open()) {
        return false;
    }

    std::string linha{};
    int peso{0};

    while (getline(ifs, linha)) {
        std::string palavra{};
        auto linha_split = StringUtil::split_str(linha, ' ');
        peso = std::stoi(linha_split[0]); // Considera que o peso antecede a palavra
        palavra += linha_split[1];
        for (int i = 2; i < (int)linha_split.size(); i++)
        {
            palavra += ' ' + linha_split[i];
        }
        std::transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);
        
        m_palavras.push_back({peso, palavra});
    }

    return true;
}