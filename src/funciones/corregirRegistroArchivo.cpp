#include "headers/funciones.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void corregirRegistroArchivo()
{
    char nombreArchivo[100];
    FILE *archivo;
    OrdenArchivo orden;

    int xBuscada;
    int yBuscada;
    bool encontrado = false;
    int posicion = 0;

    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;

    archivo = fopen(nombreArchivo, "rb+");

    if (archivo == NULL)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    cout << "Ingrese coordenada X del registro a corregir: ";
    cin >> xBuscada;

    cout << "Ingrese coordenada Y del registro a corregir: ";
    cin >> yBuscada;

    while (fread(&orden, sizeof(OrdenArchivo), 1, archivo) == 1 &&
           encontrado == false)
    {
        if (orden.x == xBuscada && orden.y == yBuscada)
        {

            encontrado = true;
            break;
        }
        else
        {
            posicion++;
        }
    }

    if (encontrado == false)
    {
        cout << "No se encontro un registro en esas coordenadas." << endl;
        fclose(archivo);
        return;
    }

    cout << "\n Registro encontrado " << endl;

    cout << "X: " << orden.x << endl;
    cout << "Y: " << orden.y << endl;
    cout << "Espera: " << orden.espera << endl;
    cout << "Granada 1: " << orden.soltarGranada1 << endl;
    cout << "Granada 2: " << orden.soltarGranada2 << endl;
    cout << "Kamikaze: " << orden.ataqueKamikaze << endl;
    cout << "Aterrizaje: " << orden.aterrizaje << endl;
    cout << "Despegue: " << orden.despegue << endl;
    cout << "Siguiente X: " << orden.siguientex << endl;
    cout << "Siguiente Y: " << orden.siguientey << endl;

    cout << "\n Ingrese los nuevos datos:" << endl;

    cout << "X: ";
    cin >> orden.x;

    cout << "Y: ";
    cin >> orden.y;

    cout << "Tiempo de espera: ";
    cin >> orden.espera;

    cout << "Soltar granada 1? (1 = si, 0 = no): ";
    cin >> orden.soltarGranada1;

    cout << "Soltar granada 2? (1 = si, 0 = no): ";
    cin >> orden.soltarGranada2;

    cout << "Ataque kamikaze? (1 = si, 0 = no): ";
    cin >> orden.ataqueKamikaze;

    cout << "Aterrizaje? (1 = si, 0 = no): ";
    cin >> orden.aterrizaje;

    cout << "Despegue? (1 = si, 0 = no): ";
    cin >> orden.despegue;

    cout << "Siguiente X: ";
    cin >> orden.siguientex;

    cout << "Siguiente Y: ";
    cin >> orden.siguientey;

    fseek(archivo, posicion * sizeof(OrdenArchivo), SEEK_SET);
    fwrite(&orden, sizeof(OrdenArchivo), 1, archivo);
    fclose(archivo);

    cout << "Registro corregido correctamente." << endl;
}