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
        bool fraude;
        Nodo(Transaccion* transaccion);
};