#ifndef Jogador_hpp
#define JOgador_hpp

#include "BingoRand.hpp"
#include <iostream>
#include <string>
#include <vector>

/**
 * Classe para armazenamento dos dados dos jogadores
 */
class Jogador {
    private:
        std::string m_nome; //<! nome do jogador
        std::vector <int> m_cartela; //<! cartela do jogador
        unsigned int m_acertos; //<! acertos
    
    public:
        /**
         * @brief Construtor da classe Jogador
         * 
         * @param nome o nome do jogador
         */
        Jogador(std::string nome, BingoRand *Brnd);

        /**
         * @brief Getter do nome 
         * 
         * @return m_nome
         */
        std::string getNome();

        /**
         * @brief Getter do acertos
         * 
         * @return m_acertos 
         */
        unsigned int getAcertos();

        /**
         * @brief Verifica se o numero sorteado esta contido na cartela e atualiza 
         * m_acertos se estiver
         * @param num 
         * @return true se estiver, false se nao estiver
         */
        bool searchCartela(int num);

        /**
         * @brief retorna a cartela do jogador no formato [x0, x1, x2, ..., xn-1, xn]
         * @return uma string representando a cartela
         */
        std::string stringCartela();
};

#endif 