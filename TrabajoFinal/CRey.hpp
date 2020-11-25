#pragma once
#include "CEntidad.hpp"
ref class CRey :
    public CEntidad
{
    bool caminando;
    short vidas;
public:
    CRey(String^ ruta, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short vidas)
        : vidas(vidas), caminando(false), CEntidad(ruta, area_dibujo, n_filas, n_columnas) {}
    void set_caminando(bool cam) { this->caminando = cam; } 
    bool get_caminando() { return caminando; } //Verfica si el personaje está caminando 
    short get_dx(){ return dx; } //Obtener la posición de x
    short get_dy(){ return dy; } //Obtener la posición de y
    void perder_vida() { --vidas; }
    bool muerto() { return vidas == 0; }
};

