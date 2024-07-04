#include "Transaccion.h"
#include "NodoAVL.h"

NodoAVL::NodoAVL(Transaccion* transaccion) {
    this->transaccion = transaccion;
    this->izquierdo = izquierdo;
    this->derecho = derecho;
    this->altura = altura;
}

NodoAVL::~NodoAVL() {} // Destructor

