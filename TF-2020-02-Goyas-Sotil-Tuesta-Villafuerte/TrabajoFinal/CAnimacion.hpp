#pragma once
#include "CImagen.hpp"
ref class CAnimacion :
    public CImagen
{
    short n_filas;
    short n_columnas;
    short n_subimagenes;
    short indice;
public:
    CAnimacion(String^ ruta, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas, short n_subimagenes)
        : CImagen(ruta, area_dibujo), n_filas(n_filas), n_columnas(n_columnas), n_subimagenes(n_subimagenes), indice(0) {}
    void dibujar(Graphics^ graficador) override {
        System::Drawing::Rectangle area_recorte = calc_area_recorte();
        graficador->DrawImage(imagen, area_dibujo, area_recorte, GraphicsUnit::Pixel);
        if (indice < n_subimagenes) ++indice;
    }
private:
    System::Drawing::Rectangle calc_area_recorte() {
        short ancho_subimagen = this->imagen->Width / this->n_columnas;
        short alto_subimagen = this->imagen->Height / this->n_filas;
        short x = this->indice * ancho_subimagen;
        short y = this->indice % n_columnas * alto_subimagen;
        return System::Drawing::Rectangle(x, y, ancho_subimagen, alto_subimagen);
    }
};

