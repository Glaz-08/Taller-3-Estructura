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

void ArbolABB::insertar(Nodo*& nodo, Transaccion* transaccion) {
    if (transaccion->getMonto() < nodo->transaccion->getMonto()) {
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

void ArbolABB::detectarTransaccionesSospechosas(Nodo* nodo, double montoLimite, const std::string& ubicacion1, const std::string& ubicacion2, std::unordered_map<std::string, int>& cuentaTransacciones) {
    if (!nodo) return;

    if (nodo->transaccion->getMonto() > montoLimite) {
        std::cout << "Transacción sospechosa detectada: ID " << nodo->transaccion->getId() << " supera el monto límite.\n";
    }

    cuentaTransacciones[nodo->transaccion->getUbicacion()]++;

    detectarTransaccionesSospechosas(nodo->izquierdo, montoLimite, ubicacion1, ubicacion2, cuentaTransacciones);
    detectarTransaccionesSospechosas(nodo->derecho, montoLimite, ubicacion1, ubicacion2, cuentaTransacciones);
}

void ArbolABB::detectarTransaccionesSospechosas(double montoLimite, const std::string& ubicacion1, const std::string& ubicacion2) {
    std::unordered_map<std::string, int> cuentaTransacciones;
    detectarTransaccionesSospechosas(raiz, montoLimite, ubicacion1, ubicacion2, cuentaTransacciones);

    if (cuentaTransacciones[ubicacion1] > 1 && cuentaTransacciones[ubicacion2] > 1) {
        std::cout << "Transacciones sospechosas detectadas entre ubicaciones " << ubicacion1 << " y " << ubicacion2 << ".\n";
    }
}

void ArbolABB::generarReporte(Nodo* nodo) {
    if (!nodo) return;

    std::cout << "Transacción ID: " << nodo->transaccion->getId() << "\n";
    std::cout << "Cuenta Origen: " << nodo->transaccion->getCuentaOrigen() << "\n";
    std::cout << "Cuenta Destino: " << nodo->transaccion->getCuentaDestino() << "\n";
    std::cout << "Monto: " << nodo->transaccion->getMonto() << "\n";
    std::cout << "Ubicación: " << nodo->transaccion->getUbicacion() << "\n";
    std::cout << "Fecha: " << nodo->transaccion->getFecha() << "\n";
    std::cout << "Hora: " << nodo->transaccion->getHora() << "\n";
    std::cout << "-------------------------\n";

    generarReporte(nodo->izquierdo);
    generarReporte(nodo->derecho);
}

void ArbolABB::generarReporte() {
    generarReporte(raiz);
}
    
