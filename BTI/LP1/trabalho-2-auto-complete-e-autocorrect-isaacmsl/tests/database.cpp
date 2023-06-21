#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include "test_manager.hpp"
#include "Database.hpp"

int main ()
{
    TestManager tm{ "Testes de Database" };
  
    //== Espaços para vars que são utilizadas em dois ou mais testes
    //== Fim vars
  
    std::cout << "Running tests...\n";

    {

        BEGIN_TEST( tm, "Validação de database", "Testa ordenacao alfabetica de palavras");
        auto database{ new Database("../data/tests/database_test1.txt") };
        auto palavras_ordem_alfabetica = database->get_palavras_ordem_alfabetica();
        
        Database::palavras palavras{};
        palavras.push_back({ 753968, "ainda" });
        palavras.push_back({ 753968, "armário" });
        palavras.push_back({ 1027976, "brasil" });
        palavras.push_back({ 1691241, "entre" });
        palavras.push_back({ 1177376, "foram" });
        palavras.push_back({ 768363, "forma" });
        palavras.push_back({ 763633, "maior" });
        palavras.push_back({ 813125, "mesmo" });
        palavras.push_back({ 1075440, "paulo" });
        palavras.push_back({ 799622, "quando" });
        palavras.push_back({ 1440391, "sobre" });
        palavras.push_back({ 827090, "trabalho" });

        auto tem_mesmo_tamanho{palavras_ordem_alfabetica.size() == palavras.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (int i = 0; i < palavras.size(); i++) {
            auto sejam_iguais{ palavras_ordem_alfabetica[i] == palavras[i] };
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
        }
    }

    {

        BEGIN_TEST( tm, "Validação de database", "Testa ordenacao por tamanho de palavras");
        auto database{ new Database("../data/tests/database_test4.txt") };
        auto palavras_ordem_tamanho = database->get_palavras_ordem_tamanho();
        
        Database::palavras palavras{};
        palavras.push_back({ 1691241, "entre" });
        palavras.push_back({ 1440391, "sobre" });
        palavras.push_back({ 1177376, "foram" });
        palavras.push_back({ 1075440, "paulo" });
        palavras.push_back({ 813125, "mesmo" });
        palavras.push_back({ 768363, "forma" });
        palavras.push_back({ 763633, "maior" });
        palavras.push_back({ 753968, "ainda" });
        palavras.push_back({ 1027976, "brasil" });
        palavras.push_back({ 799622, "quando" });
        palavras.push_back({ 827090, "trabalho" });

        auto tem_mesmo_tamanho{palavras_ordem_tamanho.size() == palavras.size()};
        EXPECT_TRUE(tem_mesmo_tamanho, "Erro em tests/main.cpp::" + std::to_string(__LINE__));

        for (int i = 0; i < palavras.size(); i++) {
            auto sejam_iguais{ palavras_ordem_tamanho[i] == palavras[i] };
            EXPECT_TRUE(sejam_iguais, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
        }
    }

    tm.summary();
    std::cout << '\n';
    return EXIT_SUCCESS;

}
