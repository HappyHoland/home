#ifndef misc_hpp
#define misc_hpp

#include <vector>
#include "Casa.hpp"

/**
 * @brief Verifica se uma casa pertence a um vetor de casas
 * @param vec vetor de refer�ncias para casas
 * @param elm uma refer�ncia para uma casa
 * @returns um inteiro correspondente ao �ndice da casa no vetor, se a casa estiver nele. Caso n�o esteja, retorna -1
 */
int casa_in_vec(std::vector<Casa*> &vec, Casa* elm);

/**
 * @brief Verifica se alguma casa tem o n�mero igual a num
 * @param vec vetor de refer�ncias para casas
 * @param num o n�mero da casa a ser achada
 * @returns um inteiro correspondente ao �ndice da casa no vetor, se a casa estiver nele. Caso n�o esteja, retorna -1
 */
int casa_in_vec(std::vector<Casa*> &vec, int num);

#endif