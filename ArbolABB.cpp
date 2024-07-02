#include <iostream>
#include "Nodo.h"
#include "Transaccion.h"
#include "ArbolABB.h"

ArbolABB::ArbolABB() {
    this->raiz = nullptr;
}

void ArbolABB::insertar(Transaccion* transaccion) {
    if (raiz == nullptr) {
        raiz = new Nodo(transaccion);
    } else {
        insertar(raiz, transaccion);
    }
}

void ArbolABB::insertar(Nodo* nodo, Transaccion* transaccion) {
    if (transaccion->getMonto()< nodo->transaccion->getMonto()) {
        if (nodo->izquierdo == nullptr) {
            nodo->izquierdo = new Nodo(transaccion);
        } else {
            insertar(nodo->izquierdo, transaccion);
        }
    } else {
        if (nodo->derecho == nullptr) {
            nodo->derecho = new Nodo(transaccion);
        } else {
            insertar(nodo->derecho, transaccion);
        }
    }
}
