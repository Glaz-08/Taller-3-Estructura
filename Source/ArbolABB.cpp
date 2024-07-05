#include <iostream>
#include "Nodo.h"
#include "Transaccion.h"
#include "ArbolABB.h"
#include "Criterio.h"

ArbolABB::ArbolABB() {
    this->raiz = nullptr;
}
Nodo* ArbolABB::getRaiz() const {
    return raiz;
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

void ArbolABB::detectarTransaccionesSospechosas(Nodo* nodo,Criterio* criterio) {
    if (!nodo) return;

    if (nodo->transaccion->getMonto() > criterio->getMonto()) {
        cout << "Transacción sospechosa detectada: ID " << nodo->transaccion->getId() << " supera el monto límite.\n";
    }
    //tomaremos un criterio de 5 minutos para una transaccion corta
    if(nodo->izquierdo){
        string tiempo = nodo->transaccion->getHora();
        string tiempo2 = nodo->izquierdo->transaccion->getHora();
        int minutos = stoi(tiempo.substr(3));
        int minutos2 = stoi(tiempo2.substr(3));

        if(nodo->transaccion->getUbicacion()!=criterio->getUbicacion()&&abs(minutos-minutos2)<5){
            cout << "Transacción sospechosa detectada: ID " << nodo->izquierdo->transaccion->getId() << " transacción realizada en ubicación geográfica distinta en un corto periodo de tiempo.\n";
            nodo->izquierdo->fraude=true;// si es true es por que si es fraudulento
        }
        if(abs(minutos-minutos2)<5){
            cout << "Transacción sospechosa detectada: ID " << nodo->izquierdo->transaccion->getId() << " supera el tiempo minimo de espera.\n";
            nodo->izquierdo->fraude=true;
        }
    }
    if(nodo->derecho){
        string tiempo = nodo->transaccion->getHora();
        string tiempo2 = nodo->derecho->transaccion->getHora();
        int minutos = stoi(tiempo.substr(3));
        int minutos2 = stoi(tiempo2.substr(3));

        if(nodo->transaccion->getUbicacion()!=criterio->getUbicacion()&&abs(minutos-minutos2)<5){
            cout << "Transacción sospechosa detectada: ID " << nodo->derecho->transaccion->getId() << " transacción realizada en ubicación geográfica distinta en un corto periodo de tiempo.\n";
            nodo->derecho->fraude=true;
        }
        if(abs(minutos-minutos2)<5){
            cout << "Transacción sospechosa detectada: ID " << nodo->derecho->transaccion->getId() << " supera el tiempo minimo de espera.\n";
            nodo->derecho->fraude=true;
        }
    }

    detectarTransaccionesSospechosas(nodo->izquierdo,criterio);
    detectarTransaccionesSospechosas(nodo->derecho, criterio);
}   
void ArbolABB::detectarTransaccionesSospechosas(Criterio* criterio) {
    detectarTransaccionesSospechosas(raiz, criterio);
}

void ArbolABB::generarReporte(Nodo* nodo) {
    if (!nodo) return;
    if(!nodo->fraude){
        cout << "Transacción ID: " << nodo->transaccion->getId() << "\n";
        cout << "Cuenta Origen: " << nodo->transaccion->getCuentaOrigen() << "\n";
        cout << "Cuenta Destino: " << nodo->transaccion->getCuentaDestino() << "\n";
        cout << "Monto: " << nodo->transaccion->getMonto() << "\n";
        cout << "Ubicación: " << nodo->transaccion->getUbicacion() << "\n";
        cout << "Fecha: " << nodo->transaccion->getFecha() << "\n";
        cout << "Hora: " << nodo->transaccion->getHora() << "\n";
        cout << "-------------------------\n";
    }
    generarReporte(nodo->izquierdo);
    generarReporte(nodo->derecho);
}

void ArbolABB::generarReporte() {
    cout << "-------------------------\n";
    cout << "Transacciones NO FRAUDULENTAS" << "\n";
    generarReporte(raiz);
    cout << "Transacciones FRAUDULENTAS" << "\n";
    generarReportesFraudulentos(raiz);
}
void ArbolABB::generarReportesFraudulentos(Nodo* nodo) {
    if (!nodo) return;
    if(nodo->fraude){
        cout << "Transacción ID: " << nodo->transaccion->getId() << "\n";
        cout << "Cuenta Origen: " << nodo->transaccion->getCuentaOrigen() << "\n";
        cout << "Cuenta Destino: " << nodo->transaccion->getCuentaDestino() << "\n";
        cout << "Monto: " << nodo->transaccion->getMonto() << "\n";
        cout << "Ubicación: " << nodo->transaccion->getUbicacion() << "\n";
        cout << "Fecha: " << nodo->transaccion->getFecha() << "\n";
        cout << "Hora: " << nodo->transaccion->getHora() << "\n";
        cout << "-------------------------\n";
    }
    generarReportesFraudulentos(nodo->izquierdo);
    generarReportesFraudulentos(nodo->derecho);
}
