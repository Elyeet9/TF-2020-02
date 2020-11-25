#pragma once
#include "CImagen.hpp"
#include "Laberinto.hpp"
ref class CEntidad :
    public CImagen//hereda publicamente de la clase CImagen
{
protected:
    short n_filas;
    short n_columnas;
    short indice;
    short fila;
public:
    CEntidad(String^ ruta, System::Drawing::Rectangle area_dibujo,short n_filas, short n_columnas)
        : CImagen(ruta, area_dibujo), n_filas(n_filas), n_columnas(n_columnas), indice(0), fila(0) {}
    CEntidad(Bitmap^ imagen, System::Drawing::Rectangle area_dibujo, short n_filas, short n_columnas)
        : CImagen(imagen, area_dibujo), n_filas(n_filas), n_columnas(n_columnas), indice(0), fila(0) {}
    void renderizar(Graphics^ graficador, short w, short h, Laberinto^ laberinto) {
        this->dibujar(graficador);
        this->mover(w, h, laberinto);
    }

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
protected:
    void mover(short w, short h, Laberinto^ laberinto) {
        if (dx != 0 || dy != 0) {
            System::Drawing::Rectangle hitbox = System::Drawing::Rectangle(area_dibujo.X, area_dibujo.Y + (area_dibujo.Height / 2), area_dibujo.Width, area_dibujo.Height/2);
            
            bool colision_x = false;
            bool colision_y = false;
            System::Drawing::Rectangle hitbox_dx = System::Drawing::Rectangle(hitbox.X + dx, hitbox.Y, hitbox.Width, hitbox.Height);
            System::Drawing::Rectangle hitbox_dy = System::Drawing::Rectangle(hitbox.X, hitbox.Y + dy, hitbox.Width, hitbox.Height);

            if (laberinto->colision_pared(hitbox_dx)) colision_x = true;
            else colision_x = false;

            if (laberinto->colision_pared(hitbox_dy)) colision_y = true;
            else colision_y = false;

            //colision con los bordes
            if (hitbox.X + dx >= 0 && hitbox.X + dx + hitbox.Width  <= w && !colision_x)
                this->area_dibujo.X += dx;
            else this->dx = 0;

            if (hitbox.Y + dy >= 0 && hitbox.Y + dy + hitbox.Height <= h && !colision_y)
                this->area_dibujo.Y += dy;
            else this->dy = 0;
        }
    }
    System::Drawing::Rectangle calc_area_recorte() {
        short ancho_subimagen = this->imagen->Width / this->n_columnas;
        short alto_subimagen = this->imagen->Height / this->n_filas;
        short x = this->indice * ancho_subimagen;
        short y = this->fila * alto_subimagen;
        return System::Drawing::Rectangle(x, y, ancho_subimagen, alto_subimagen);
    }
};
