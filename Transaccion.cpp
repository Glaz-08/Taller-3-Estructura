#include "Transaccion.h"

Transaccion::Transaccion(int id,string CuentaOrigen,string CuentaDestino,double monto,string Ubicacion,string fecha, string hora){
    this-> id = id;
    this-> CuentaOrigen = CuentaOrigen;
    this-> CuentaDestino = CuentaDestino;
    this-> monto = monto;
    this-> Ubicacion = Ubicacion;
    this-> fecha = fecha;
    this-> hora = hora;
}
Transaccion::~Transaccion(){}//destructor

double Transaccion::getMonto(){
    return this->monto;
}



