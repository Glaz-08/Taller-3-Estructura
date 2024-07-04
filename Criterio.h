#pragma once
#include <string>
using namespace std;

class Criterio {
 public:
    int monto;
    string ubicacion;
    int horaInicio;
    int horaFin;
    Criterio(int monto, string ubicacion, int horaInicio, int horaFin);
    ~Criterio();
    int getMonto();
    string getUbicacion();
    int getHoraInicio();
    int getHoraFin();
        
};