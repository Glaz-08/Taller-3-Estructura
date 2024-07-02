#pragma once
#include <iostream>
#include "Nodo.h"
#include "Transaccion.h"

class ArbolABB {
public:
    Nodo* raiz;
    ArbolABB();
    void insertar(Transaccion* transaccion);

private:
    void insertar(Nodo* nodo, Transaccion* transaccion);
};
