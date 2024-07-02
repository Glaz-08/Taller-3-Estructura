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
string Transaccion::getCuentaOrigen(){
    return this->CuentaOrigen;
}
string Transaccion::getCuentaDestino(){
    return this->CuentaOrigen;
}
int Transaccion::getId(){
    return this->id;
}
string Transaccion::getUbicacion(){
    return this->Ubicacion;
}
string Transaccion::getFecha(){
    return this->fecha;
}
string Transaccion::getHora(){
    return this->hora;
}




