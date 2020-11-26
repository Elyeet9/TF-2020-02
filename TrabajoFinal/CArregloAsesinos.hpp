#pragma once
#include <cstdlib>
#include "CCorrupto.hpp"
#include "CRey.hpp"
#include "Vida.hpp"
#include "Laberinto.hpp"
ref class CArregloAsesinos
{
    List<CCorrupto^>^ asesinos;
    Bitmap^ imagen;
public:
    CArregloAsesinos(String^ ruta, short n, short w, short h, Laberinto^ laberinto, short reyX, short reyY, short velocidad) {//la clase usa/depende de la clase laberinto
        asesinos = gcnew List<CCorrupto^>;
        this->imagen = gcnew Bitmap(ruta);
        for (short i = 0; i < n; ++i) {
            System::Drawing::Rectangle area;
            do
            {
                area = System::Drawing::Rectangle(rand() % ANCHO * CAS_ANCHO, rand() % ALTO * CAS_ANCHO, CAS_ANCHO - 10, CAS_ANCHO);
            } while (area.X < w / 2 || area.Y < h / 2 || laberinto->colision_pared(area));
            CCorrupto^ new_corrupto = gcnew CCorrupto(imagen, area, 4, 4, reyX, reyY, velocidad, laberinto);
            this->asesinos->Add(new_corrupto);
        }
    }
    ~CArregloAsesinos() {
        for (short i = 0; i < this->asesinos->Count; ++i)
        {
            delete asesinos[i];
        }
        delete asesinos;
        delete imagen;
    }
     short colision_rectangle(System::Drawing::Rectangle area) {
        short aux = 0;
        for (short i = 0; i < this->asesinos->Count; i++)
        {
            if (this->asesinos[i]->hay_colision(area))aux++;
        }
        return aux;
    }
    void renderizar(Graphics^ graficador, short w, short h, Laberinto^ laberinto, CRey^ rey, Vida^ vidas) {
        if (asesinos != nullptr) {
            for (short i = 0; i < this->asesinos->Count; i++)
            {
                this->asesinos[i]->renderizar(graficador, w, h, laberinto);
                if (asesinos[i]->hay_colision(rey)) {
                    rey->perder_vida();
                    vidas->perder_vida();
                    this->asesinos->RemoveAt(i);
                    --i;
                    continue;
                }
                this->asesinos[i]->actualizar_camino(rey->getX(), rey->getY());
            }
        }
    }
};

