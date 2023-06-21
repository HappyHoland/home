#ifndef misc_hpp
#define misc_hpp
#include "Matriz.hpp"

/**
 * @brief Inicializa uma matriz seguindo o padr�o de entradas
 * @return Uma refer�ncia para uma matriz correspondente as entradas
 */
Matriz* init_mat(); 

/**
 * @brief Valida o resultado de uma opera��o com matrizes e atualiza os ponteiros
 * 
 * @param init a refer�ncia para a matriz inicial, antes da opera��o
 * @param res a refer�ncia para o resultado
 * @return true se o processo � v�lido, false se n�o
 */
bool validate_res(Matriz *& init, Matriz *& res);

/**
 * @brief Imprime a matriz A 
 * 
 * @param A 
 * @param format 
 */
void printMatriz(Matriz* A, int format);

#endif