#pragma once
#include <iostream>
#include <unordered_map>
#include "Nodo.h"
#include "Transaccion.h"

class ArbolABB {
public:
    Nodo* raiz;

    ArbolABB();

    void insertar(Transaccion* transaccion);
    void detectarTransaccionesSospechosas(double montoLimite, const std::string& ubicacion1, const std::string& ubicacion2);
    void generarReporte();

private:
    void insertar(Nodo& nodo, Transaccion transaccion);
    void detectarTransaccionesSospechosas(Nodo* nodo, double montoLimite, const std::string& ubicacion1, const std::string& ubicacion2, std::unordered_map<std::string, int>& cuentaTransacciones);
    void generarReporte(Nodo* nodo);

    // Funciones de balanceo AVL
    int altura(Nodo* N);
    int obtenerBalance(Nodo* N);
    Nodo* rotacionDerecha(Nodo* y);
    Nodo* rotacionIzquierda(Nodo* x);
    Nodo* insertarAVL(Nodo* nodo, Transaccion* transaccion);
};
