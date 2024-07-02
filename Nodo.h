#pragma once
#include <iostream>
#include "Transaccion.h"
using namespace std;

class Nodo 
{
    public: 
        Transaccion* transaccion;
        Nodo* izquierdo;
        Nodo* derecho;
        Nodo(Transaccion* transaccion) : transaccion(transaccion), izquierdo(nullptr), derecho(nullptr) {}
};