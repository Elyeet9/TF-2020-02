#pragma once
#include <cstdlib>
#include "CAliado.hpp"
#include "CRey.hpp"
#include "Laberinto.hpp"
using namespace System::Collections::Generic;
ref class CArregloAliados
{
    List<CAliado^>^ aliados;
    Bitmap^ imagen;
    short rey_dx, rey_dy;
    short cont;
public:
    CArregloAliados(String^ ruta, short n, short w, short h, Laberinto^ laberinto) : cont(0) {//la clase usa/depende de la clase laberinto
        aliados = gcnew List<CAliado^>;
        this->imagen = gcnew Bitmap(ruta);
        for (short i = 0; i < n; ++i) {
            System::Drawing::Rectangle area;
            do
            {
                area = System::Drawing::Rectangle(rand() % ANCHO * CAS_ANCHO, rand() % ALTO * CAS_ANCHO, CAS_ANCHO-5, CAS_ANCHO);
            } while (laberinto->colision_pared(area));
            CAliado^ new_aliado = gcnew CAliado(imagen, area, 4, 4);
            this->aliados->Add(new_aliado);
        }
    }
    ~CArregloAliados() {
        for (short i = 0; i < this->aliados->Count; ++i)
        {
            delete aliados[i];
        }
        delete aliados;
        delete imagen;
    }
    void renderizar(Graphics^ graficador, short w, short h, CRey^ rey, Laberinto^ laberinto) {
        if (rey->get_dx() != 0 || rey->get_dy() != 0) {
            rey_dx = rey->get_dx();
            rey_dy = rey->get_dy();
        }
        this->mover(graficador, w, h, rey, rey_dx, rey_dy, laberinto);
    }
    short size() { return this->aliados->Count; }
private:
    void colision_rey(CRey^ rey) {
        for (short i = 0; i < this->aliados->Count; i++)
        {
            if (this->aliados[i]->get_perseguir()) continue;
            if (this->aliados[i]->hay_colision(rey)) {
                aliados[i]->set_perseguir(true);
                cont++;
            }
        }
    }
    
    void mover(Graphics^ graficador, short w, short h, CRey^ rey, short rey_dx, short rey_dy, Laberinto^ laberinto) {
        short i;
        colision_rey(rey);
        for (i = 0; i < this->aliados->Count; ++i) {
            if (aliados[i]->get_perseguir()) {
                this->aliados[i]->mover_aliado(rey->getX() - 4 * rey_dx, rey->getY() - 5 * rey_dy);
                break;
            }
        }
        if (cont >= 2) {
            for (short j = 0; j < cont; j++)
            {

                short posX = aliados[i]->getX();
                short posY = aliados[i]->getY();
                i++;
                for (i; i < this->aliados->Count; i++)
                {
                    if (aliados[i]->get_perseguir()) {
                        this->aliados[i]->mover_aliado(posX - 4 * rey_dx, posY - 5 * rey_dy);
                        break;
                    }
                }
            }
        }
        for (i = 0; i < this->aliados->Count; i++)
        {
            aliados[i]->renderizar(graficador, w, h, laberinto);
        }
    }
};

