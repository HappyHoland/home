#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include <algorithm>  // lower_bound, upper_bound
#include "test_manager.hpp"
//#include "Database.hpp"
#include "leveshtein.hpp"

bool fair_compare_strs( std::string target, const std::string element ) {
    return target < element.substr( 0, target.size() );
}

int main ()
{
    TestManager tm{ "Testes do Trabalho 2" };
  
    //== Espaços para vars que são utilizadas em dois ou mais testes
    size_t a_size{4};
    std::pair<int, int> A[a_size];
    A[0] = {10, 4};
    A[1] = {30, 4};
    A[2] = {10, 3};
    A[3] = {30, 1};

    std::pair<int, int> A_sorted[a_size];
    A_sorted[0] = {30, 1};
    A_sorted[1] = {30, 4};
    A_sorted[2] = {10, 3};
    A_sorted[3] = {10, 4};

    std::pair<int, int> A_sorted2[a_size];
    A_sorted2[0] = {30, 1};
    A_sorted2[1] = {10, 3};
    A_sorted2[2] = {30, 4};
    A_sorted2[3] = {10, 4};

    std::string words[]{ "gato", "galinha", "geladeira", "gelo", "helicoptero", "zebra" };
    int qnt_words = 6;
    //== Fim vars
  
    std::cout << "Running tests...\n";

    {
        BEGIN_TEST( tm, "Validação de lower_bound", "Espera encontrar a primeira palavra não menor do que a palavra 'ga'");
        auto resultado{ std::lower_bound( words, words + qnt_words, "ga" ) };
        EXPECT_TRUE( *resultado == words[0], "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm, "Validação de lower_bound", "Espera encontrar a primeira palavra não menor do que a palavra 'ge'");
        auto resultado{ std::lower_bound( words, words + qnt_words, "ge" ) };
        EXPECT_TRUE( *resultado == words[2], "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm, "Validação de lower_bound", "Espera encontrar a primeira palavra não menor do que a palavra 'h'");
        auto resultado{ std::lower_bound( words, words + qnt_words, "h" ) };
        EXPECT_TRUE( *resultado == words[4], "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm, "Validação de upper_bound", "Espera encontrar a primeira palavra maior do que a palavra 'ga'");
        auto resultado{ 
            std::upper_bound( 
                words,
                words + qnt_words, 
                "ga" ,
                fair_compare_strs
            )
        };
        EXPECT_TRUE( *resultado == words[2], "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm, "Validação de upper_bound", "Espera encontrar a primeira palavra maior do que a palavra 'ge'");
        auto resultado{ 
            std::upper_bound( 
                words,
                words + qnt_words, 
                "ge" ,
                fair_compare_strs
            )
        };
        EXPECT_TRUE( *resultado == words[4], "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm, "Validação de upper_bound", "Espera encontrar a primeira palavra maior do que a palavra 'z'");
        auto resultado{ 
            std::upper_bound( 
                words,
                words + qnt_words, 
                "z" ,
                fair_compare_strs
            )
        };
        EXPECT_TRUE( resultado == end(words), "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    /*
    {
        std::vector<std::string> resultado_esperado{"sao paulo, brazil", "sao pedro da aldeia, brazil", "sao pedro, brazil", "sao pedro da cova, brazil"};

        BEGIN_TEST( tm, "Validação de autocomplete", "Espera ter saídas corretas ao informar a palavra Sao");
        auto autocomplete{new Autocomplete("Sao", "/data/cities.txt")};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i]};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }
    */

    /*
    {
        BEGIN_TEST( tm,"Validação de arquivos", "Arquivo não existente");

        Database Database("words.txt");
        
        auto result = Database.eh_valido();

        EXPECT_TRUE( (result.first == false && result.second == "Arquivo inexistente: words.txt") , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    */
  
    /*
    {
        BEGIN_TEST( tm,"Validação de arquivos", "Arquivo com caracteres especiais");

        Database Database("/tests/database_test1.txt");
        
        auto result = Database.eh_valido();

        EXPECT_TRUE( (result.first == false && result.second == "line 10 word cabeça") , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    */
  
    /*
    {
        BEGIN_TEST( tm,"Validação de arquivos", "Arquivo com palavra sem peso");

        Database Database("tests/database_test2.txt");
        
        auto result = Database.eh_valido();

        EXPECT_TRUE( (result.first == false && result.second == "line 12 word amarelo") , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    */
  
    /*
    {
        BEGIN_TEST( tm,"Validação de arquivos", "Arquivo com palavra de peso negativo");

        Database Database("tests/database_test3.txt");
        
        auto result = Database.eh_valido();

        EXPECT_TRUE( (result.first == false && result.second == "line 7 word mesmo") , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    */
    
    /*
    {
        BEGIN_TEST( tm,"Validação de arquivos", "Armazenamento");

        Database Database("tests/database_test4.txt");
        
        auto result = Database.getvec();

        EXPECT_TRUE( (*result)[2].first == 1177376 && (*result).second == "foram") , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    */
  
    
    {
        BEGIN_TEST( tm,"Distancia de Levenshtein", "kitten - sitting");

        int dist = edit_dist("kitten", "sitting");

        EXPECT_TRUE( (dist == 3) , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    
  
    
    {
        BEGIN_TEST( tm,"Distancia de Levenshtein", "bonita - baroco");

        int dist = edit_dist("bonita", "baroco");

        EXPECT_TRUE( (dist == 5) , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    
    
    
    {
        BEGIN_TEST( tm,"Distancia de Levenshtein", "health - healing");

        int dist = edit_dist("health", "healing");

        EXPECT_TRUE( (dist == 3) , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    
  
    /*
    {   
        auto resultado_esperado{(103, "bobear"), (100, "abacaxi"), (105, "abaixar"), (102, "abelha"), (104, "urso")};
        BEGIN_TEST( tm,"Sorting Binario", "Vetor de pares e vetor de distancia");

        std::vector <std::pair <int, std::string>> vec{(102, "abelha"), (104, "urso"), (100, "abacaxi"), (105, "abaixar"), (103, "bobear")};
        std::vector <int> vec1{2, 3, 1, 2, 1}

        our_sort(vec, vec1);

        for (int i = 0; i < 5; i++) {
            auto sejam_iguais{vec[i] == resultado_esperado[i]};
            EXPECT_TRUE( sejam_iguais , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
        }
    }
    */
    
    /*
    {
        auto resultado_esperado{(1691242, "bolsa"), (1691241, "folha"), (1691240, "bolhas"), (1691239, "colha"), (1691241, "bomba")}

        BEGIN_TEST( tm,"Sorting Binario", "Arquivo de referencia");

        Database Database("/tests/sort_test.txt")

        Database.sort_size();

        auto vec = Database.getvec();

        auto vec_ed = Database.Levenshtein("bolha");

        our_sort_ref(vec, vec_ed);

        for (int i = 0; i < 5; i++) {
            auto sejam_iguais{vec[i] == resultado_esperado[i]};
            EXPECT_TRUE( sejam_iguais , "Erro em tests/main.cpp::" + std::to_string(__LINE__));
        }
    }
    */
  
    {
        BEGIN_TEST(tm, "Ordenação de pares {peso, distância}", "Testa funcionamento da ordenação de pares {peso, distância} por subtração");

        std::pair<int, int> B[a_size];
        std::copy(A, A+a_size, B);

        std::sort(B, B + a_size,
            [](std::pair<int, int>& a, std::pair<int, int>& b) {
                return a.first - a.second > b.first - b.second;
            }
        );

        for (size_t i{0}; i < a_size; i++) {
            bool result{B[i].first == A_sorted[i].first && B[i].second == A_sorted[i].second};
            EXPECT_TRUE(result, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
        }
    }

    {
        BEGIN_TEST(tm, "Ordenação de pares {peso, distância}", "Testa funcionamento da ordenação de pares {peso, distância} por expressão lógica");

        std::pair<int, int> B[a_size];
        std::copy(A, A+a_size, B);

        std::sort(B, B + a_size,
            [](std::pair<int, int>& a, std::pair<int, int>& b) {
                return a.second < b.second || (a.second == b.second && a.first > b.first);
            }
        );

        for (size_t i{0}; i < a_size; i++) {
            bool result{B[i].first == A_sorted2[i].first && B[i].second == A_sorted2[i].second};
            EXPECT_TRUE(result, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
        }
    }
    
    tm.summary();
    std::cout << '\n';
    return EXIT_SUCCESS;

}
