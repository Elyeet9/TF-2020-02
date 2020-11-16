#pragma once
#include "pch.h"
#include <vector>
#include "CImagen.hpp"
using namespace std;
using namespace System;
using namespace System::Collections::Generic;

#define ALTO 24
#define ANCHO 40
#define ULTIMO this->pila->size()-1
#define CONSTANTE 2
#define CAS_ANCHO 40

class Casilla {
    short x, y;
public:
    Casilla() {}
    Casilla(short y, short x) : x(x), y(y) {}
    ~Casilla() {}
    //getters
    short get_y() { return y; }
    short get_x() { return x; }
};

ref class Laberinto {
    vector<Casilla*>* pila;//la clase se compone de una lista de casillas
    int** mat;
    int visited_cells;
    List<CImagen^>^ paredes;//la clase se compone de una lista de imagenes
    Bitmap^ img_pared;
    Bitmap^ img_suelo;
public:
    Laberinto() {
        this->paredes = gcnew List<CImagen^>;
        this->img_pared = gcnew Bitmap("img\\pared.png");
        this->img_suelo= gcnew Bitmap("img\\suelo.png");

        this->visited_cells = 1;
        this->pila = new vector<Casilla*>;
        this->pila->push_back(new Casilla(1, 1));
        this->mat = new int* [ALTO + 1];

        for (int i = 0; i < ALTO + 1; ++i)
            this->mat[i] = new int[ANCHO];

        for (short i = 0; i < ALTO + 1; ++i) {
            for (short j = 0; j <= ANCHO; ++j)
                mat[i][j] = 0;
        }
        this->generar_camino();

        for (short i = 0; i < ALTO + 1; i++) {
            for (short j = 0; j < ANCHO+1; j++) {
                if (mat[i][j] == 0)
                    paredes->Add(gcnew CImagen(img_pared, System::Drawing::Rectangle(j * CAS_ANCHO, i * CAS_ANCHO, CAS_ANCHO, CAS_ANCHO)));
            }
        }
    }

    ~Laberinto() {
        for (Casilla* casilla : *pila)
            delete casilla;
        delete pila;
        for (short i = 0; i < ALTO + 1; ++i)
            delete[] mat[i];
        delete[] mat;

        for (short i = 0; i < paredes->Count; ++i)
            delete paredes[i];

        delete paredes, img_pared, img_suelo;
    }

    void renderizar(Graphics^ graficador, short w, short h) {
        graficador->DrawImage(img_suelo, System::Drawing::Rectangle(0, 0, w, h));
        //graficar el arreglo de paredes
        for (short i = 0; i < paredes->Count; i++)
            paredes[i]->dibujar(graficador);
    }
    
    bool colision_pared(System::Drawing::Rectangle otro) {
        for (short i = 0; i < paredes->Count; ++i) {
            if (paredes[i]->hay_colision(otro)) return true;
        }
        return false;
    }

private:
    void generar_camino() {
        while (visited_cells < ANCHO / CONSTANTE * ALTO / CONSTANTE) {
            if (visited_cells < ANCHO / CONSTANTE * ALTO / CONSTANTE) {

                vector<int> neighbours;

                //north neighbor
                if (pila->at(ULTIMO)->get_y() > 0 && pila->at(ULTIMO)->get_y() - CONSTANTE > 0
                    && mat[pila->at(ULTIMO)->get_y() - CONSTANTE][pila->at(ULTIMO)->get_x()] != 1) {
                    neighbours.push_back(0);
                }
                //east neighbor
                if (pila->at(ULTIMO)->get_x() < ANCHO && pila->at(ULTIMO)->get_x() + CONSTANTE < ANCHO
                    && mat[pila->at(ULTIMO)->get_y()][pila->at(ULTIMO)->get_x() + CONSTANTE] != 1) {
                    neighbours.push_back(1);
                }//south neighbor
                if (pila->at(ULTIMO)->get_y() < ALTO && pila->at(ULTIMO)->get_y() + CONSTANTE < ALTO
                    && mat[pila->at(ULTIMO)->get_y() + CONSTANTE][pila->at(ULTIMO)->get_x()] != 1) {
                    neighbours.push_back(2);
                }//west neighbor
                if (pila->at(ULTIMO)->get_x() > 0 && pila->at(ULTIMO)->get_x() - CONSTANTE > 0
                    && mat[pila->at(ULTIMO)->get_y()][pila->at(ULTIMO)->get_x() - CONSTANTE] != 1) {
                    neighbours.push_back(3);
                }

                //where are the neighbours 
                if (!neighbours.empty()) {

                    //choose one rand

                    int next_cell_dir = neighbours[rand() % neighbours.size()];

                    //creating path 
                    switch (next_cell_dir)
                    {
                    case 0://north
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y() - i][pila->at(ULTIMO)->get_x()] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y() - CONSTANTE, pila->at(ULTIMO)->get_x()));
                        break;
                    case 1://East
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y()][pila->at(ULTIMO)->get_x() + i] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y(), pila->at(ULTIMO)->get_x() + CONSTANTE));
                        break;
                    case 2://South
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y() + i][pila->at(ULTIMO)->get_x()] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y() + CONSTANTE, pila->at(ULTIMO)->get_x()));
                        break;
                    case 3://west
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y()][pila->at(ULTIMO)->get_x() - i] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y(), pila->at(ULTIMO)->get_x() - CONSTANTE));
                        break;

                    }
                    this->visited_cells++;
                }
                else {
                    //no available neighbours so backtrack
                    this->pila->pop_back();
                }
            }

        }
    }

};