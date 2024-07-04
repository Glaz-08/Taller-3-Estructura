#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "Nodo.h"
#include "Transaccion.h"
#include "ArbolABB.h"

void menu(ArbolABB& arbolABB, ArbolAVL& arbolAVL) {
    int opcion;
    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Insertar nueva transacción\n";
        std::cout << "2. Mostrar transacciones sospechosas\n";
        std::cout << "3. Generar reporte de actividad\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese la opción deseada: ";
        std::cin >> opcion;
        int id;
        std::string cuentaOrigen, cuentaDestino, ubicacion, fecha, hora;
        double monto;
        switch (opcion) {
            case 1: {
                std::cout << "Ingrese ID: ";
                std::cin >> id;
                std::cout << "Ingrese Cuenta Origen: ";
                std::cin >> cuentaOrigen;
                std::cout << "Ingrese Cuenta Destino: ";
                std::cin >> cuentaDestino;
                std::cout << "Ingrese Monto: ";
                std::cin >> monto;
                std::cout << "Ingrese Ubicación: ";
                std::cin >> ubicacion;
                std::cout << "Ingrese Fecha: ";
                std::cin >> fecha;
                std::cout << "Ingrese Hora: ";
                std::cin >> hora;
                Transaccion* transaccion = new Transaccion(id, cuentaOrigen, cuentaDestino, monto, ubicacion, fecha, hora);
                arbol.insertar(transaccion);
                std::cout << "Transacción nueva realizada!!\n";
                break;
            }
            case 2: {
                double montoLimite;
                std::string ubicacion1, ubicacion2;
                std::cout << "Ingrese monto límite para detectar transacciones sospechosas: ";
                std::cin >> montoLimite;
                std::cout << "Ingrese primera ubicación para detección: ";
                std::cin >> ubicacion1;
                std::cout << "Ingrese segunda ubicación para detección: ";
                std::cin >> ubicacion2;
                arbol.detectarTransaccionesSospechosas(montoLimite, ubicacion1, ubicacion2);
                break;
            }
            case 3:
                arbol.generarReporte();
                break;
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
                break;
        }
    } while (opcion != 4);
}

std::vector<std::string> split(const std::string& linea, char delimitador) {
    std::vector<std::string> partes;
    std::string parte;
    std::istringstream ss(linea);
    while (std::getline(ss, parte, delimitador)) {
        partes.push_back(parte);
    }
    return partes;
}

void leerTransacciones(ArbolABB& arbol) {
    std::string linea;
    std::ifstream archivo("Transacciones.txt");
    char delimitador = ',';
    while (std::getline(archivo, linea)) {
        std::vector<std::string> partes = split(linea, delimitador);
        if (partes.size() >= 5) {
            int id = std::stoi(partes[0]);
            std::string cuentaOrigen = partes[1];
            std::string cuentaDestino = partes[2];
            double monto = std::stoi(partes[3]);
            std::string ubicacion = partes[4];
            std::string fecha = partes[5];
            std::string hora = partes[6];
            Transaccion* transaccionJ = new Transaccion(id, cuentaOrigen, cuentaDestino, monto, ubicacion, fecha, hora);
            arbol.insertar(transaccionJ);
        } else {
            std::cout << "Error: Datos incompletos en la línea del archivo de productos." << std::endl;
        }
    }
    archivo.close();
}

int main() {
    ArbolABB arbolABB;
    ArbolAVL arbolAVL;
    leerTransacciones(arbolABB);
    menu(arbolABB,arbolAVL);

    return 0;
}
