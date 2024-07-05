#include <iostream>
#include "Nodo.h"
#include "Transaccion.h"

Nodo::Nodo(Transaccion* transaccion) : transaccion(transaccion), izquierdo(nullptr), derecho(nullptr), fraude(false)
{
    this->transaccion = transaccion;
    this->izquierdo = izquierdo;
    this->derecho = derecho;
}