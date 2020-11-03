#pragma once
#include <Windows.h>
#include <MMSystem.h>
#include "CImagen.hpp"
#include "CEntidad.hpp"
#include "CAliado.hpp"

ref class CJuego
{
	CImagen^ escenario;
	CEntidad^ rey;
	CAliado^ aliado;
	CEntidad^ corrupt;
	CEntidad^ assassin;
	//Para mover el aliado es lo de abajo pero se le puede poner en el arreglo CArregloAliados
	short new_dx;
	short new_dy;
public:
	CJuego(System::Drawing::Rectangle area_dibujo) {
		escenario = gcnew CImagen("img\\fondo.png", area_dibujo);
		rey = gcnew CEntidad("img\\rey.png", System::Drawing::Rectangle(0, 0, 110, 120), 4, 4, 5);
		aliado = gcnew CAliado("img\\aliado.png", System::Drawing::Rectangle(300, 300, 110, 120), 4, 4, 1);
		corrupt = gcnew CEntidad("img\\corrupt.png", System::Drawing::Rectangle(600, 300, 110, 110), 4, 4, 1);
		assassin = gcnew CEntidad("img\\assassin.png", System::Drawing::Rectangle(600, 700, 70, 110), 4, 4, 1);
		PlaySound(TEXT("ost\\Awake.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
	~CJuego() {
		delete escenario, rey, aliado, corrupt, assassin;
		PlaySound(NULL, NULL, 0);
	}
	void jugar(Graphics^ graficador) {
		if (aliado->hay_colision(rey)) aliado->set_perseguir(true);
		renderizar(graficador);
	}
	void mover_rey(short new_dx, short new_dy) { 
		rey->set_direccion(new_dx, new_dy); 
		if (new_dx != 0 || new_dy != 0) { //cuando no se mueve el rey sus dx y dy son 0, si le quitas el if >:v
			this->new_dx = new_dx;
			this->new_dy = new_dy;
		}
	}
private:
	void renderizar(Graphics^ graficador) {
		escenario->renderizar(graficador);
		if (aliado->get_perseguir() == true)
			aliado->mover_aliado(rey->getX() - 8 * new_dx, rey->getY() - 8 * new_dy);
		//una pregunta, de donde sacas el new_dx y new_dy de aca?
		aliado->renderizar(graficador);
		corrupt->renderizar(graficador);
		assassin->renderizar(graficador);
		rey->renderizar(graficador);
	}
};