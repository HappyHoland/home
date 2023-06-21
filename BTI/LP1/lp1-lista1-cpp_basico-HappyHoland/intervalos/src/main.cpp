/*!
 * @brief This code implements the Intervalos programming problem
 * @author selan
 * @data June, 6th 2021
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setprecision;

#include "func.hpp"

int main(void)
{
    int nums[5];
    float * percs;

    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
    }

    percs = func(nums);

    for (int j = 0; j < 4; j++) {
            cout << "[" << nums[j] << ", " << nums[j+1] << "[ = " << std::fixed << setprecision(2) << percs[j] << endl;
        }

        cout << "outros = " << std::fixed << setprecision(2) << percs[4] << endl;

    return 0;
}
