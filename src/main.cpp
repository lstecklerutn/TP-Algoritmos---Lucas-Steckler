#include <iostream>
#include "funciones/headers/funciones.h"
using namespace std;

int main()
{
    Orden memoria[filas][columnas];
    bool ocupada[filas][columnas];

    inicializarMemoria(memoria);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            ocupada[i][j] = false;
        }
    }

    int opcion;

    do
    {
        cout << "\n [SISTEMA DE ATAQUE]\n";
        cout << "1 Cargar archivo de ataque en memoria\n";
        cout << "2 Mostrar ataque cargado\n";
        cout << "3 Crear un archivo de ataque nuevo\n";
        cout << "4 Corregir un registro del archivo\n";
        cout << "5 Corregir un registro en memoria\n";
        cout << "6 Guardar memoria en un archivo nuevo\n";
        cout << "7 Visualizar un archivo de ataque en HTML\n";
        cout << "0 Salir\n";

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cargarArchivoEnMemoria(memoria, ocupada);
            break;

        case 2:
            mostrarAtaque(memoria, ocupada);
            break;

        case 3:
            crearArchivoAtaque();
            break;

        case 4:
            corregirRegistroArchivo();
            break;

        case 5:
            corregirRegistroMemoria(memoria, ocupada);
            break;

        case 6:
            guardarMemoriaEnArchivo(memoria, ocupada);
            break;

        case 7:
            generarHTML(memoria, ocupada);
            break;
        case 8:
            cout << "Mostrar Archivos\n";
            mostrarArchivoPrueba();
            break;

        case 0:
            cout << "Fin del programa\n";
            break;

        default:
            cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}