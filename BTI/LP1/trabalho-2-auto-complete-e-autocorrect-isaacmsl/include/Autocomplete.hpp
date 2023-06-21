#ifndef AUTOCOMPLETE_HPP
#define AUTOCOMPLETE_HPP

#include "Database.hpp"
#include <vector>
#include <algorithm> // sort

/**
 * Classe para autocomplete de palavras
 */
class Autocomplete {
    private:
        using peso_palavra = Database::peso_palavra;
        using palavras = std::vector<std::string>;
        using reference_palavras = palavras&;

        std::string m_palavra; //!< Palavra que será realizado o autocomplete
        Database* m_database; //!< Database que detém as palavras que serão consideradas como possíveis resultados do autocomplete
        palavras m_resultado; //!< Lista de strings resultados do autocomplete
    private:
        /**
         * Preenche m_resultado com palavras similares a palavra procurada
         */
        void palavras_similares();
    public:
        /**
         * Construtor de Autocomplete.
         * Constrói um objeto do tipo Autocomplete com m_palavra e m_database inicializados por parâmetro. Automaticamente realiza
         * suas operações e atualiza m_resultado para o resultado do autocomplete.
         * @param palavra Palavra que será realizado o autocomplete
         * @param database Database que será utilizado no autocomplete
         */
        Autocomplete(const std::string &palavra, Database* database);

        /**
         * Getter de m_resultado
         * @return lista com palavras similares a palavra procurada
         */
        reference_palavras resultado();

        /**
         * Setter para m_palavra
         * @param palavra Nova palavra a ser buscada
         */
        void set_palavra(const std::string& palavra);
};

#endif // AUTOCOMPLETE_HPP
