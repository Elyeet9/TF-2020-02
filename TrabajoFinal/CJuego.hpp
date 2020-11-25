#pragma once
#include <Windows.h>
#include <MMSystem.h>
#include "CImagen.hpp"
#include "CEntidad.hpp"
#include "CRey.hpp"
#include "CArregloAliados.hpp"
#include "CArregloCorruptos.hpp"
#include "Laberinto.hpp"
#include "Vida.hpp"

ref class CJuego
{
	Laberinto^ laberinto;
	CRey^ rey;
	CArregloAliados^ aliados;
	CArregloCorruptos^ corruptos;
	CEntidad^ assassin;
	Vida^ vidas;
	//Para mover el aliado es lo de abajo pero se le puede poner en el arreglo CArregloAliados
	short new_dx;
	short new_dy;
	short n;
public:
	CJuego(System::Drawing::Rectangle area_dibujo, short n, short velocidadcorrupt, short nvidas) : n(n) {
		this->laberinto = gcnew Laberinto();
		this->rey = gcnew CRey("img\\rey centrado.png", System::Drawing::Rectangle(CAS_ANCHO, CAS_ANCHO, CAS_ANCHO-5, CAS_ANCHO), 4, 4, nvidas);
		this->aliados = gcnew CArregloAliados("img\\aliado sin sombras.png", n, area_dibujo.Width, area_dibujo.Height, laberinto);
		this->corruptos = gcnew CArregloCorruptos("img\\corrupt.png", n * 0.4, area_dibujo.Width, area_dibujo.Height, laberinto, this->rey->getX(), this->rey->getY(), velocidadcorrupt);
		vidas = gcnew Vida("img\\vida.png", nvidas);
		this->assassin = gcnew CEntidad("img\\assassin.png", System::Drawing::Rectangle(600, 700, 70, 110), 4, 4);
		PlaySound(TEXT("ost\\Awake.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	~CJuego() {
		delete rey, aliados, corruptos, assassin, vidas;
		PlaySound(NULL, NULL, 0);
	}
	bool jugar(Graphics^ graficador, short w, short h) {
		renderizar(graficador, w, h);
		if (rey->muerto())
			return true;
		return false;
	}
	void mover_rey(short new_dx, short new_dy, bool cam) { 
		this->rey->set_direccion(new_dx, new_dy);
		this->rey->set_caminando(cam);
	}
private:
	void renderizar(Graphics^ graficador, short w, short h) {
		this->laberinto->renderizar(graficador, w, h);
		this->aliados->renderizar(graficador, w, h, rey, laberinto);
		this->corruptos->renderizar(graficador, w, h, laberinto, this->rey, this->vidas);
		this->rey->renderizar(graficador, w, h, laberinto);
		//this->assassin->renderizar(graficador, w, h, laberinto);
		this->vidas->renderizar(graficador);
	}
};