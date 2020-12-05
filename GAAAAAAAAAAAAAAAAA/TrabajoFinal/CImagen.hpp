#pragma once

using namespace System;
using namespace System::Drawing;

ref class CImagen
{
protected:
	System::Drawing::Rectangle area_dibujo;
	Bitmap^ imagen;
	short dx, dy;
public:
	CImagen(String^ ruta, System::Drawing::Rectangle area_dibujo)
		: area_dibujo(area_dibujo) {
		this->imagen = gcnew Bitmap(ruta);
	}
	CImagen(Bitmap^ imagen, System::Drawing::Rectangle area_dibujo)
		: area_dibujo(area_dibujo) {
		this->imagen = imagen;
	}
	~CImagen() {
		delete this->imagen;
	}
	bool hay_colision(CImagen^ otro) {
		return this->area_dibujo.IntersectsWith(otro->area_dibujo);
	}
	bool hay_colision(System::Drawing::Rectangle otro) {
		return this->area_dibujo.IntersectsWith(otro);
	}
	
	void set_direccion(short new_dx, short new_dy) {
		this->dx = new_dx;
		this->dy= new_dy;
	}

	virtual void dibujar(Graphics^ graficador) {
		graficador->DrawImage(this->imagen, this->area_dibujo);
	}

	short getX() { return area_dibujo.X; }
	short getY() { return area_dibujo.Y; }
};

