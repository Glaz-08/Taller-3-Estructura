#include "Transaccion.h"
#include <sstream>
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
std::string Transaccion::toString() const {
    std::ostringstream oss;
    oss << "Transacción ID: " << id << "\n"
        << "Cuenta Origen: " << CuentaOrigen << "\n"
        << "Cuenta Destino: " << CuentaDestino << "\n"
        << "Monto: " << monto << "\n"
        << "Ubicación: " << Ubicacion << "\n"
        << "Fecha: " << fecha << "\n"
        << "Hora: " << hora << "\n";
    return oss.str();
}



