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


// Función para mostrar el menú y manejar la interacción con el usuario
void menu(ArbolABB& arbol) {
    int opcion;
    do {
        std::cout << "\n--- Menú Principal ---\n";
        std::cout << "1. Leer transacciones desde archivo\n";
        std::cout << "2. Insertar nueva transacción\n";
        std::cout << "3. Mostrar transacciones sospechosas\n";
        std::cout << "4. Generar reporte de actividad\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese la opción deseada: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                leerTransacciones(arbol);
                break;
            case 2:
                //insertar una nueva transacción
                break;
            case 3:
                //mostrar transacciones sospechosas
                break;
            case 4:
                //reporte de actividad
                break;
            case 5:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Por favor, ingrese una opción válida.\n";
                break;
        }
    } while (opcion != 5);
}

// Función para dividir una cadena en partes basadas en un delimitador por que el split me estaba dando errores y lo tuve que hacer asi
std::vector<std::string> split(const std::string& linea, char delimitador) {
    std::vector<std::string> partes;
    std::string parte;
    std::istringstream ss(linea);
    while (std::getline(ss, parte, delimitador)) {
        partes.push_back(parte);
    }
    return partes;
}
//lectura del archivo que crea el objeto transacciones y lo coloca en el arbol
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
            Transaccion* transaccionJ = new Transaccion(id,cuentaOrigen,cuentaDestino,monto,ubicacion,fecha,hora);
            arbol.insertar(transaccionJ);
            // Aquí puedes hacer lo que necesites con los datos leídos
        } else {
            std::cout << "Error: Datos incompletos en la línea del archivo de productos." << std::endl;
        }
    }
    archivo.close();
}

// Función principal
int main() {
    ArbolABB arbol;
    //falta leer el archivo y cargarlos al arbol
    leerTransacciones(arbol);
    menu(arbol);

    return 0;
}