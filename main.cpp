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
void leerTransacciones(){
    string linea;
    ifstream archivo("Transacciones.txt");
    char delimitador = ',';
    while (getline(archivo, linea)) {

    }

}

// Función principal
int main() {
    ArbolABB arbol;
    //falta leer el archivo y cargarlos al arbol
    leerTransacciones();

    return 0;
}