#include <iostream>   // cout, endl
#include <cassert>    // assert()
#include <random>     // random_device, mt19937
#include <iterator>   // std::begin(), std::end()
#include <fstream>    // ifstream
#include "test_manager.hpp"
#include "Interface.hpp"
#include "Autocomplete.hpp"
#include "Autocorrect.hpp"
#include "StringUtil.hpp"
#include "Database.hpp"

std::string file_to_str(std::string path_file) {
    std::ifstream file ( path_file );
    std::string output{""}, line{""};
    
    while ( getline( file, line )) {
        output += line;
        output += "\n";
    }
    return output;
}

int main ()
{
    TestManager tm{ "Testes de Interface" };
  
    //== Espaços para vars que são utilizadas em dois ou mais testes
    //== Fim vars
  
    std::cout << "Running tests...\n";

    {

        BEGIN_TEST( tm, "Validação de interface", "Palavra que não possui sugestões");
        auto database{ new Database("../data/tests/interface_test1.txt")};
        std::string palavra{"xad"};
        auto autocomplete{new Autocomplete(palavra, database)};
        auto autocorrect{new Autocorrect(palavra, database)};

        auto interface{ new Interface(autocomplete->resultado(), autocorrect->get_resultado()) };
        auto resultado{ interface->resultado() };
        
        std::string path_file = "../data/expected/interface_test1.txt";
        std::string esperado = file_to_str( path_file );
        
        EXPECT_TRUE(resultado == esperado, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    
    
    {
        BEGIN_TEST( tm, "Validação de interface", "Palavra que possui apenas autocomplete");
        auto database{ new Database("../data/tests/interface_test2.txt")};
        std::string palavra{"en"};
        auto autocomplete{new Autocomplete(palavra, database)};
        auto autocorrect{new Autocorrect(palavra, database)};

        auto interface{ new Interface(autocomplete->resultado(), autocorrect->get_resultado()) };
        auto resultado{ interface->resultado() };
        
        std::string path_file = "../data/expected/interface_test2.txt";
        std::string esperado = file_to_str( path_file );

        EXPECT_TRUE(resultado == esperado, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    {
        BEGIN_TEST( tm, "Validação de interface", "Palavra que possui apenas autocorrect");
        auto database{ new Database("../data/tests/interface_test3.txt")};
        std::string palavra{"sao"};
        auto autocomplete{new Autocomplete(palavra, database)};
        auto autocorrect{new Autocorrect(palavra, database)};

        auto interface{ new Interface(autocomplete->resultado(), autocorrect->get_resultado()) };
        auto resultado{ interface->resultado() };
        
        std::string path_file = "../data/expected/interface_test3.txt";
        std::string esperado = file_to_str( path_file );

        EXPECT_TRUE(resultado == esperado, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }

    // FIXME: Desconsiderado por conter palavras de formatos inesperados
    /*
    {
        BEGIN_TEST( tm, "Validação de interface", "Cities");
        std::string palavra{"sao"};
        auto autocomplete{new Autocomplete(palavra, "/data/cities.txt")};
        auto autocorrect{new Autocorrect(palavra, "/data/cities.txt")};

        auto resultado{ Interface.resultado(autocomplete->resultado(), autocorrect->resultado()) };

        std::ifstream arquivo_resultado_esperado ( "/data/expected/cities.txt" );
        
        EXPECT_TRUE(arquivo_resultado_esperado.is_open(), "Arquivo de teste não foi encontrado. tests/main.cpp::" + std::to_string(__LINE__));

        std::string esperado{ file_to_str( arquivo_resultado_esperado )};

        EXPECT_TRUE(resultado == esperado, "Erro em tests/main.cpp::" + std::to_string(__LINE__));
    }
    */

    tm.summary();
    std::cout << '\n';
    return EXIT_SUCCESS;

}
