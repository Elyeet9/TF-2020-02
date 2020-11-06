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
	void renderizar(Graphics^ graficador, short w, short h) {
		this->mover(w, h);
		this->dibujar(graficador);
	}
	void set_direccion(short new_dx, short new_dy) {
		this->dx = new_dx;
		this->dy= new_dy;
	}
	//by jhinta
	short getX() { return area_dibujo.X; }
	short getY() { return area_dibujo.Y; }
	//end by jhinta
protected:
	virtual void dibujar(Graphics^ graficador) {
		graficador->DrawImage(this->imagen, this->area_dibujo);
	}
	void mover(short w, short h) {
		if (this->area_dibujo.X + dx >= 0 && this->area_dibujo.X + dx + this->area_dibujo.Width <= w)
			this->area_dibujo.X += dx;
		else this->dx = 0;
		if (this->area_dibujo.Y + dy >= 0 && this->area_dibujo.Y + dy + this->area_dibujo.Height <= h)
			this->area_dibujo.Y += dy;
		else this->dy = 0;
	}
};

