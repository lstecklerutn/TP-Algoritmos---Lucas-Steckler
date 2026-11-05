#ifndef FUNCIONES_H
#define FUNCIONES_H

const int filas = 200;
const int columnas = 200;

struct Orden
{
    unsigned int espera;
    bool soltarGranada1;
    bool soltarGranada2;
    bool ataqueKamikaze;
    bool aterrizaje;
    bool despegue;
    int siguientex;
    int siguientey;
};

struct OrdenArchivo
{
    int x;
    int y;
    unsigned int espera;
    bool soltarGranada1;
    bool soltarGranada2;
    bool ataqueKamikaze;
    bool aterrizaje;
    bool despegue;
    int siguientex;
    int siguientey;
};

void inicializarMemoria(Orden memoria[filas][columnas]);
void crearArchivoAtaque();
void mostrarArchivoPrueba();
void cargarArchivoEnMemoria(Orden memoria[filas][columnas], bool ocupada[filas][columnas]);
void mostrarAtaque(Orden memoria[filas][columnas], bool ocupada[filas][columnas]);
void corregirRegistroMemoria(Orden memoria[filas][columnas], bool ocupada[filas][columnas]);
void corregirRegistroArchivo();
void guardarMemoriaEnArchivo(
    Orden memoria[filas][columnas],
    bool ocupada[filas][columnas]);
void generarHTML(
    Orden memoria[filas][columnas],
    bool ocupada[filas][columnas]);

#endif