#include "func.hpp"
#include <iostream>
using std::cin;

float * func(int array[]){
    int x, total = 0, in_interval[5] = {0, 0, 0, 0, 0};
    float static perc[5] = {0, 0, 0, 0, 0};
    
    while( cin >> std::ws >> x) {
        total++;

        if (x >= array[0] && x < array[1]) {in_interval[0]++;} 
        
        else if (x >= array[1] && x < array[2]) {in_interval[1]++;} 
        
        else if (x >= array[2] && x < array[3]) {in_interval[2]++;} 
        
        else if (x >= array[3] && x < array[4]) {in_interval[3]++;} 
        
        else {in_interval[4]++;}

    }

    for (int i = 0; i < 5; i++) {
        perc[i] = in_interval[i]*100.00/total;
    }

    return perc;
}