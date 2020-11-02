#pragma once
#include <Windows.h>
#include <MMSystem.h>


ref class CJuego
{
public:
	CJuego(System::Drawing::Rectangle area_dibujo) {
		PlaySound(TEXT("ost\\Step.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	}
};

