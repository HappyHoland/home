#include "function.hpp"
#include <iostream>
using namespace std;

template <typename t>
int in_vector(vector<t> vec, t x) {
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        if (vec[i] == x) {return i;}
    }

    return -1;
}

int in_vector(vector<bool> vec, bool x) {
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        if (vec[i] == x) {return i;}
    }

    return -1;
}

template <typename t>
void sort_vects (vector<pair<t, int>>& v, int n) {
    pair<t, int> aux;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j].first <= v[i].first) {
                aux.first = v[j].first;
                aux.second = v[j].second;

                v[j].first = v[i].first;
                v[j].second = v[i].second;

                v[i].first = aux.first;
                v[i].second = aux.second;
            }
        }
    }
}

vector<pair<int, int>> histograma(const vector<int> &V){
    int n = V.size();
    int index;
    vector<int> elms;
    
    vector<pair<int, int>> aux;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            elms.push_back(V[0]);
            aux.push_back(make_pair(V[0], 1));

        } else {
            index = in_vector(elms, V[i]);

            if (index >= 0) {
                aux[index].second++;
            } else {
                elms.push_back(V[i]);
                aux.push_back(make_pair(V[i], 1));

            }
        }
    }

    sort_vects(aux, aux.size());
    
    return aux; 
}

vector<pair<float, int>> histograma(const vector<float> &V){
    int n = V.size();
    int index;
    vector<float> elms;
    
    vector<pair<float, int>> aux;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            elms.push_back(V[0]);
            aux.push_back(make_pair(V[0], 1));

        } else {
            index = in_vector(elms, V[i]);

            if (index >= 0) {
                aux[index].second++;
            } else {
                elms.push_back(V[i]);
                aux.push_back(make_pair(V[i], 1));
            }
        }
    }

    sort_vects(aux, aux.size());
    
    return aux;
}

vector<pair<double, int>> histograma(const vector<double> &V){
    int n = V.size();
    int index;
    vector<double> elms;
    
    vector<pair<double, int>> aux;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            elms.push_back(V[0]);
            aux.push_back(make_pair(V[0], 1));
        } else {
            index = in_vector(elms, V[i]);

            if (index >= 0) {
                aux[index].second++;
            } else {
                elms.push_back(V[i]);
                aux.push_back(make_pair(V[i], 1));
            }
        }
    }

    sort_vects(aux, aux.size());
    
    return aux; 
}

vector<pair<char, int>> histograma(const vector<char> &V){
    int n = V.size();
    int index;
    vector<char> elms;
    
    vector<pair<char, int>> aux;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            elms.push_back(V[0]);
            aux.push_back(make_pair(V[0], 1));
        } else {
            index = in_vector(elms, V[i]);

            if (index >= 0) {
                aux[index].second++;
            } else {
                elms.push_back(V[i]);
                aux.push_back(make_pair(V[i], 1));
            }
        }
    }

    sort_vects(aux, aux.size());
    
    return aux; 
}

vector<pair<string, int>> histograma(const vector<string> &V){
    int n = V.size();
    int index;
    vector<string> elms;
    
    vector<pair<string, int>> aux;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            elms.push_back(V[0]);
            aux.push_back(make_pair(V[0], 1));
        } else {
            index = in_vector(elms, V[i]);

            if (index >= 0) {
                aux[index].second++;
            } else {
                elms.push_back(V[i]);
                aux.push_back(make_pair(V[i], 1));
            }
        }
    }

    sort_vects(aux, aux.size());
    
    return aux;
}

vector<pair<bool, int>> histograma(const vector<bool> &V){
    int n = V.size();
    int index;
    vector<bool> elms;
    
    vector<pair<bool, int>> aux;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            elms.push_back(V[0]);
            aux.push_back(make_pair(V[0], 1));
        } else {
            index = in_vector(elms, V[i]);

            if (index >= 0) {
                aux[index].second++;
            } else {
                elms.push_back(V[i]);
                aux.push_back(make_pair(V[i], 1));
            }
        }
    }
    
    return aux; 
}