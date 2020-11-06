#pragma once
#include "CEntidad.hpp"

ref class CAliado :
    public CEntidad
{
    bool impostor;
    bool perseguir;
public:
    CAliado(String^ ruta, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short vidas)
        : impostor(false), perseguir(false), CEntidad(ruta, area_dibujo, n_filas, n_columnas, vidas) {}
    CAliado(Bitmap^ imagen, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short vidas)
        : impostor(false), perseguir(false), CEntidad(imagen, area_dibujo, n_filas, n_columnas, vidas) {}
    void mover_aliado(int pos_x, int pos_y) {
        //Si quieren que el aliado se mueva igual que el prota cambiar dx y dy de 5 por 10
        if (area_dibujo.X == pos_x)     { this->dx = 0; }
        else if (area_dibujo.X > pos_x) { this->dx = -5; }
        else if (area_dibujo.X < pos_x) { this->dx = 5; }

        if (area_dibujo.Y == pos_y)     { this->dy = 0; }
        else if (area_dibujo.Y > pos_y) { this->dy = -5; }
        else if (area_dibujo.Y < pos_y) { this->dy = 5; }
    }
    void set_perseguir(bool ToF) { perseguir = ToF; }
    bool get_perseguir() { return perseguir; }
};

