#include "Interface.hpp"

using namespace std;

Interface::Interface(const reference_palavras autocomplete, const reference_palavras autocorrect) {
    m_autocomplete = autocomplete;
    m_autocorrect = autocorrect;
    
    if (m_autocomplete.size() == 0) {
        m_autocomplete.push_back("<nenhuma>");
    }

    if (m_autocorrect.size() == 0) {
        m_autocorrect.push_back("<nenhuma>");
    }
}

void Interface::print_label_input_palavra() {
    cout << ">>> Digite uma palavra, ou parte dela e digite Enter, o pressione Ctrl + d pra terminar: ";
}

string Interface::resultado() {
    string autocomplete_header = "Autocomplete", autocorrect_header = "Autocorrect";
    int max_autocomplete_size = autocomplete_header.size();
    bool has_printed_empty_autocomplete = 0, has_printed_empty_autocorrect = 0;

    for (int i = 0; i < m_autocomplete.size(); i++) {
        max_autocomplete_size = max(max_autocomplete_size, (int) m_autocomplete[i].size());
    }

    ostringstream oss;
    oss << ">>> Matches são\n";
    oss << setw(max_autocomplete_size) << left << autocomplete_header;
    oss << " | " << autocorrect_header;
    oss << '\n';

    int qnt_linhas{ max((int) m_autocorrect.size(), (int) m_autocomplete.size()) };
    for (int i = 0; i < qnt_linhas; i++) {
        std::string autocomplete{ "" }, autocorrect{ "" };
        if (i < (int) m_autocomplete.size()) {
            autocomplete = m_autocomplete[i];
        }
        if (i < (int) m_autocorrect.size()) {
            autocorrect = m_autocorrect[i];
        }
        
        if (autocomplete == "<nenhuma>" && !has_printed_empty_autocomplete) {
            has_printed_empty_autocomplete = 1;
        } else if (autocomplete == "<nenhuma>") {
            autocomplete = "";
        }

        if (autocorrect == "<nenhuma>" && !has_printed_empty_autocorrect) {
            has_printed_empty_autocorrect = 1;
        } else if (autocorrect == "<nenhuma>") {
            autocorrect = "";
        }

        oss << setw(max_autocomplete_size) << left << autocomplete;
        oss << " | " << autocorrect;
        oss << '\n';
    }

    return oss.str();
}