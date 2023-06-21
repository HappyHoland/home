#ifndef FUNCTION_H
#define FUNCTION_H
#include <array>
using std::array;

#include <string>
using std::string;

/// Representa um ponto em 2D
struct Ponto {
    int x; //!< coordenada x.
    int y; //!< coordenada y.
    /**
     * "Construtor" da struct, atribui xi e yi à x e y deste ponto.
     **/
    Ponto( int xi=0, int yi=0 ) : x{xi}, y{yi}
    {}
};

int pt_in_rect( const Ponto&, const Ponto&, const Ponto& );

bool validate_rect( const Ponto&, const Ponto&);

#endif
