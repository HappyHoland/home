#include "rua.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "misc.hpp"

/**
 * Construtor com o nome e cep da rua
 * @param nome o nome da rua
 * @param cep o cep atribuido à rua
 **/
rua::rua(std::string nome, std::string cep){
    m_nome = nome;
    m_CEP = cep;
}

/**
 * Adiciona uma casa no vetor de casas do lado A ou lado B, da rua dependendo do valor de l. 
 * O número da casa deve ser modificado conforme sua posição no vetor A ou B, casas do lado A só tem numeros pares, 
 * começando em 0, as do lado B, começando em 1 números ímpares. Se o valor de l não for A ou B este comando não tem efeito.
 * @param c uma referencia para a casa a ser adicionada, veja que o número da casa será modificado.
 * @param l o lado da rua em que a casa deve ser adicionada, pode ser LADO_A ou LADO_B.
 **/
void rua::adiciona_casa(Casa *c, lado_rua l) {
    switch (l) {
        case LADO_A:
            m_lado_a.push_back(c);
            c->setNumero((m_lado_a.size() - 1)*2);
            break;

        case LADO_B:
            m_lado_b.push_back(c);
            c->setNumero((m_lado_b.size() - 1)*2 + 1);
            break;
    }
}

/**
 * Retorna um par contendo os visinhos de uma casa da rua. 
 * Uma casa é considerada vizinha da ESQUERDA se ela é anterior à casa c no vetor em que c está adicionada, outra casa
 * pode ser considerada vizinha da DIREITA, se ela é posterior à c.
 * Uma casa tem um terceiro vizinho que é a casa que fica à FRENTE dela no vetor que representa as casas
 * do lado oposto à rua, ex: se c estiver do lado A, o visinho da frente está no lado B e tem índice
 * igual ao de c no vetor oposto; 
 * Se a casa em questão não tiver qualquer um dos vizinhos, a casa correspondente na tupla retornada tem valor nullptr.
 * @param c a casa que este método deve usar para procurar os vizinhos
 * @return uma tupla contendo referencias para dos vizinhos à frente, da esquerda e da direita de c.
 **/
std::tuple<Casa*, Casa*, Casa*> rua::vizinhos(Casa *c) {
    Casa *left = nullptr, *right = nullptr, *front = nullptr;
    int ia = casa_in_vec(m_lado_a, c);
    int ib = casa_in_vec(m_lado_b, c);
    int a_size = m_lado_a.size(), b_size = m_lado_b.size();
    
    if (ia >= 0) {
        if (ia > 0) {
            left = m_lado_a[ia-1];
        }

        if (ia < a_size - 1) {
            right = m_lado_a[ia+1];
        }

        if (ia <= b_size - 1) {
            front = m_lado_b[ia];
        }

    } else if (ib >= 0) {
        if (ib > 0) {
            left = m_lado_b[ib-1];
        }

        if (ib < b_size - 1) {
            right = m_lado_b[ib+1];
        }

        if (ib <= a_size - 1) {
            front = m_lado_a[ib];
        }
    }

    return std::make_tuple(front, left, right);
}

/**
 * Retorna uma tupla contendo as casas que são vizinhas à casa com o número fornecido.
 * Os termos de vizinhança são os mesmos do método anterior.
 * @param num o número da casa cuja qual se deseja encontrar os vizinhos
 * @return uma tupla contendo referencias para os vizinhos da casa fornecida, se houverem.
 **/
std::tuple<Casa*, Casa*, Casa*> rua::vizinhos(int num){
    Casa *left = nullptr, *right = nullptr, *front = nullptr;
    int n = num%2, ia, ib, a_size = m_lado_a.size(), b_size = m_lado_b.size();

    switch (n) {
        case 0:
            ia = casa_in_vec(m_lado_a, num);

            if (ia >= 0) {
                if (ia > 0) {
                    left = m_lado_a[ia-1];
                }
                
                if (ia < a_size - 1) {
                    right = m_lado_a[ia+1];
                }

                if (ia <= b_size - 1) {
                    front = m_lado_b[ia];
                }
            }
            break;

        case 1:
            ib = casa_in_vec(m_lado_b, num);

            if (ib >= 0) {
                if (ib > 0) {
                    left = m_lado_b[ib-1];
                }
                
                if (ib < b_size - 1) {
                    right = m_lado_b[ib+1];
                }

                if (ib <= a_size - 1) {
                    front = m_lado_a[ib];
                }
            }

            break;
    }

    return std::make_tuple(front, left, right);
}

/**
 * Retorna o endereço da casa com número passado. 
 * O endereço é formatado segundo o formato: <nome_rua>, Cep: <cep>; Casa No. <numero>, Área: <const> / <tot> m2; Lado <lado>.
 * ex:  Rua Osvaldo Montenegro, Cep: 59-513-491; Casa No. 3, Área: 250.20 / 300 m2; Lado B
 * Esta função retorna uma string vazia se o número procurado não pertencer a nenhuma casa da rua.
 * @param numero o número de alguma casa da rua
 * @return o endereço no formato:<nome_rua>, Cep: <cep>; Casa No. <numero>, Área: <const> / <tot> m2; Lado <lado>.
 **/
std::string rua::endereco(int numero) {
    int ia = casa_in_vec(m_lado_a, numero), ib = casa_in_vec(m_lado_b, numero);
    std::string endereco;

    if (ia >= 0) {
        endereco = m_nome + ", " + m_CEP + ", Casa no. " + std::to_string(m_lado_a[ia]->getNumero()) + ", " + m_lado_a[ia]->toString() + ", lado A";   
    } else if (ib >= 0) {
        endereco = m_nome + ", " + m_CEP + ", Casa no. " + std::to_string(m_lado_b[ib]->getNumero()) + ", " + m_lado_b[ib]->toString() + ", lado B";
    }

    return endereco;
}

/**
 * Retorna um vetor com todas as casas da rua cujo status ocupado é false.
 * @return um vetor contendo casas que estão com status "desocupado"
**/
std::vector<Casa*> rua::get_desocupadas() {
    std::vector<Casa*> aux;

    for (unsigned int i = 0; i < m_lado_a.size(); i++) {
        if (!m_lado_a[i]->isOcupada()) {
            aux.push_back(m_lado_a[i]);
        }
    }

    for (unsigned int i = 0; i < m_lado_b.size(); i++) {
        if (!m_lado_b[i]->isOcupada()) {
            aux.push_back(m_lado_b[i]);
        }
    }

    return aux;
}

/**
 * Apaga o conteúdo dos containers do lado A e do lado B
 */
void rua::clear_rua() {
    m_lado_a.clear();
    m_lado_b.clear();
}