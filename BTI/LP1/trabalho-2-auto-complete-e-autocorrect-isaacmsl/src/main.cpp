#include "Database.hpp"
#include "Autocorrect.hpp"
#include "Autocomplete.hpp"
#include "Interface.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    Database* database = new Database(argv[1]);
    string palavra{""};

    if (!database->carregar_palavras()) {
        return 1;
    }
    
    Autocomplete autocomplete(palavra, database);
    Autocorrect autocorrect(palavra, database);

    Interface::print_label_input_palavra();

    while (getline(cin, palavra)) {
        transform(palavra.begin(), palavra.end(), palavra.begin(), ::tolower);

        while (palavra.find_first_not_of("abcdefghijklmnopqrstuvwxyl- '") != string::npos) {
            Interface::print_label_input_palavra();
            getline(cin, palavra);
        }

        autocomplete.set_palavra(palavra);
        autocorrect.set_palavra(palavra);

        Interface interface(autocomplete.resultado(), autocorrect.get_resultado());

        cout << interface.resultado();

        Interface::print_label_input_palavra();
    }

    delete(database);

    return 0;
}