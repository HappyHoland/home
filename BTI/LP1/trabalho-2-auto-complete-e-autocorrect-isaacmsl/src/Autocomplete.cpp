#include "Autocomplete.hpp"

using namespace std;

Autocomplete::Autocomplete(const string &palavra, Database* database) {
    m_palavra = palavra;
    m_database = database;
    palavras_similares();
}


void Autocomplete::set_palavra(const std::string& palavra) {
    m_resultado.clear();
    m_palavra = palavra;
    palavras_similares();
}

// Função auxiliar para ordenar por peso
bool sort_peso(const Database::peso_palavra &a, const Database::peso_palavra &b) {
    return (a.first > b.first);
}

void Autocomplete::palavras_similares() {
    auto qnt_sugestoes{ 0 };
    Database::palavras palavras_aux{};
    auto palavras_ordem_alfabetica = m_database->get_palavras_ordem_alfabetica();
    peso_palavra peso_default_palavra = {-1, m_palavra};

    auto low = lower_bound(
                    palavras_ordem_alfabetica.begin(),
                    palavras_ordem_alfabetica.end(),
                    peso_default_palavra,
                    [](const peso_palavra &other, peso_palavra target){
                        return other.second.substr(0, (int) target.second.size()) < target.second;
                    }
                );

    auto upper = upper_bound(
                    palavras_ordem_alfabetica.begin(),
                    palavras_ordem_alfabetica.end(),
                    peso_default_palavra,
                    [](peso_palavra target, const peso_palavra &other){
                        // Considera apenas substring com tamanho do target na string de other
                        return target.second < other.second.substr(0, target.second.size());
                    }
                );

    while (low < upper) {
        palavras_aux.push_back(*low);
        ++low;
    }
    
    // Ordena resultado final por peso
    sort(
        palavras_aux.begin(),
        palavras_aux.end(),
        sort_peso
    );

    for (auto it = palavras_aux.begin(); it < palavras_aux.end() && qnt_sugestoes < 4; it++) {
        m_resultado.push_back((*it).second);
        qnt_sugestoes++;
    }
}

Autocomplete::reference_palavras Autocomplete::resultado() {
    return m_resultado;
}