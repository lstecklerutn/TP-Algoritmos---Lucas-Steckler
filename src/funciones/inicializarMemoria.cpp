#include "headers/funciones.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void inicializarMemoria(Orden memoria[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            memoria[i][j].espera = 0;
            memoria[i][j].soltarGranada1 = false;
            memoria[i][j].soltarGranada2 = false;
            memoria[i][j].ataqueKamikaze = false;
            memoria[i][j].aterrizaje = false;
            memoria[i][j].despegue = false;
            memoria[i][j].siguientex = 0;
            memoria[i][j].siguientey = 0;
        }
    }
}
