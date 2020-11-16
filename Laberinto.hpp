#include "pch.h"
#include <vector>
#include <stdlib.h>
using namespace std;
using namespace System;

#define ALTO 36
#define ANCHO 64
#define ULTIMO this->pila->size()-1
#define CONSTANTE 2


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

class Laberinto {
    vector<Casilla*>* pila;
    int** mat;
    int visited_cells;
public:
    Laberinto() {
        this->visited_cells = 1;
        this->pila = new vector<Casilla*>;
        pila->push_back(new Casilla(1,1 ));
        mat = new int* [ALTO+1];
        for (int i = 0; i < ALTO+1; ++i) {
            mat[i] = new int[ANCHO];
        }
        for (int i = 0; i < ALTO+1; ++i) {
            for (int j = 0; j <= ANCHO; ++j) {
                mat[i][j] = 0;
            }
        }
        this->camino();
    }

    ~Laberinto() {
        for(Casilla* casilla : pila)
            delete casilla;
        delete pila;
        for(short i = 0; i < ALTO +1; ++I)
            delete[] mat[i];
        delete[] mat;
    }

    void camino() {
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
                        for (int i = 0; i < CONSTANTE+1; ++i) {
                            mat[pila->at(ULTIMO)->get_y()-i][pila->at(ULTIMO)->get_x()] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y() - CONSTANTE, pila->at(ULTIMO)->get_x()));
                        break;
                    case 1://East
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y() ][pila->at(ULTIMO)->get_x()+i] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y(), pila->at(ULTIMO)->get_x() + CONSTANTE));
                        break;
                    case 2://South
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y()+i][pila->at(ULTIMO)->get_x()] = 1;
                        }
                        pila->push_back(new Casilla(pila->at(ULTIMO)->get_y() + CONSTANTE, pila->at(ULTIMO)->get_x()));
                        break;
                    case 3://west
                        for (int i = 0; i < CONSTANTE + 1; ++i) {
                            mat[pila->at(ULTIMO)->get_y()][pila->at(ULTIMO)->get_x()-i] = 1;
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