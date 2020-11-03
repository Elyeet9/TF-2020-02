#pragma once
#include <Windows.h>
#include <MMSystem.h>
#include "CImagen.hpp"
#include "CEntidad.hpp"

ref class CJuego
{
	CImagen^ escenario;
	CEntidad^ rey;
	CEntidad^ aliado;
	CEntidad^ corrupt;
	CEntidad^ assassin;
public:
	CJuego(System::Drawing::Rectangle area_dibujo) {
		escenario = gcnew CImagen("img\\fondo.png", area_dibujo);
		rey = gcnew CEntidad("img\\rey.png", System::Drawing::Rectangle(0, 0, 110, 120), 4, 4, 5);
		aliado = gcnew CEntidad("img\\aliado.png", System::Drawing::Rectangle(300, 300, 110, 120), 4, 4, 1);
		corrupt = gcnew CEntidad("img\\corrupt.png", System::Drawing::Rectangle(600, 300, 110, 110), 4, 4, 1);
		assassin = gcnew CEntidad("img\\assassin.png", System::Drawing::Rectangle(600, 700, 70, 110), 4, 4, 1);
		PlaySound(TEXT("ost\\Awake.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	~CJuego() {
		delete escenario;
		delete rey;
		delete aliado;
		delete corrupt;
		delete assassin;
		PlaySound(NULL, NULL, 0);
	}
	void renderizar(Graphics^ graficador) {
		escenario->renderizar(graficador);
		aliado->renderizar(graficador);
		corrupt->renderizar(graficador);
		assassin->renderizar(graficador);
		rey->renderizar(graficador);
	}
	void mover_rey(short new_dx, short new_dy) { rey->set_direccion(new_dx, new_dy); }
};
