#include <iostream>  
#include "Matriz.hpp"
#include "misc.hpp"
#include <string>
#include <vector>

using namespace std;

int main ( void )
{
    Matriz *result, *aux;
    string txt;
    int n;
    bool interrupted = false;

    result = init_mat();

    while (cin >> txt) {
        if (!interrupted) {
            if (txt == "add") {
                aux = result->add(init_mat());

                interrupted = !validate_res(result, aux);

            } else if (txt == "dot") {
                aux = result->dot(init_mat());

                interrupted = !validate_res(result, aux);

            } else if (txt == "mul") {
                aux = result->mul(init_mat());

                interrupted = !validate_res(result, aux);
            } else {
                cin >> n;

                aux = result->mue(n);

                delete(result);
                result = aux;

            }
        }
    }

    cout << "Resultado " << result->getnome();

    if (interrupted) {
        cout << " pôde ser calculado, resultado até aqui:";
    }

    cout << endl;

    result->printMatriz();
    
    return EXIT_SUCCESS;
}
