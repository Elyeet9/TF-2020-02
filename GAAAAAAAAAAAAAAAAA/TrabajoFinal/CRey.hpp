#pragma once
#include "CEntidad.hpp"
ref class CRey :
    public CEntidad
{
    short vidas;
public:
    CRey(String^ ruta, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short vidas)
        : vidas(vidas), CEntidad(ruta, area_dibujo, n_filas, n_columnas) {}
    short get_dx(){ return dx; } //Obtener la posición de x
    short get_dy(){ return dy; } //Obtener la posición de y
    void perder_vida() { --vidas; }
    bool muerto() { return vidas <= 0; }
};

