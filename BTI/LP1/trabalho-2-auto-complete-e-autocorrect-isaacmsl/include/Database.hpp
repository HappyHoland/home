#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <algorithm> // lower_bound, upper_bound
#include <vector>
#include <string>
#include <fstream>
#include "StringUtil.hpp"

/**
 * Classe para manipulação de uma lista de palavras
 */
class Database {
    public:
        using peso_palavra = std::pair<int, std::string>;
        using palavras = std::vector<peso_palavra>;
        using reference_palavras = palavras&;

    private:
        std::string m_caminho; //!< Caminho para a lista de palavras

        palavras m_palavras; //!< Lista de palavras e seus pesos
        palavras m_palavras_ordem_alfabetica; //!< Lista de palavras ordenadas alfabeticamente
        palavras m_palavras_ordem_tamanho; //!< Lista de palavras ordenadas por tamanho
    private:
        /**
         * Ordena palavras atuais por ordem alfabética
         */
        void ordem_alfabetica();

        
        /**
         * Ordena palavras atuais por tamanho da palavra
         */
        void ordem_tamanho_palavra();
        
    public:
        /**
         * Construtor de Database.
         * Constrói um objeto do tipo Database com m_caminho inicializado de acordo com o parâmetro caminho.
         * @param caminho Caminho para a lista de palavras
         */
        Database(const std::string &caminho);

        /**
         * Getter de m_palavras_ordem_alfabetica
         * @return m_palavras_ordem_alfabetica
         */
        reference_palavras get_palavras_ordem_alfabetica();

        /**
         * Getter de m_palavras_ordem_tamanho
         * @return m_palavras_ordem_tamanho
         */
        reference_palavras get_palavras_ordem_tamanho();

        /**
         * Carrega a lista de palavras preenchendo **ao menos** a estrutura m_palavras
         * @return T caso ocorra sucesso no carregamento. F caso contrário.
         */
        bool carregar_palavras();
};

#endif // DATABASE_HPP