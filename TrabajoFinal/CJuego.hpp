#pragma once
#include <Windows.h>
#include <MMSystem.h>
#include "CImagen.hpp"
#include "CEntidad.hpp"
#include "CRey.hpp"
#include "CArregloAliados.hpp"
#include "Laberinto.hpp"

ref class CJuego
{
	Laberinto^ laberinto;
	CRey^ rey;
	CArregloAliados^ aliados;
	CEntidad^ corrupt;
	CEntidad^ assassin;
	//Para mover el aliado es lo de abajo pero se le puede poner en el arreglo CArregloAliados
	short new_dx;
	short new_dy;
public:
	CJuego(System::Drawing::Rectangle area_dibujo) {
		laberinto = gcnew Laberinto();
		rey = gcnew CRey("img\\rey centrado.png", System::Drawing::Rectangle(CAS_ANCHO, CAS_ANCHO, CAS_ANCHO-5, CAS_ANCHO), 4, 4, 5);
		aliados = gcnew CArregloAliados("img\\aliado sin sombras.png", 6, area_dibujo.Width, area_dibujo.Height, laberinto);
		corrupt = gcnew CEntidad("img\\corrupt.png", System::Drawing::Rectangle(600, 300, CAS_ANCHO - 5, CAS_ANCHO), 4, 4, 1);
		assassin = gcnew CEntidad("img\\assassin.png", System::Drawing::Rectangle(600, 700, 70, 110), 4, 4, 1);
		PlaySound(TEXT("ost\\Awake.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	~CJuego() {
		delete rey, aliados, corrupt, assassin;
		PlaySound(NULL, NULL, 0);
	}
	void jugar(Graphics^ graficador, short w, short h) {
		renderizar(graficador, w, h);
	}
	void mover_rey(short new_dx, short new_dy) { 
		rey->set_direccion(new_dx, new_dy);
	}
private:
	void renderizar(Graphics^ graficador, short w, short h) {
		laberinto->renderizar(graficador, w, h);
		aliados->renderizar(graficador, w, h, rey, laberinto);
		rey->renderizar(graficador, w, h, laberinto);
		//corrupt->renderizar(graficador, w, h, laberinto);
		//assassin->renderizar(graficador, w, h, laberinto);
	}
};