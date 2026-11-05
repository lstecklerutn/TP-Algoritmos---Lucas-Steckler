#include <iostream>
#include <stdio.h>
#include "headers/funciones.h"
using namespace std;

void crearArchivoAtaque()
{
    char nombreArchivo[100];
    FILE *archivo;
    OrdenArchivo orden;
    int continuar;

    cout << "Ingrese el nombre del archivo: ";
    cin >> nombreArchivo;

    archivo = fopen(nombreArchivo, "wb");

    if (archivo == NULL)
    {
        cout << "No se pudo crear el archivo." << endl;
        return;
    }

    do
    {
        cout << "\nIngrese coordenada X: ";
        cin >> orden.x;

        cout << "Ingrese coordenada Y: ";
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

        fwrite(&orden, sizeof(OrdenArchivo), 1, archivo);

        cout << "\nOrden guardada correctamente." << endl;

        cout << "Desea ingresar otra orden? (1 = si, 0 = no): ";
        cin >> continuar;

    } while (continuar == 1);

    fclose(archivo);

    cout << "\nArchivo creado correctamente." << endl;
}
