#include "headers/funciones.h"
#include <iostream>

using namespace std;

void corregirRegistroMemoria(Orden memoria[filas][columnas], bool ocupada[filas][columnas])
{
    int x;
    int y;

    cout << "Ingrese coordenada X del registro a corregir: ";
    cin >> x;

    cout << "Ingrese coordenada Y del registro a corregir: ";
    cin >> y;

    if (x < 0 || x >= filas || y < 0 || y >= columnas)
    {
        cout << "Error: coordenada fuera de rango." << endl;
        return;
    }

    if (ocupada[x][y] == false)
    {
        cout << "No existe un registro en esa coordenada." << endl;
        return;
    }

    cout << "\n Registro actual " << endl;

    cout << "Espera: " << memoria[x][y].espera << endl;
    cout << "Granada 1: " << memoria[x][y].soltarGranada1 << endl;
    cout << "Granada 2: " << memoria[x][y].soltarGranada2 << endl;
    cout << "Kamikaze: " << memoria[x][y].ataqueKamikaze << endl;
    cout << "Aterrizaje: " << memoria[x][y].aterrizaje << endl;
    cout << "Despegue: " << memoria[x][y].despegue << endl;
    cout << "Siguiente X: " << memoria[x][y].siguientex << endl;
    cout << "Siguiente Y: " << memoria[x][y].siguientey << endl;

    cout << "\n Ingrese los nuevos datos:" << endl;

    cout << "Tiempo de espera: ";
    cin >> memoria[x][y].espera;

    cout << "Soltar granada 1? (1 = si, 0 = no): ";
    cin >> memoria[x][y].soltarGranada1;

    cout << "Soltar granada 2? (1 = si, 0 = no): ";
    cin >> memoria[x][y].soltarGranada2;

    cout << "Ataque kamikaze? (1 = si, 0 = no): ";
    cin >> memoria[x][y].ataqueKamikaze;

    cout << "Aterrizaje? (1 = si, 0 = no): ";
    cin >> memoria[x][y].aterrizaje;

    cout << "Despegue? (1 = si, 0 = no): ";
    cin >> memoria[x][y].despegue;

    cout << "Siguiente X: ";
    cin >> memoria[x][y].siguientex;

    cout << "Siguiente Y: ";
    cin >> memoria[x][y].siguientey;

    cout << "Registro modificado correctamente." << endl;
}
