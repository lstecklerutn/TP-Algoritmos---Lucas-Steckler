#include "headers/funciones.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void mostrarArchivoPrueba()
{
    char nombreArchivo[100];
    FILE *archivo;
    OrdenArchivo orden;
    int contador = 1;

    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;

    archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    while (fread(&orden, sizeof(OrdenArchivo), 1, archivo) == 1)
    {
        cout << "\n Orden " << contador << ":" << endl;

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

        contador++;
    }

    fclose(archivo);
}
