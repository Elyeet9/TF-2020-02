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

ref class AEstrella
{
	aNodo* nodos = nullptr;
	short ancho = ANCHO + 1;
	short alto = ALTO + 1;
	aNodo* PrimerNodo = nullptr;
	aNodo* UltimoNodo = nullptr;
public:
	AEstrella(Laberinto^ laberinto, short startX, short startY, short reyX, short reyY) {
		this->nodos = new aNodo[ancho * alto];
		for (short y = 0; y < alto; y++) //
		{
			for (short x = 0; x < ancho; x++) //
			{
				this->nodos[y * ancho + x].x = x;
				this->nodos[y * ancho + x].y = y;
				if(laberinto->es_pared(y, x)) this->nodos[y * ancho + x].Pared = true;
				else this->nodos[y * ancho + x].Pared = false;
				this->nodos[y * ancho + x].padre = nullptr;
				this->nodos[y * ancho + x].Visitado = false;
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
		PrimerNodo = &nodos[startY / CAS_ANCHO * ancho + startX / CAS_ANCHO];
		UltimoNodo = &nodos[reyY / CAS_ANCHO * ancho + reyX / CAS_ANCHO];
	}

	~AEstrella() {
		delete[] nodos;
	}

	void hallar_camino(short startX, short startY, short reyX, short reyY) {
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
		PrimerNodo = &nodos[startY / CAS_ANCHO * ancho + startX / CAS_ANCHO];
		UltimoNodo = &nodos[reyY / CAS_ANCHO * ancho + reyX / CAS_ANCHO];

		aNodo* nodoActual = PrimerNodo;
		nodoActual->MetaLocal = 0.0f;
		nodoActual->MetaGlobal = distancia(PrimerNodo, UltimoNodo);

		vector<aNodo*> listaNoProbados;
		listaNoProbados.push_back(nodoActual);

		while (!listaNoProbados.empty() && nodoActual != UltimoNodo) {
			for (unsigned short i = 0; i < listaNoProbados.size()-1; i++)
			{
				for (unsigned short j = i+1; j < listaNoProbados.size(); j++)
				{
					if (listaNoProbados.at(i)->MetaGlobal > listaNoProbados.at(j)->MetaGlobal)
						swap(listaNoProbados.at(i), listaNoProbados.at(j));
				}
			}

			while (!listaNoProbados.empty() && listaNoProbados.front()->Visitado)
				listaNoProbados.erase(listaNoProbados.begin());

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

	short get_new_dx(short startX, short velocidad) {
		if (UltimoNodo->padre != nullptr)
		{
			aNodo* p = UltimoNodo;
			while (p->padre->padre != nullptr)
			{
				p = p->padre;
			}
			if (startX < p->x * CAS_ANCHO)
				return velocidad;
			else if (startX > p->x * CAS_ANCHO) return velocidad * -1;
		}
	}

	short get_new_dy(short startY, short velocidad) {
		if (UltimoNodo->padre != nullptr)
		{
			aNodo* p = UltimoNodo;
			while (p->padre->padre != nullptr)
			{
				p = p->padre;
			}
			if (startY > p->y * CAS_ANCHO)
				return velocidad * -1;
			else if (startY < p->y * CAS_ANCHO) return velocidad;
		}
	}

private:
	float distancia(aNodo* a, aNodo* b) {
		return sqrtf((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
	}
};

