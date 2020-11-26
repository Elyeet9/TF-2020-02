#include "pch.h"
#include "MyForm.h"
#include "menu.h"
#include "ending.h"
#include <cstdlib>
#include <time.h>
using namespace System;
using namespace TrabajoFinal;
int main()
{
    srand(time(NULL));
    short* tiempo = new short;
    short* n = new short;
    short* vidas = new short;
    bool* jugar = new bool;
    bool* ganaste = new bool;
    *ganaste = false;
    *jugar = false;
    
    Application::Run(gcnew menu(vidas, tiempo, n, jugar));
    if (*jugar) Application::Run(gcnew MyForm(*tiempo, *n, *vidas, ganaste));
    if (*jugar) Application::Run(gcnew ending(*ganaste));
    delete tiempo, n, vidas, jugar, ganaste;
    return 0;
}