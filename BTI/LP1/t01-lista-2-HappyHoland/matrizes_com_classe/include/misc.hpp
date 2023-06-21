#ifndef misc_hpp
#define misc_hpp
#include "Matriz.hpp"

/**
 * @brief Inicializa uma matriz seguindo o padrão de entradas
 * @return Uma referência para uma matriz correspondente as entradas
 */
Matriz* init_mat(); 

/**
 * @brief Valida o resultado de uma operação com matrizes e atualiza os ponteiros
 * 
 * @param init a referência para a matriz inicial, antes da operação
 * @param res a referência para o resultado
 * @return true se o processo é válido, false se não
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