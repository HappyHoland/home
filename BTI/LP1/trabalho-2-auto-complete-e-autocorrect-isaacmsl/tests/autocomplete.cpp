#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include "test_manager.hpp"
#include "Autocomplete.hpp"

int main ()
{
    TestManager tm{ "Testes do Autocomplete" };
  
    //== Espaços para vars que são utilizadas em dois ou mais testes
    //== Fim vars
  
    std::cout << "Running tests...\n";

    {

        BEGIN_TEST( tm, "Validação de autocomplete", "Palavra que não possui sugestões");
        std::string palavra{ "xad" };
        auto database{ new Database("../data/tests/autocomplete_test5.txt") };
        auto autocomplete{new Autocomplete(palavra, database)};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == 0};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        std::vector<std::string> resultado_esperado{"mesmo", "maior"};
        std::string palavra{ "m" };
        BEGIN_TEST( tm, "Validação de autocomplete", "Palavra m");
        auto database{ new Database("../data/tests/autocomplete_test1.txt") };
        auto autocomplete{new Autocomplete(palavra, database)};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i]};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }

    {
        BEGIN_TEST( tm, "Validação de autocomplete", "Palavra B");
        std::string palavra{ "b" };
        auto database = new Database("../data/tests/autocomplete_test4.txt");
        auto autocomplete{new Autocomplete(palavra, database)};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == 1};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        auto sejam_iguais{resultado[0] == "brasil"};
        EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        std::vector<std::string> resultado_esperado{"entre", "engraxate", "engavetar", "engracado"};

        BEGIN_TEST( tm, "Validação de autocomplete", "Palavra en (palavras já são ordenadas no arquivo)");
        std::string palavra{"en"};
        auto database = new Database("../data/tests/autocomplete_test2.txt");
        auto autocomplete{new Autocomplete(palavra, database)};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i]};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }

    {
        std::vector<std::string> resultado_esperado{"entre", "engraxate", "engavetar", "engracado"};

        BEGIN_TEST( tm, "Validação de autocomplete", "Palavra en (testa se ordenacao por peso funciona)");
        auto palavra{ "en" };
        auto database = new Database("../data/tests/autocomplete_test3.txt");
        auto autocomplete{new Autocomplete("en", database)};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i]};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }

    // FIXME: Desconsideramos pois o arquivo não é válido (possui palavras que não se encaixam no padrão de palavras)
    /*{
        std::vector<std::string> resultado_esperado{"sao paulo, brazil", "sao pedro da aldeia, brazil", "sao pedro, brazil", "sao pedro da cova, brazil"};
        auto palavra{"sao"};
        BEGIN_TEST( tm, "Validação de autocomplete", "Palavra Sao");
        auto database = new Database("../data/cities.txt");
        auto autocomplete{new Autocomplete(palavra, database)};
        auto resultado = autocomplete->resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i].second};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }*/

    tm.summary();
    std::cout << '\n';
    return EXIT_SUCCESS;

}
