#pragma once
#include <cstdlib>
#include "CAliado.hpp"
#include "CRey.hpp"
#include "CCorrupto.hpp"
#include "Laberinto.hpp"
using namespace System::Collections::Generic;
ref class CArregloAliados
{
    List<CAliado^>^ aliados;
    Bitmap^ imagen;
    short rey_dx, rey_dy;
    short cont;
public:
    CArregloAliados(String^ ruta, short n, short w, short h, Laberinto^ laberinto) : cont(2) {//la clase usa/depende de la clase laberinto
        aliados = gcnew List<CAliado^>;
        this->imagen = gcnew Bitmap(ruta);
        System::Drawing::Rectangle area = System::Drawing::Rectangle(CAS_ANCHO, CAS_ANCHO, CAS_ANCHO - 5, CAS_ANCHO);
        this->aliados->Add(gcnew CAliado(imagen, area, 4, 4));
        this->aliados->Add(gcnew CAliado(imagen, area, 4, 4));
        this->aliados[0]->set_perseguir(true);
        this->aliados[1]->set_perseguir(true);
        for (short i = 2; i < n; ++i) {
            do
            {
                area = System::Drawing::Rectangle(rand() % ANCHO * CAS_ANCHO, rand() % ALTO * CAS_ANCHO, CAS_ANCHO-5, CAS_ANCHO);
            } while (laberinto->colision_pared(area) || (area.X > w / 2 && area.Y > h / 2));
            this->aliados->Add(gcnew CAliado(imagen, area, 4, 4));
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
        if (aliados != nullptr) {
            if (rey->get_dx() != 0 || rey->get_dy() != 0) {
                rey_dx = rey->get_dx();
                rey_dy = rey->get_dy();
            }
            this->mover(graficador, w, h, rey, rey_dx, rey_dy);
            for (short i = 0; i < this->aliados->Count; i++)
            {
                aliados[i]->renderizar(graficador, w, h, laberinto);
            }
        }
    }
    short size() { return this->aliados->Count; }
    bool colision_corrupt(CCorrupto^ corrupto) {
        for (short i = 0; i < this->aliados->Count; i++)
        {
            if (this->aliados[i]->hay_colision(corrupto)) {
                if(this->aliados[i]->get_perseguir()) cont--;
                aliados->RemoveAt(i);
                return true;
            }
        }
        return false;
    }
    void tp_aliados(short new_X, short new_Y) {
        for (short i = 0; i < this->aliados->Count; i++)
        {
            if (aliados[i]->get_perseguir())
                this->aliados[i]->tp(new_X, new_Y);
        }
    }
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
    
    void mover(Graphics^ graficador, short w, short h, CRey^ rey, short rey_dx, short rey_dy) {
        short i;
        colision_rey(rey);
        for (i = 0; i < this->aliados->Count; ++i) {
            if (aliados[i]->get_perseguir()) {
                this->aliados[i]->mover_aliado(rey->getX() - 2 * rey_dx, rey->getY() - 3 * rey_dy);
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
                        this->aliados[i]->mover_aliado(posX - 2 * rey_dx, posY - 3 * rey_dy);
                        break;
                    }
                }
            }
        }

    }
};

