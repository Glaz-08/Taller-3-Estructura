#pragma once
#include <iostream>
#include <unordered_map>
#include "Nodo.h"
#include "Transaccion.h"
#include "Criterio.h"

class ArbolABB {
public:
    Nodo* raiz;

    ArbolABB();
    void insertar(Transaccion* transaccion);
    void generarReporte();
    void generarReportesFraudulentos();
    Nodo* getRaiz() const;
    void detectarTransaccionesSospechosas(Criterio* criterio);

private:
    void insertar(Nodo*& nodo, Transaccion* transaccion); // Cambiado el paso de argumentos por referencia
    void detectarTransaccionesSospechosas(Nodo* nodo,Criterio* criterio);
    void generarReporte(Nodo* nodo);
    void generarReportesFraudulentos(Nodo* nodo);

    // Funciones de balanceo AVL
    int altura(Nodo* N);
    int obtenerBalance(Nodo* N);
    Nodo* rotacionDerecha(Nodo* y);
    Nodo* rotacionIzquierda(Nodo* x);
};

