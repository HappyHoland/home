#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <vector>
#include <iostream>
#include <string>
#include <iomanip> // setw

/**
 * Classe para apresentar a interface da aplicação ao usuário
 */
class Interface {
    public:
        using palavras = std::vector<std::string>;
        using reference_palavras = palavras&;

    private:
        palavras m_autocomplete; //!< Lista de palavras do autocomplete
        palavras m_autocorrect; //!< Lista de palavras do autocorrect
    public:
        /**
         * Construtor de Interface.
         * Constrói um objeto do tipo Interface iniacializando os atributos de acordo com os parâmetros.
         * @param 
         */
        Interface(const reference_palavras autocomplete, const reference_palavras autocorrect);

        /**
         * Constrói uma string mostrando o resultado do autocomplete e autocorrect
         * @return string resultado do autocomplete e autocorrect
         */
        std::string resultado();

        /**
         * Imprime na saída padrão um texto informativo solicitando uma palavra
         */
        static void print_label_input_palavra();
};

#endif // INTERFACE_HPP