#include "misc.hpp"
#include "Matriz.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Inicializa uma matriz seguindo o padr�o de entradas
 * @return Uma refer�ncia para uma matriz correspondente as entradas
 */
Matriz* init_mat() {
    Matriz *aux;
    std::string nome, linhas_txt, colunas_txt, n_txt;
    int linhas, colunas, n;

    std::cin >> nome >> linhas >> colunas;

    aux = new Matriz(nome, linhas, colunas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            std::cin >> n;

            aux->setMatrizValue(i, j, n);
        }
    }

    return aux;

}

/**
 * @brief Valida o resultado de uma opera��o com matrizes e atualiza os ponteiros
 * 
 * @param init a refer�ncia para a matriz inicial, antes da opera��o
 * @param res a refer�ncia para o resultado
 * @return true se o resultado � v�lido, false se n�o
 */
bool validate_res(Matriz *& init, Matriz *& res) {
    if (res != nullptr) {
        delete(init);

        init = res;
        res = nullptr;
        
        return true;

    } else {
        return false;

    }
}