#include "function.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main(){
    vector<int> ints{1, 2, 2, 1, 3, 5, 2, 5, 4, 3};
    vector<pair<int,int>> inthist = histograma(ints);
    int sizeints = inthist.size();

    for (int i = 0; i < sizeints; i++) {
        cout << "(" << inthist[i].first << "," << inthist[i].second << ") ";
    }

    cout << endl;

    vector<float> floats{1.0, 1.5, 1.0, 2.3, 1.5, 2.2, 2.2, 1.5, 1.5};
    
    auto floathist = histograma(floats);
    int sizefloats = floathist.size();

    for (int i = 0; i < sizefloats; i++) {
        cout << "(" << floathist[i].first << "," << floathist[i].second << ") ";
    }

    cout << endl;

    vector<double> doubles{1.1, 1.3, 1.1, 2.6, 1.5, 10.2, 2.6, 1.5, 1.5};
    auto doublehist = histograma(doubles);
    int sizedoubles = doublehist.size();

    for (int i = 0; i < sizedoubles; i++) {
        cout << "(" << doublehist[i].first << "," << doublehist[i].second << ") ";
    }

    cout << endl;

    vector<char> chars{'a', 'a', 'z', 'y', 'c', 'a', 'c', 'j', 'z', 'e', 'z', 'a'};
    auto charhist = histograma(chars);
    int sizechars = charhist.size();

    for (int i = 0; i < sizechars; i++) {
        cout << "(" << charhist[i].first << "," << charhist[i].second << ") ";
    }

    cout << endl;

    vector<string> strings{"abba", "mamma mia", "bia", "aloha", "Hello World", "abba", "bia", "abba", "aloha"};
    auto stringhist = histograma(strings);
    int sizestrings = stringhist.size();

    for (int i = 0; i < sizestrings; i++) {
        cout << "(" << stringhist[i].first << "," << stringhist[i].second << ") ";
    }

    cout << endl;
    vector<bool> bools{true, false, true, true, false, false, false, true, false, false, false};
    auto boolhist = histograma(bools);
    int sizebools = boolhist.size();

    for (int i = 0; i < sizebools; i++) {
        cout << "(" << boolhist[i].first << "," << boolhist[i].second << ") ";
    }

    cout << endl;

    return 0;
}