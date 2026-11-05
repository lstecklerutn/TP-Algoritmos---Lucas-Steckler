#include "headers/funciones.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void guardarMemoriaEnArchivo(
    Orden memoria[filas][columnas],
    bool ocupada[filas][columnas])
{
    bool hayAtaque = false;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (ocupada[i][j] == true)
            {
                hayAtaque = true;
            }
        }
    }

    if (hayAtaque == false)
    {
        cout << "No hay ningun ataque cargado en memoria." << endl;
        return;
    }

    char nombreArchivo[100];
    FILE *archivo;

    cout << "Ingrese el nombre del nuevo archivo: ";
    cin >> nombreArchivo;

    archivo = fopen(nombreArchivo, "wb");

    if (archivo == NULL)
    {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (ocupada[i][j] == true)
            {
                OrdenArchivo ordenArchivo;

                ordenArchivo.x = i;
                ordenArchivo.y = j;
                ordenArchivo.espera = memoria[i][j].espera;
                ordenArchivo.soltarGranada1 = memoria[i][j].soltarGranada1;
                ordenArchivo.soltarGranada2 = memoria[i][j].soltarGranada2;
                ordenArchivo.ataqueKamikaze = memoria[i][j].ataqueKamikaze;
                ordenArchivo.aterrizaje = memoria[i][j].aterrizaje;
                ordenArchivo.despegue = memoria[i][j].despegue;
                ordenArchivo.siguientex = memoria[i][j].siguientex;
                ordenArchivo.siguientey = memoria[i][j].siguientey;

                fwrite(&ordenArchivo, sizeof(OrdenArchivo), 1, archivo);
            }
        }
    }

    fclose(archivo);

    cout << "Memoria guardada correctamente." << endl;
}