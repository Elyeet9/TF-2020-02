#pragma once
#include "Laberinto.hpp"
#include <list>
#define INFINITO ((float)(_HUGE_ENUF * _HUGE_ENUF))

struct aNodo {
	bool Pared = false;
	bool Visitado = false;
	float MetaGlobal;
	float MetaLocal;
	int x, y;
	vector<aNodo*> vecinos;
	aNodo* padre;
};

class AEstrella
{
	aNodo* nodos = nullptr;
	short ancho = ANCHO + 1;
	short alto = ALTO + 1;
	aNodo* PrimerNodo = nullptr;
	aNodo* UltimoNodo = nullptr;
public:
	AEstrella(Laberinto^ laberinto, short corruptX, short corruptY, short reyX, short reyY) {
		this->nodos = new aNodo[ancho * alto];
		for (short i = 0; i < ancho; i++) //
		{
			for (short j = 0; j < alto; j++) //
			{
				if(laberinto->es_pared(j,i)) this->nodos[j * ancho + i].Pared = true;
				else this->nodos[j * ancho + i].Pared = false;
				this->nodos[j * ancho + i].Visitado = false;
				this->nodos[j * ancho + i].x = i;
				this->nodos[j * ancho + i].y = j;
				this->nodos[j * ancho + i].padre = nullptr;
			}
		}

		for (short x = 0; x < ancho; x++)
		{
			for (short y = 0; y < alto; y++)
			{
				if (y > 0) //
					nodos[y * ancho + x].vecinos.push_back(&nodos[(y - 1) * ancho + (x + 0)]);
				if (y < alto - 1) //
					nodos[y * ancho + x].vecinos.push_back(&nodos[(y + 1) * ancho + (x + 0)]);
				if (x > 0) //
					nodos[y * ancho + x].vecinos.push_back(&nodos[(y + 0) * ancho + (x - 1)]);
				if (x < ancho - 1) //
					nodos[y * ancho + x].vecinos.push_back(&nodos[(y + 0) * ancho + (x + 1)]);
			}
		}
		PrimerNodo = &nodos[corruptY * ancho + corruptX];
		UltimoNodo = &nodos[reyY * ancho + reyX];
	}

	~AEstrella() {
		delete[] nodos;
	}

	void hallar_camino(short corruptX, short corruptY, short reyX, short reyY) {
		for (short x = 0; x < ancho; x++)
		{
			for (short y = 0; y < alto; y++)
			{
				nodos[y * ancho + x].Visitado = false;
				nodos[y * ancho + x].MetaGlobal = INFINITO;
				nodos[y * ancho + x].MetaLocal = INFINITO;
				nodos[y * ancho + x].padre = nullptr;
			}
		}
		PrimerNodo = &nodos[corruptY * ancho + corruptX];
		UltimoNodo = &nodos[reyY * ancho + reyX];

		aNodo* nodoActual = PrimerNodo;
		nodoActual->MetaLocal = 0.0f;
		nodoActual->MetaGlobal = distancia(PrimerNodo, UltimoNodo);

		list<aNodo*> listaNoProbados;
		listaNoProbados.push_back(nodoActual);

		while (!listaNoProbados.empty() && nodoActual != UltimoNodo) {
			listaNoProbados.sort([](const aNodo* lhs, const aNodo* rhs) {return lhs->MetaGlobal < rhs->MetaLocal; });

			while (!listaNoProbados.empty() && listaNoProbados.front()->Visitado)
				listaNoProbados.pop_front();

			if (listaNoProbados.empty())
				break;

			nodoActual = listaNoProbados.front();
			nodoActual->Visitado = true;

			for (aNodo* nodoVecino : nodoActual->vecinos) {
				if (!nodoVecino->Visitado && nodoVecino->Pared == false)
					listaNoProbados.push_back(nodoVecino);

				float MetaMasBajaPosible = nodoActual->MetaLocal + distancia(nodoActual, nodoVecino);

				if (MetaMasBajaPosible < nodoVecino->MetaLocal) {
					nodoVecino->padre = nodoActual;
					nodoVecino->MetaLocal = MetaMasBajaPosible;
					nodoVecino->MetaGlobal = nodoVecino->MetaLocal + distancia(nodoVecino, UltimoNodo);
				}
			}
		}
	}

private:
	float distancia(aNodo* a, aNodo* b) {
		return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
	}
};

