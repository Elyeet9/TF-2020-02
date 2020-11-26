#pragma once
#include "CEntidad.hpp"
#include "CRey.hpp"
ref class CBenji :
    public CEntidad
{
    bool salvado;
    short rey_dx, rey_dy;
public:
    CBenji(String^ ruta, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas) :
        salvado(false), rey_dx(0), rey_dy(0), CEntidad(ruta, area_dibujo, n_filas, n_columnas) {}
    void set_salvado(bool ToF) { salvado = ToF; }
    bool get_salvado() { return salvado; }
    void renderizar_benji(Graphics^ graficador, CRey^ rey) {
        if(salvado) mover(rey);
        System::Drawing::Rectangle area_recorte = calc_area_recorte();
        graficador->DrawImage(imagen, area_dibujo, area_recorte, GraphicsUnit::Pixel);
    }
private:
    void mover(CRey^ rey) {
        if (salvado == true) {
            if (rey->get_dx() != 0 || rey->get_dy() != 0) {
                rey_dx = rey->get_dx();
                rey_dy = rey->get_dy();
            }
            if (rey_dy > 0) this->fila = 0;
            else if (rey_dy < 0) this->fila = 3;
            else if (rey_dx > 0) this->fila = 2;
            else if (rey_dx < 0) this->fila = 1;
            this->area_dibujo.X = rey->getX()-3;
            this->area_dibujo.Y = rey->getY() - CAS_ANCHO + 10;
        }
    }
};

