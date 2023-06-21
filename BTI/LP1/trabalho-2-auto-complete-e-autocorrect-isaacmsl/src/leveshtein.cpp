#include "leveshtein.hpp"
#include <string>
#include <vector>
#include <algorithm>

int edit_dist (std::string palavra1, std::string palavra2) {
    std::vector <std::vector <int>> d;
    int substitutionCost;

    for (int i = 0;  i <= palavra1.size(); i++) {
        std::vector <int> aux;

        for (int j = 0; j <= palavra2.size(); j++) {
            aux.push_back(0);
        }

        d.push_back(aux);
    }

    for (int i = 1; i <= palavra1.size(); i++) {
        d[i][0] =  i;
    }

    for (int i = 1; i <= palavra2.size(); i++) {
        d[0][i] =  i;
    }

    for (int i = 1; i <= palavra1.size(); i++) {
        for (int j = 1; j <= palavra2.size(); j++) {
            if (palavra1[i-1] == palavra2[j-1]) {
                substitutionCost = 0;
            } else {
                substitutionCost = 1;
            }

            d[i][j] = std::min({d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + substitutionCost}, [](int a, int b) {return a < b;});
        }
    }

    return d[palavra1.size()][palavra2.size()];
}