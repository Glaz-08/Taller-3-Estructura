#pragma once
#include "NodoAVL.h"
#include "Transaccion.h"

class ArbolAVL {
public:
    NodoAVL* raiz;

    ArbolAVL();

    void insertar(Transaccion* transaccion);

private:
    int altura(NodoAVL* N);
    int max(int a, int b);
    NodoAVL* insertar(NodoAVL* nodo, Transaccion* transaccion);
    int obtenerBalance(NodoAVL* N);
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
};
