#pragma once
#include <string>
using namespace std;

class Transaccion{
 public:
    int id;
    string CuentaOrigen,CuentaDestino;
    double monto;
    string Ubicacion,fecha,hora;
    Transaccion(int id,string CuentaOrigen,string CuentaDestino,double monto,string Ubicacion,string fecha, string hora);
    ~Transaccion();
    double getMonto();
    string getCuentaOrigen();
    string getCuentaDestino();
    int getId();
    string getUbicacion();
    string getFecha();
    string getHora();
    std::string toString() const;
        
};