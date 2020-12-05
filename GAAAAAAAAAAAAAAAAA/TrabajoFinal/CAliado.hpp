#pragma once
#include "CEntidad.hpp"
#include "AEstrella.hpp"
ref class CAliado :
    public CEntidad
{
    AEstrella^ camino;
    bool perseguir;
public:
    CAliado(Bitmap^ imagen, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, Laberinto^ laberinto, short reyX, short reyY)
        : perseguir(false), CEntidad(imagen, area_dibujo, n_filas, n_columnas) {
        camino = gcnew AEstrella(laberinto, this->area_dibujo.X, this->area_dibujo.Y, reyX, reyY);
    }
    ~CAliado() {
        delete camino;
    }
    void mover_aliado(int pos_x, int pos_y) {
        //Si quieren que el aliado se mueva igual que el prota cambiar dx y dy de 5 por 10
        this->camino->hallar_camino(this->area_dibujo.X, this->area_dibujo.Y, pos_x, pos_y);
        this->dx = camino->get_new_dx(this->area_dibujo.X, 10);
        this->dy = camino->get_new_dy(this->area_dibujo.Y, 10);
    }
    void set_perseguir(bool ToF) { perseguir = ToF; }
    bool get_perseguir() { return perseguir; }
};

