#include <iostream>
#include "Casa.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

/**
 * Construtor da classe casa.
 * @param areaConstruida a área construida da casa
 * @param areaTotal a area total do terreno
 */
Casa::Casa(double areaConstruida, double areaTotal) {
    m_areaConstruida = areaConstruida;
    m_areaTotal = areaTotal;
    m_numero = -1;
    m_ocupada = false;
}

/**
 * Getter do número da casa.
 * @return o número da casa.
 */
int Casa::getNumero() {
    return m_numero;
}

/**
 * Setter do número da casa
 * @param n o número que deve ser atribuído à casa
 */
void Casa::setNumero(int n) {
    m_numero = n;
}

/**
 * Setter do ocupada
 * @param ocupada o estado da casa, desocupada (F) / ocupada(T)
 */
void Casa::setOcupada(bool ocupada){
    m_ocupada = ocupada;
}

/**
 * Getter do estado da casa
 * @return T se ocupada, F caso contrário.
 */
bool Casa::isOcupada(){
    return m_ocupada;
}

/**
 * Retorna uma representação de string da Casa no formato Área: area_ocupada / areaConstruida m2
 * @return a representação em string da casa.
 */
std::string Casa::toString(){
    std::ostringstream sstream;
    sstream << "Área: " << std::fixed << std::setprecision(2) << m_areaConstruida << " / " << std::fixed << std::setprecision(2) << m_areaTotal;
    return sstream.str();
}