#pragma once
#include "CImagen.hpp"
ref class CEntidad :
    public CImagen
{
    short vidas;
    short n_filas;
    short n_columnas;
    short indice;
    short fila;
public:
    CEntidad(String^ ruta, System::Drawing::Rectangle area_dibujo,short n_filas, short n_columnas, short vidas)
        : CImagen(ruta, area_dibujo), n_filas(n_filas), n_columnas(n_columnas), vidas(vidas), indice(0), fila(0) {}
    void renderizar(Graphics^ graficador) {
        this->mover();
        this->dibujar(graficador);
    }
    short get_indice() { return indice; }
protected:
    virtual void dibujar(Graphics^ graficador) override {
        System::Drawing::Rectangle area_recorte = calc_area_recorte();
        graficador->DrawImage(imagen, area_dibujo, area_recorte, GraphicsUnit::Pixel);
        if (dx != 0 || dy != 0)++indice %= n_columnas;
        else indice = 0;
    }
private:
    void mover() {
        this->area_dibujo.X += this->dx;
        this->area_dibujo.Y += this->dy;
        if (dy > 0) this->fila = 0;
        else if (dx < 0) this->fila = 1;
        else if (dx > 0) this->fila = 2;
        else if (dy < 0) this->fila = 3;
    }
    System::Drawing::Rectangle calc_area_recorte() {
        short ancho_subimagen = this->imagen->Width / this->n_columnas;
        short alto_subimagen = this->imagen->Height / this->n_filas;
        short x = this->indice * ancho_subimagen;
        short y = this->fila * alto_subimagen;
        return System::Drawing::Rectangle(x, y, ancho_subimagen, alto_subimagen);
    }
};

