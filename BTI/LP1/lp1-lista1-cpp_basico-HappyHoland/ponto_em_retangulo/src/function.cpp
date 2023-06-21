#include "function.h"

/*! 
 * Verifica se um ponto está dentro de um retângulo.
 */
int pt_in_rect( const Ponto &IE, const Ponto &SD, const Ponto &P )
{
    if ((P.x > IE.x && P.x < SD.x) && (P.y > IE.y && P.y < SD.y)) {return 0;}
    else if ((P.x >= IE.x && P.x <= SD.x) && (P.y == IE.y || P.y == SD.y)) {return 1;} 
    else if ((P.y >= IE.y && P.y <= SD.y) && (P.x == IE.x || P.x == SD.x)) {return 1;}
    else {return -1;}
}

bool validate_rect( const Ponto& A, const Ponto& B){
    if (A.x != B.x && A.y != B.y) {return true;}
    else {return false;}
}
