#include "pch.h"
#include "MyForm.h"
#include <cstdlib>
#include <time.h>
using namespace System;
using namespace TrabajoFinal;
int main()
{
    srand(time(NULL));
    Application::Run(gcnew MyForm);
    return 0;
}