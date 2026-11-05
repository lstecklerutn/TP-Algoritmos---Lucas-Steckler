#include "headers/funciones.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void cargarArchivoEnMemoria(Orden memoria[filas][columnas], bool ocupada[filas][columnas])
{
    char nombreArchivo[100];
    FILE *archivo;
    OrdenArchivo ordenArchivo;
    Orden memoriaTemporal[filas][columnas];
    bool coordenadasUsadas[filas][columnas];
    bool recorrido[filas][columnas];

    int cantidadDespegues = 0;
    bool despegueConAtaque = false;
    int cantidadAterrizajes = 0;
    int cantidadKamikaze = 0;
    bool coordenadaInvalida = false;
    bool coordenadaRepetida = false;
    int xDespegue = 0;
    int yDespegue = 0;

    int cantidadRegistros = 0;
    int cantidadRecorridas = 0;

    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;

    archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    inicializarMemoria(memoriaTemporal);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            coordenadasUsadas[i][j] = false;
            recorrido[i][j] = false;
        }
    }

    while (fread(&ordenArchivo, sizeof(OrdenArchivo), 1, archivo) == 1)
    {
        if (ordenArchivo.x >= 0 && ordenArchivo.x < filas &&
            ordenArchivo.y >= 0 && ordenArchivo.y < columnas)
        {
            cantidadRegistros++;

            if (coordenadasUsadas[ordenArchivo.x][ordenArchivo.y] == true)
            {
                coordenadaRepetida = true;
            }
            else
            {
                coordenadasUsadas[ordenArchivo.x][ordenArchivo.y] = true;
            }

            if (ordenArchivo.despegue == true)
            {
                cantidadDespegues++;

                xDespegue = ordenArchivo.x;
                yDespegue = ordenArchivo.y;

                if (ordenArchivo.soltarGranada1 == true ||
                    ordenArchivo.soltarGranada2 == true ||
                    ordenArchivo.ataqueKamikaze == true)
                {
                    despegueConAtaque = true;
                }
            }

            if (ordenArchivo.aterrizaje == true)
            {
                cantidadAterrizajes++;
            }

            if (ordenArchivo.ataqueKamikaze == true)
            {
                cantidadKamikaze++;
            }

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].espera =
                ordenArchivo.espera;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].soltarGranada1 =
                ordenArchivo.soltarGranada1;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].soltarGranada2 =
                ordenArchivo.soltarGranada2;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].ataqueKamikaze =
                ordenArchivo.ataqueKamikaze;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].aterrizaje =
                ordenArchivo.aterrizaje;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].despegue =
                ordenArchivo.despegue;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].siguientex =
                ordenArchivo.siguientex;

            memoriaTemporal[ordenArchivo.x][ordenArchivo.y].siguientey =
                ordenArchivo.siguientey;
        }
        else
        {
            coordenadaInvalida = true;
        }
    }

    fclose(archivo);

    if (coordenadaInvalida == true)
    {
        cout << "Error: se encontro una coordenada fuera de rango." << endl;
        return;
    }

    if (coordenadaRepetida == true)
    {
        cout << "Error: hay coordenadas repetidas en el archivo." << endl;
        return;
    }

    if (cantidadDespegues != 1)
    {
        cout << "Error: el archivo debe contener un unico despege." << endl;
        return;
    }

    if (despegueConAtaque == true)
    {
        cout << "Error: la orden de despegue no puede contener un ataque." << endl;
        return;
    }

    if (cantidadAterrizajes + cantidadKamikaze != 1)
    {
        cout << "Error: debe exisir un unico aterrizaje o ataque kamikaze." << endl;
        return;
    }

    int xActual = xDespegue;
    int yActual = yDespegue;

    bool rutaValida = true;
    bool llegoAlFinal = false;

    while (rutaValida == true && llegoAlFinal == false)
    {
        if (recorrido[xActual][yActual] == true)
        {
            cout << "Error: la ruta pasa mas de una vez por la mism coordenada." << endl;
            rutaValida = false;
        }
        else
        {
            recorrido[xActual][yActual] = true;
            cantidadRecorridas++;
        }

        if (rutaValida == true)
        {
            if (memoriaTemporal[xActual][yActual].aterrizaje == true ||
                memoriaTemporal[xActual][yActual].ataqueKamikaze == true)
            {
                llegoAlFinal = true;
            }
            else
            {
                int siguienteX = memoriaTemporal[xActual][yActual].siguientex;
                int siguienteY = memoriaTemporal[xActual][yActual].siguientey;

                if (siguienteX < 0 || siguienteX >= filas ||
                    siguienteY < 0 || siguienteY >= columnas)
                {
                    cout << "Error: la siguiente coordenada esta fuera de rango." << endl;
                    rutaValida = false;
                }
                else
                {
                    int diferenciaX = siguienteX - xActual;
                    int diferenciaY = siguienteY - yActual;

                    if (diferenciaX < 0)
                    {
                        diferenciaX = diferenciaX * -1;
                    }

                    if (diferenciaY < 0)
                    {
                        diferenciaY = diferenciaY * -1;
                    }

                    if (diferenciaX + diferenciaY != 1)
                    {
                        cout << "Error: la siguiente posicion no es una celda aledana." << endl;
                        rutaValida = false;
                    }
                    else if (coordenadasUsadas[siguienteX][siguienteY] == false)
                    {
                        cout << "Error: la ruta tien un hueco." << endl;
                        rutaValida = false;
                    }
                    else
                    {
                        xActual = siguienteX;
                        yActual = siguienteY;
                    }
                }
            }
        }
    }

    if (rutaValida == false)
    {
        return;
    }

    if (cantidadRecorridas != cantidadRegistros)
    {
        cout << "Error: existen ordenes que no forman parte de la ruta" << endl;
        return;
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            memoria[i][j] = memoriaTemporal[i][j];
            ocupada[i][j] = coordenadasUsadas[i][j];
        }
    }

    cout << "Archivo cargado en memoria correctamente" << endl;
}