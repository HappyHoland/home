#include <vector>
#include <string>
#include <algorithm>
#include "Database.hpp"
#include "leveshtein.hpp"
#include "Autocorrect.hpp"
#include <iostream>

using namespace std;

/**
 * @brief Construct a new Autocorrect object
 * 
 * @param palavra a palavra a ser comparada
 * @param dados a versao ordenada dos dados recebidos do arquivo
 */
Autocorrect::Autocorrect(string palavra, Database* database, int num){
    m_palavra = palavra;
    m_database = database;
    m_num_result = num;
}

/**
 * @brief Set the palavra object
 * 
 * @param palavra 
 */
void Autocorrect::set_palavra(string palavra){
    m_resultado.clear();
    m_palavra = palavra;
}

/**
 * @brief getter do resultado
 * 
 * @return vector<string>& 
 */
vector<string>& Autocorrect::get_resultado(){
    
    if (m_palavra.size() < 3) {
        return m_resultado;
    }

    vector <pair <int, string>> aux;
    vector <pair <int, string>>& ordenada = m_database->get_palavras_ordem_tamanho();
    vector <pair <pair <int, string>, int>> aux_edit_dist;
    int count = 0;

    auto low = lower_bound(ordenada.begin(), ordenada.end(), m_palavra, [](const pair<int, string>& other, string target){
        return  other.second.size() < target.size();});

    auto upp = upper_bound(ordenada.begin(), ordenada.end(), m_palavra, [](string other, pair<int, string> target){
        return other.size() + 1 < target.second.size();});

    for (; low < upp; low++) {
        aux.push_back(*low);
    }

    auto it = aux.begin();

    for (; it < aux.end(); it++) {
        aux_edit_dist.push_back(make_pair(*it, edit_dist((*it).second, m_palavra)));
    }

    sort(aux_edit_dist.begin(), aux_edit_dist.end(), [](pair <pair <int, string>, int> a, pair <pair <int, string>, int> b){
        return a.second < b.second || (a.second == b.second && a.first.first > b.first.first);
    });

    for (auto it = aux_edit_dist.begin(); it < aux_edit_dist.end() && count < 4; it++) {
        m_resultado.push_back((*it).first.second);
        count++;
    }

    return m_resultado;
}   