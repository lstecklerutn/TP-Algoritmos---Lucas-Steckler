#include "headers/funciones.h"
#include <iostream>
#include <stdio.h>

using namespace std;

void generarHTML(Orden memoria[filas][columnas],
                 bool ocupada[filas][columnas])
{
    FILE *archivo;

    archivo = fopen("salida/visual.html", "w");

    if (archivo == NULL)
    {
        cout << "No se pudo crear el archivo HTML." << endl;
        return;
    }

    fprintf(archivo, "<!DOCTYPE html>\n");
    fprintf(archivo, "<html>\n");

    fprintf(archivo, "<head>\n");
    fprintf(archivo, "<meta charset='UTF-8'>\n");
    fprintf(archivo, "<title>Mapa de ataque</title>\n");
    fprintf(archivo, "<link rel='stylesheet' href='estilos.css'>\n");
    fprintf(archivo, "</head>\n");

    fprintf(archivo, "<body>\n");

    fprintf(archivo, "<h1>Mapa de ataque del dron</h1>\n");

    fprintf(archivo, "<div class='contenedor'>\n");

    fprintf(archivo, "<div class='mapa'>\n");

    fprintf(archivo, "<table>\n");

    fprintf(archivo, "<tr>\n");
    fprintf(archivo, "<th class='esquina'>X/Y</th>\n");

    for (int j = 0; j < columnas; j++)
    {
        fprintf(archivo, "<th class='numero-columna'>%d</th>\n", j);
    }

    fprintf(archivo, "</tr>\n");

    for (int i = 0; i < filas; i++)
    {
        fprintf(archivo, "<tr>\n");

        fprintf(archivo, "<th class='numero-fila'>%d</th>\n", i);

        for (int j = 0; j < columnas; j++)
        {
            if (ocupada[i][j] == false)
            {
                fprintf(archivo, "<td class='vacia'></td>\n");
            }
            else
            {
                if (memoria[i][j].despegue == true)
                {
                    fprintf(archivo,
                            "<td class='despegue' title='Coordenada (%d,%d)'>",
                            i, j);
                }
                else if (memoria[i][j].aterrizaje == true)
                {
                    fprintf(archivo,
                            "<td class='aterrizaje' title='Coordenada (%d,%d)'>",
                            i, j);
                }
                else if (memoria[i][j].soltarGranada1 == true)
                {
                    fprintf(archivo,
                            "<td class='granada1' title='Coordenada (%d,%d)'>",
                            i, j);
                }
                else if (memoria[i][j].soltarGranada2 == true)
                {
                    fprintf(archivo,
                            "<td class='granada2' title='Coordenada (%d,%d)'>",
                            i, j);
                }
                else if (memoria[i][j].ataqueKamikaze == true)
                {
                    fprintf(archivo,
                            "<td class='kamikaze' title='Coordenada (%d,%d)'>",
                            i, j);
                }
                else if (memoria[i][j].espera > 0)
                {
                    fprintf(archivo,
                            "<td class='espera' title='Coordenada (%d,%d)'>",
                            i, j);
                }
                else
                {
                    fprintf(archivo,
                            "<td class='movimiento' title='Coordenada (%d,%d)'>",
                            i, j);
                }

                if (memoria[i][j].despegue == true)
                {
                    fprintf(archivo, "D");
                }

                if (memoria[i][j].aterrizaje == true)
                {
                    fprintf(archivo, "A");
                }

                if (memoria[i][j].soltarGranada1 == true)
                {
                    fprintf(archivo, "G1");
                }

                if (memoria[i][j].soltarGranada2 == true)
                {
                    fprintf(archivo, "G2");
                }

                if (memoria[i][j].ataqueKamikaze == true)
                {
                    fprintf(archivo, "K");
                }

                if (memoria[i][j].espera > 0)
                {
                    fprintf(archivo, "E");
                }

                if (memoria[i][j].despegue == false &&
                    memoria[i][j].aterrizaje == false &&
                    memoria[i][j].soltarGranada1 == false &&
                    memoria[i][j].soltarGranada2 == false &&
                    memoria[i][j].ataqueKamikaze == false &&
                    memoria[i][j].espera == 0)
                {
                    fprintf(archivo, "*");
                }

                fprintf(archivo, "</td>\n");
            }
        }

        fprintf(archivo, "</tr>\n");
    }

    fprintf(archivo, "</table>\n");

    fprintf(archivo, "</div>\n");

    fprintf(archivo, "<div class='leyenda'>\n");

    fprintf(archivo, "<h2>Referencias</h2>\n");

    fprintf(archivo,
            "<p><span class='cuadro despegue'></span> D = Despegue</p>\n");

    fprintf(archivo,
            "<p><span class='cuadro aterrizaje'></span> A = Aterrizaje</p>\n");

    fprintf(archivo,
            "<p><span class='cuadro granada1'></span> G1 = Granada 1</p>\n");

    fprintf(archivo,
            "<p><span class='cuadro granada2'></span> G2 = Granada 2</p>\n");

    fprintf(archivo,
            "<p><span class='cuadro kamikaze'></span> K = Ataque kamikaze</p>\n");

    fprintf(archivo,
            "<p><span class='cuadro espera'></span> E = Espera</p>\n");

    fprintf(archivo,
            "<p><span class='cuadro movimiento'></span> * = Movimiento</p>\n");

    fprintf(archivo, "</div>\n");

    fprintf(archivo, "</div>\n");

    fprintf(archivo, "</body>\n");
    fprintf(archivo, "</html>\n");

    fclose(archivo);

    cout << "Archivo HTML generado correctamente." << endl;
}