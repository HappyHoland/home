#ifndef Matriz_hpp
#define Matriz_hpp

#include <vector>
#include <iostream>
/*TODO documentação estilo doxygen*/
class Matriz{
    private:
        std::string m_nome; //!< nome da matriz
        int m_linhas; //!< número de linhas da matriz
        int m_colunas; //!< número de colunas da matriz
        std::vector<std::vector<int>> m_matriz; //!< container dos elementos da matriz

    public:
        /**
         * @brief Construtor da classe Matriz
         * @param nome o nome da matriz
         * @param linhas o número de linhas da matriz
         * @param colunas o número de colunas da matriz
         */
        Matriz(std::string nome, int linhas, int colunas);

        /**
         * @brief Atribui o valor n numa posição da matriz
         * @param i linha na qual o valor vai ser atribuido
         * @param j coluna na qual o valor vai ser atribuido
         * @param n valor a ser atribuido
         */
        void setMatrizValue(int i, int j, int n);

        /**
         * @brief getter de uma posicao da matriz
         * @param i linha na qual o valor esta
         * @param j coluna na qual o valor esta
         * @return valor na posicao i,j ser atribuido
         */
        int getMatrizValue(int i, int j);

        /**
         * @brief Recebe uma matriz e calcula a soma dela com o objeto
         * @param A uma matriz passada por referência
         * @return Matriz* - Uma referência à matriz resultante
         */
        Matriz* add(Matriz *A);

        /**
         * @brief Recebe uma matriz e calcula o produto matricial 
         * @param A uma matriz passada por referência
         * @return Matriz* - Uma referência à matriz resultante
         */
        Matriz* dot(Matriz *A);

        /**
         * @brief Recebe uma matriz e calcula o produto elemento por elemento
         * @param A uma matriz passada por referência
         * @return Matriz* - Uma referência à matriz resultante
         */
        Matriz* mul(Matriz *A);

        /**
         * @brief Recebe um inteiro e calcula o produto escalar
         * @param n o inteiro a ser multiplicado
         * @return Matriz* - Uma referência à matriz resultante
         */
        Matriz* mue(int n);

        /**
         * @brief Get o nome da matriz
         * @return string correspondente ao nome m_nome
         */
        std::string getnome();

        /**
         * @brief Imprime os valores da matriz
         */
        void printMatriz(void);
        
        /**
         * @brief Get the Linhas object
         * 
         * @return int 
         */
        int getLinhas();

        /**
         * @brief Get the Colunas object
         * 
         * @return int 
         */
        int getColunas();

};

#endif //FiguraGeometrica_hpp