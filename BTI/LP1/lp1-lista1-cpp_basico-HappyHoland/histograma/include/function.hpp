#ifndef FUNCTION_H
#define FUNCTION_H

#include <utility>
#include <vector>
#include <string>

/*! 
 * Computa e retorna um histograma no formato especificado. Veja que essa função só funciona
 * se os dados de V forem inteiros!
 *
 * @param V um vetor de dados quaisquer
 *
 * @return um vetor contendo pares representando o histograma dos dados
 */

template <typename t>
int in_vector(std::vector<t> vec, t x);

int in_vector(std::vector<bool> vec, bool x);

template <typename t>
void sort_vects (std::vector<std::pair<t, int>>& v2, int n);

std::vector<std::pair<int, int>> histograma(const std::vector<int>& V);

std::vector<std::pair<float, int>> histograma(const std::vector<float>& V);

std::vector<std::pair<double, int>> histograma(const std::vector<double>& V);

std::vector<std::pair<char, int>> histograma(const std::vector<char>& V);

std::vector<std::pair<std::string, int>> histograma(const std::vector<std::string>& V);

std::vector<std::pair<bool, int>> histograma(const std::vector<bool>& V);


#endif
