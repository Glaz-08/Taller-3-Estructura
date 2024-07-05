#include "Criterio.h"

Criterio::Criterio(int monto, string ubicacion, int horaInicio, int horaFin){
    this-> monto = monto;
    this-> ubicacion = ubicacion;
    this-> horaInicio = horaInicio;
    this-> horaFin = horaFin;
}

Criterio::~Criterio(){}//destructor

int Criterio::getMonto(){
    return this->monto;
}

string Criterio::getUbicacion(){
    return this->ubicacion;
}