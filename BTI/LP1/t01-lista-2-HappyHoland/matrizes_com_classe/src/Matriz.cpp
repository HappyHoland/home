#include "Matriz.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

/**
 * @brief Construtor da classe Matriz
 * @param nome o nome da matriz
 * @param linhas o número de linhas da matriz
 * @param colunas o número de colunas da matriz
 */
Matriz::Matriz(std::string nome, int linhas, int colunas){
    std::vector<int> aux;
    
    m_nome = nome;
    m_linhas = linhas;
    m_colunas = colunas;

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            aux.push_back(0);
        }

        m_matriz.push_back(aux);
        aux.clear();
    }
}

/**
 * @brief Atribui o valor n numa posição da matriz
 * @param i linha na qual o valor vai ser atribuido
 * @param j coluna na qual o valor vai ser atribuido
 * @param n valor a ser atribuido
 */
void Matriz::setMatrizValue(int i, int j, int n) {
    m_matriz[i][j] = n;
}

int Matriz::getMatrizValue(int i, int j) {
    return m_matriz[i][j];
}

/**
 * @brief Recebe duas matrizes e calcula sua soma
 * @param A uma matriz passada por referência
 * @return Matriz* - Uma referência à matriz resultante
 */
Matriz* Matriz::add(Matriz *A){
    Matriz *result = new Matriz(m_nome + " add " + A->m_nome, m_linhas, m_colunas);
    
    if (m_linhas != A->getLinhas() or m_colunas != A->getColunas()) {
        return nullptr;
    }
    
    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            result->setMatrizValue(i, j, m_matriz[i][j] + A->getMatrizValue(i,j));

        }
    }

    return result;
}

/**
 * @brief Recebe duas matrizes e calcula o produto matricial 
 * @param A uma matriz passada por referência
 * @return Matriz* - Uma referência à matriz resultante
 */
Matriz* Matriz::dot(Matriz *A){
    Matriz *result = new Matriz(m_nome + " dot " + A->m_nome, m_linhas, A->m_colunas);

    if (m_colunas != A->getLinhas()) {
        return nullptr;
    }

    for (int i = 0; i < result->getLinhas(); i++) {
        for (int j = 0; j < result->getColunas(); j++) {
            int aux = 0;

            for (int k = 0; k < m_colunas; k++) {
                aux += m_matriz[i][k]*A->getMatrizValue(k,j);
            }

            result->setMatrizValue(i, j, aux);

        }
    }

    return result;
}

/**
 * @brief Recebe duas matrizes e calcula o produto elemento por elemento das duas
 * @param A uma matriz passada por referência
 * @return Matriz* - Uma referência à matriz resultante
 */
Matriz* Matriz::mul(Matriz *A){
    Matriz *result = new Matriz(m_nome + " mul " + A->m_nome, m_linhas, m_colunas);

    if (m_linhas != A->getLinhas() or m_colunas != A->getColunas()) {
        return nullptr;
    }

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            result->setMatrizValue(i,j, m_matriz[i][j]*A->getMatrizValue(i,j));

        }
    }

    return result;
}

/**
 * @brief Recebe duas matrizes e calcula o produto elemento por elemento das duas
 * @param n o inteiro a ser multiplicado
 * @return Matriz* - Uma referência à matriz resultante
 */
Matriz* Matriz::mue(int n) {
    Matriz *result = new Matriz(m_nome + " mue " + std::to_string(n), m_linhas, m_colunas);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            result->setMatrizValue(i,j,m_matriz[i][j]*n);

        }
    }

    return result;
}

/**
 * @brief Get o nome da matriz
 * 
 * @return string correspondente ao nome m_nome
 */
std::string Matriz::getnome() {
    return m_nome;
}

int Matriz::getLinhas() {
    return m_linhas;
}

int Matriz::getColunas() {
    return m_colunas;
}

/**
 * @brief Imprime os valores da matriz
 */
void Matriz::printMatriz(){
    int format = 0;

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            if (std::to_string(m_matriz[i][j]).size() > format) {
                format = std::to_string(m_matriz[i][j]).size();
            }
        }
    }

    auto sw = std::setw(format+1);

    for (int i = 0; i < m_linhas; i++) {
        for (int j = 0; j < m_colunas; j++) {
            if (j < m_colunas - 1) {
                std::cout << sw << std::left;
            }
            std::cout << m_matriz[i][j];
        }

        std::cout << std::endl;
    }
}

/*TODO implementação da classe*/
