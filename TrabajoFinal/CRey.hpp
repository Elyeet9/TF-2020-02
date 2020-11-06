#pragma once
#include "CEntidad.hpp"
ref class CRey :
    public CEntidad
{
public:
    CRey(String^ ruta, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short vidas)
        : CEntidad(ruta, area_dibujo, n_filas, n_columnas, vidas) {}
    short get_dx(){ return dx; }
    short get_dy(){ return dy; }
};

