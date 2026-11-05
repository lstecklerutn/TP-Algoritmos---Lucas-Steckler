#include <iostream>
#include <limits>
#include "headers/funciones.h"

using namespace std;

void mostrarAtaque(Orden memoria[filas][columnas], bool ocupada[filas][columnas])
{
    int cantidadTotal = 0;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (ocupada[i][j] == true)
            {
                cantidadTotal++;
            }
        }
    }

    if (cantidadTotal == 0)
    {
        cout << "No hay ningun ataque cargad en memoria." << endl;
        return;
    }

    int mostradas = 0;
    int numeroPagina = 1;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nPAGINA " << numeroPagina << "" << endl;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (ocupada[i][j] == true)
            {
                cout << "\nCoordenada (" << i << "," << j << ")" << endl;

                cout << "Espera: " << memoria[i][j].espera << endl;
                cout << "Granada 1: " << memoria[i][j].soltarGranada1 << endl;
                cout << "Granada 2: " << memoria[i][j].soltarGranada2 << endl;
                cout << "Kamikaze: " << memoria[i][j].ataqueKamikaze << endl;
                cout << "Aterrizaje: " << memoria[i][j].aterrizaje << endl;
                cout << "Despegue: " << memoria[i][j].despegue << endl;

                cout << "Siguiente posicion: ("
                     << memoria[i][j].siguientex << ","
                     << memoria[i][j].siguientey << ")" << endl;

                mostradas++;

                if (mostradas % 10 == 0 && mostradas < cantidadTotal)
                {
                    cout << "\n Presione enter para ver la siguiente pagina";
                    cin.get();

                    numeroPagina++;

                    cout << "\nPagina " << numeroPagina << "" << endl;
                }
            }
        }
    }

    cout << "\nFin del ataque cargado" << endl;
}