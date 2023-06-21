#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include "test_manager.hpp"
#include "Autocorrect.hpp"
#include "Database.hpp"

int main ()
{
    TestManager tm{ "Testes do Autocorrect" };
  
    //== Espaços para vars que são utilizadas em dois ou mais testes
    //== Fim vars
  
    std::cout << "Running tests...\n";

   
    {

        BEGIN_TEST( tm, "Validação de autocorrect", "Palavra que não possui sugestões");
        std::string dir{"../data/tests/autocorrect_test3.txt"};
        auto autocorrect{new Autocorrect("Bol", new Database(dir))};
        auto resultado = autocorrect->get_resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == 0};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    
    tm.summary();
    std::cout << '\n';
    
    {

        BEGIN_TEST( tm, "Validação de autocorrect", "Palavra de tamanho menor que 3");
        std::string dir{"../data/tests/autocorrect_test2.txt"};
        auto autocorrect{new Autocorrect("Ar", new Database(dir))};
        auto resultado = autocorrect->get_resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == 0};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    
    tm.summary();
    std::cout << '\n';
    
    {
        std::vector<std::string> resultado_esperado{"bolha", "bolhas", "colha", "bolsa"};

        BEGIN_TEST( tm, "Validação de autocorrect", "Palavra bolha");
        std::string dir{"../data/tests/autocorrect_test1.txt"};
        auto autocorrect{new Autocorrect("bolha", new Database(dir))};
        auto resultado = autocorrect->get_resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i]};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }
    
    tm.summary();
    std::cout << '\n';
    
    {
        std::vector<std::string> resultado_esperado{"sao", "sal", "sai", "sem"};

        BEGIN_TEST( tm, "Validação de autocorrect", "Palavra Sao");
        std::string dir{"../data/tests/autocorrect_test2.txt"};
        auto autocorrect{new Autocorrect("sao", new Database(dir))};
        auto resultado = autocorrect->get_resultado();
        
        auto tem_mesmo_tamanho{resultado.size() == resultado_esperado.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (auto i{0}; i < (int) resultado_esperado.size(); i++) {
            auto sejam_iguais{resultado_esperado[i] == resultado[i]};
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));            
        }
    }
    

    tm.summary();
    std::cout << '\n';
    return EXIT_SUCCESS;

}
