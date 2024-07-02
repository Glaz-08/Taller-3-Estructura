#include "Transaccion.h"
#include "NodoAVL.h"

class NodoAVL {
public:
    Transaccion* transaccion;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    NodoAVL(Transaccion* transaccion) : transaccion(transaccion), izquierdo(nullptr), derecho(nullptr), altura(1) {}
};