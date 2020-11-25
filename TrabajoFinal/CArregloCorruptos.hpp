#pragma once
#include <cstdlib>
#include "CCorrupto.hpp"
#include "CRey.hpp"
#include "Vida.hpp"
#include "Laberinto.hpp"
using namespace System::Collections::Generic;

ref class CArregloCorruptos
{
	List<CCorrupto^>^ corruptos;
    Bitmap^ imagen;
public:
    CArregloCorruptos(String^ ruta, short n, short w, short h, Laberinto^ laberinto, short reyX, short reyY, short velocidad) {//la clase usa/depende de la clase laberinto
        corruptos = gcnew List<CCorrupto^>;
        this->imagen = gcnew Bitmap(ruta);
        for (short i = 0; i < n; ++i) {
            System::Drawing::Rectangle area;
            do
            {
                area = System::Drawing::Rectangle(rand() % ANCHO * CAS_ANCHO, rand() % ALTO * CAS_ANCHO, CAS_ANCHO - 5, CAS_ANCHO);
            } while (area.X<w/2||area.Y<h/2||laberinto->colision_pared(area));
            CCorrupto^ new_corrupto = gcnew CCorrupto(imagen, area, 4, 4, reyX, reyY, velocidad, laberinto);
            this->corruptos->Add(new_corrupto);
        }
    }
    ~CArregloCorruptos() {
        for (short i = 0; i < this->corruptos->Count; ++i)
        {
            delete corruptos[i];
        }
        delete corruptos;
        delete imagen;
    }
    void renderizar(Graphics^ graficador, short w, short h, Laberinto^ laberinto, CRey^ rey, Vida^ vidas) {
        for (short i = 0; i < this->corruptos->Count; i++)
        {
            this->corruptos[i]->actualizar_camino(rey->getX(), rey->getY());
            this->corruptos[i]->renderizar(graficador, w, h, laberinto);
            if (corruptos[i]->hay_colision(rey)) {
                rey->perder_vida();
                vidas->perder_vida();
                this->corruptos->RemoveAt(i);
                --i;
                continue;
            }
        }
    }
};

