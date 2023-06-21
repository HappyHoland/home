#ifndef Autocorrect_hpp
#define Autocorrect_hpp

#include <vector>
#include <string>
#include "Database.hpp"
#include "leveshtein.hpp"

class Autocorrect {
    public:
        using peso_palavra = std::pair<int, std::string>;
        using palavras = std::vector<peso_palavra>;
        using reference_palavras = palavras&;

    private:
        Database* m_database;//<! dados ordenados por tamanho da palavra
        std::string m_palavra;//<! palavra a ser buscada nos dados
        int m_num_result;//<! numero de opcoes de correcao a serem mostradas
        std::vector <std::string> m_resultado;//<! resultado do autocorrect

    public:
        /**
         * @brief Construct a new Autocorrect object
         * 
         * @param palavra a palavra a ser comparada
         * @param dados a versao ordenada dos dados recebidos do arquivo
         */
        Autocorrect(std::string palavra, Database* database, int num = 4);

        /**
         * @brief Set the palavra object
         * 
         * @param palavra 
         */
        void set_palavra(std::string palavra);

        /**
         * @brief Getter do resultado 
         * 
         * @return std::vector<std::string>* 
         */
        std::vector<std::string>& get_resultado();
};

#endif