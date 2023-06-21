#ifndef STRING_UTIL_HPP
#define STRING_UTIL_HPP

#include <vector>
#include <string>

class StringUtil {
    public:
        /**
        * Dada uma string, esta função tem por objetivo separar a mesma em substrings de acordo
        * com um caracter específico.
        * @param str string que vai ser dividida.
        * @param delimiter caractere que será utilizado como critério de separação da str.
        * @param trim (padrão é false) se para cada string encontrada deseja usar o metodo trim_str.
        * @return vetor de string.
        */
        static std::vector<std::string> split_str(std::string &str, char delimiter, bool trim = false);

        /**
        * Função que concatena cada elemento de um vetor de string com um caractere entre cada elemento.
        * @param n quantidade de vezes que o caracter será repetido.
        * @param c o caracter que será repetido.
        * @return string.
        */
        static std::string join_str(std::vector<std::string> &strs, char c);

        /**
        * Dado uma string, remove espaços/quebra de linhas na esquerda até que apareça um caracter diferente.
        * @param str string que será manipulada.
        */
        static void trim_left_str(std::string &str);

        /**
        * Dado uma string, remove espaços/quebra de linhas na
        * direita até que apareça um caracter diferente.
        * @param str string que será manipulada.
        */
        static void trim_right_str(std::string &str);

        /**
        * Dado uma string, remove espaços/quebra de linhas na esquerda e
        * na direita até que apareça um caracter diferente.
        * @param str string que será manipulada.
        */
        static void trim_str(std::string &str);
};

#endif // STRING_UTIL_HPP