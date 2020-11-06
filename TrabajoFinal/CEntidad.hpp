#pragma once
#include "CImagen.hpp"
ref class CEntidad :
    public CImagen
{
protected:
    short vidas; 
    short n_filas;
    short n_columnas;
    short indice;
    short fila;
public:
    CEntidad(String^ ruta, System::Drawing::Rectangle area_dibujo,short n_filas, short n_columnas, short vidas)
        : CImagen(ruta, area_dibujo), n_filas(n_filas), n_columnas(n_columnas), vidas(vidas), indice(0), fila(0) {}
    CEntidad(Bitmap^ imagen, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short vidas)
        : CImagen(imagen, area_dibujo), n_filas(n_filas), n_columnas(n_columnas), vidas(vidas), indice(0), fila(0) {}
    bool perder_vida() {
        return --vidas == 0;
    }
protected:
    void dibujar(Graphics^ graficador) override {
        System::Drawing::Rectangle area_recorte = calc_area_recorte();
        if (dx < 0) this->fila = 1;
        else if (dx > 0) this->fila = 2;
        else if (dy > 0) this->fila = 0;
        else if (dy < 0) this->fila = 3;
        graficador->DrawImage(imagen, area_dibujo, area_recorte, GraphicsUnit::Pixel);
        if (dx != 0 || dy != 0) ++indice %= n_columnas;
        else indice = 0;
    }
    System::Drawing::Rectangle calc_area_recorte() {
        short ancho_subimagen = this->imagen->Width / this->n_columnas;
        short alto_subimagen = this->imagen->Height / this->n_filas;
        short x = this->indice * ancho_subimagen;
        short y = this->fila * alto_subimagen;
        return System::Drawing::Rectangle(x, y, ancho_subimagen, alto_subimagen);
    }
};
