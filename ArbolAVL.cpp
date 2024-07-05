#include "ArbolAVL.h"

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

void ArbolAVL::insertar(Transaccion* transaccion) {
    raiz = insertar(raiz, transaccion);
}

int ArbolAVL::altura(NodoAVL* N) {
    if (N == nullptr)
        return 0;
    return N->altura;
}

int ArbolAVL::max(int a, int b) {
    return (a > b) ? a : b;
}

NodoAVL* ArbolAVL::insertar(NodoAVL* nodo, Transaccion* transaccion) {
    if (nodo == nullptr)
        return new NodoAVL(transaccion);

    if (transaccion->id < nodo->transaccion->id)
        nodo->izquierdo = insertar(nodo->izquierdo, transaccion);
    else if (transaccion->id > nodo->transaccion->id)
        nodo->derecho = insertar(nodo->derecho, transaccion);
    else
        return nodo;

    nodo->altura = 1 + max(altura(nodo->izquierdo), altura(nodo->derecho));

    int balance = obtenerBalance(nodo);

    // Balanceo del arbol AVL
    if (balance > 1 && transaccion->id < nodo->izquierdo->transaccion->id)
        return rotacionDerecha(nodo);

    if (balance < -1 && transaccion->id > nodo->derecho->transaccion->id)
        return rotacionIzquierda(nodo);

    if (balance > 1 && transaccion->id > nodo->izquierdo->transaccion->id) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && transaccion->id < nodo->derecho->transaccion->id) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

int ArbolAVL::obtenerBalance(NodoAVL* N) {
    if (N == nullptr)
        return 0;
    return altura(N->izquierdo) - altura(N->derecho);
}

NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;

    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;

    return y;
}
Transaccion* ArbolAVL::buscar(int id) {
    return buscar(raiz, id);
}

Transaccion* ArbolAVL::buscar(NodoAVL* nodo, int id) {
    if (nodo == nullptr)
        return nullptr;

    if (id == nodo->transaccion->id)
        return nodo->transaccion;
    else if (id < nodo->transaccion->id)
        return buscar(nodo->izquierdo, id);
    else
        return buscar(nodo->derecho, id);
}