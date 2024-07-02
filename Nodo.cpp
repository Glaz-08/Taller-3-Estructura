#include <iostream>
#include "Nodo.h"
#include "Transaccion.h"

Nodo::Nodo(Transaccion* transaccion) : transaccion(transaccion), izquierdo(nullptr), derecho(nullptr)
{
    this->transaccion = transaccion;
    this->izquierdo = izquierdo;
    this->derecho = derecho;
}