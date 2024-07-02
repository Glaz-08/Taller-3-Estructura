#pragma once
#include <string>
using namespace std;

class Transaccion{
 public:
    int id;
    std::string CuentaOrigen,CuentaDestino;
    double monto;
    std::string Ubicacion,fecha,hora;
    Transaccion(int id,string CuentaOrigen,string CuentaDestino,double monto,string Ubicacion,string fecha, string hora);
    ~Transaccion();
    double getMonto();
        
};