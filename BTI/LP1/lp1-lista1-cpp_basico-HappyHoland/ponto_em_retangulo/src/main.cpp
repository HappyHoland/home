/*!
 * @brief Implementação do Ponto em Retângulo V2.
 * @author selan
 * @data June, 6th 2021
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <algorithm>
using std::min;
using std::max;

#include "function.h"


int main(void)
{
    Ponto rect1, rect2, P, IE, SD;
    int P_pos;

    while (cin >> std::ws >> rect1.x) {
        cin >> rect1.y >> rect2.x >> rect2.y >> P.x >> P.y;

        if (validate_rect(rect1, rect2)) {
            IE.x = min(rect1.x, rect2.x);
            IE.y = min(rect1.y, rect2.y);
            SD.x = max(rect1.x, rect2.x);
            SD.y = max(rect1.y, rect2.y);

            P_pos = pt_in_rect(IE, SD, P);

            switch (P_pos) {
                case -1:
                    cout << "outside" << endl;
                    break;
                case 0:
                    cout << "inside" << endl;
                    break;
                case 1:
                    cout << "border" << endl;
                    break;
            }
        } else {cout << "invalid" << endl;}
    }
    

    return 0;
}
