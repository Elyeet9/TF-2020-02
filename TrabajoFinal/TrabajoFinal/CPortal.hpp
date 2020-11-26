#pragma once
#include "CImagen.hpp"
#include "Laberinto.hpp"
#include "CRey.hpp"
#include "CArregloAsesinos.hpp"
#include "CArregloCorruptos.hpp"
ref class CPortal
{
	bool existe;
	short duracion;
	short cooldown;
	Bitmap^ imagen;
	List <CImagen^>^ portales;
public:
	CPortal(String^ ruta) : existe(false), duracion(0), cooldown(0) { 
		this->portales = gcnew List<CImagen^>;
		this->imagen = gcnew Bitmap(ruta);
	}
	~CPortal() {
		if (portales != nullptr) {
			for (short i = 0; i < this->portales->Count; i++)
			{
				delete portales[i];
			}
			delete portales;
			delete imagen;
		}
	}
	void renderizar(Graphics^ graficador, Laberinto^ laberinto, CArregloAsesinos^ asesinos, CArregloCorruptos^ corruptos, CRey^ rey, short w, short h, CArregloAliados^ aliados) {
		if (existe) {
			duracion++;
			this->portales[0]->dibujar(graficador);
			this->portales[1]->dibujar(graficador);
			if (duracion >= 50) {
				portales->RemoveAt(1);
				portales->RemoveAt(0);
				existe = false;
				duracion = 0;
				cooldown = 150;
				return;
			}
			if (rey->hay_colision(portales[0])) {
				rey->tp(portales[1]->getX(), portales[1]->getY());
				aliados->tp_aliados(portales[1]->getX(), portales[1]->getY());
				portales->RemoveAt(1);
				portales->RemoveAt(0);
				existe = false;
				duracion = 0;
				cooldown = 150;
				return;
			}
		}
		else generarPortales(laberinto, asesinos, corruptos, rey, w, h);
	}
private:
	void generarPortales(Laberinto^ laberinto,CArregloAsesinos^ asesinos,CArregloCorruptos^ corruptos,CRey^ rey,short w,short h)
	{	
		--cooldown;
		if (cooldown <= 0) {
			System::Drawing::Rectangle area;
			System::Drawing::Rectangle area_verificar = System::Drawing::Rectangle(rey->getX() - 3 * CAS_ANCHO, rey->getY() - 3 * CAS_ANCHO, CAS_ANCHO * 7, CAS_ANCHO * 7);
			if (corruptos->colision_rectangle(area_verificar) + asesinos->colision_rectangle(area_verificar) > 0) {
				//entrada
				do
				{
					System::Drawing::Rectangle area_vecina = System::Drawing::Rectangle(rey->getX() - CAS_ANCHO, rey->getY() - CAS_ANCHO, CAS_ANCHO * 3, CAS_ANCHO * 3);
					area = System::Drawing::Rectangle(rand() % area_vecina.Width + area_vecina.X, rand() % area_vecina.Height + area_vecina.Y, CAS_ANCHO - 5, CAS_ANCHO);
				} while (laberinto->colision_pared(area));
				this->portales->Add(gcnew CImagen(imagen, area));
				//salida
				do
				{
					area = System::Drawing::Rectangle(rand() % ANCHO * CAS_ANCHO, rand() % ALTO * CAS_ANCHO, CAS_ANCHO - 5, CAS_ANCHO);
				} while (laberinto->colision_pared(area));
				this->portales->Add(gcnew CImagen(imagen, area));
				this->existe = true;
			}
		}
	}
};
