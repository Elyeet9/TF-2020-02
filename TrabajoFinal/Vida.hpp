#pragma once
#include "CImagen.hpp"
#include "Laberinto.hpp"
using namespace System::Collections::Generic;
ref class Vida
{
	List<CImagen^>^ vidas;
	Bitmap^ imagen;
public:
	Vida(String^ ruta, short n) {
		vidas = gcnew List<CImagen^>;
		imagen = gcnew Bitmap(ruta);
		for (short i = 0; i < n; i++)
		{
			CImagen^ corazon = gcnew CImagen(imagen, System::Drawing::Rectangle(i * CAS_ANCHO, 0, CAS_ANCHO, CAS_ANCHO));
			vidas->Add(corazon);
		}
	}
	~Vida() {
		for (short i = 0; i < this->vidas->Count; ++i)
		{
			delete vidas[i];
		}
		delete vidas;
		delete imagen;
	}
	void renderizar(Graphics^ graficador) {
		for (int i = 0; i < vidas->Count; i++)
		{
			vidas[i]->dibujar(graficador);
		}
	}
	void perder_vida() {
		vidas->RemoveAt(this->vidas->Count-1);
	}
};

