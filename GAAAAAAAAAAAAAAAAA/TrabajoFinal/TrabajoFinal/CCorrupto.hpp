#pragma once
#include "CEntidad.hpp"
#include "Laberinto.hpp"
#include "AEstrella.hpp"
ref class CCorrupto :
    public CEntidad
{
    AEstrella^ camino;
    short velocidad;
    short cooldown;
public:
    CCorrupto(Bitmap^ imagen, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short reyX, short reyY, short velocidad, Laberinto^ laberinto)
        : cooldown(0), velocidad(velocidad), CEntidad(imagen, area_dibujo, n_filas, n_columnas) {
        camino = gcnew AEstrella(laberinto, this->area_dibujo.X, this->area_dibujo.Y, reyX, reyY);
    }

    void actualizar_camino(short reyX, short reyY) {
        this->camino->hallar_camino(this->area_dibujo.X, this->area_dibujo.Y, reyX, reyY);
        this->dx = camino->get_new_dx(this->area_dibujo.X, this->velocidad);
        this->dy = camino->get_new_dy(this->area_dibujo.Y, this->velocidad);
    }
    void parar() {
        this->dx = 0;
        this->dy = 0;
    }
    void add_cooldown() { ++cooldown; }
    void set_cooldown(short new_cooldown) { this->cooldown = new_cooldown; }
    short get_cooldown() { return cooldown; }
    short get_velocidad() { return velocidad; }
};

