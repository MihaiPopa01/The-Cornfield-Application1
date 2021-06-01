#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void generator(int n)
{
    for(int i = 1; i <= 10; i++)
    {
        FILE *aux;
        char nume[30];
        sprintf(nume, "Data/input%d.txt", i);
        aux = fopen(nume, "w");

        int i, nr, distanta_minima;

        nr = rand()%n;  // generarea numarului de coordonate
        distanta_minima = rand()%n + 1;  // generarea distantei minime

        fprintf(aux, "%d %d\n", nr, distanta_minima); // afisarea in fisier a numarului de coordonate si a distantei minime

        for(int j = 1; j <= nr; j++)
        {
            fprintf(aux, "%d ", (rand()%n));  // generarea si afisarea in fisier a coordonatelor
        }
        fclose(aux);

    }
}

void afisare_coordonate(int vector[], int dimensiune)
{
    fprintf(out,"Coordonatele cocenilor ramasi sunt: \n");
    for (int i = 0; i <= dimensiune; i++)
        fprintf(out, "%d ", vector[i]);
    fprintf(out, "\n");

}

void eliminare_tulpini(int vector[], int dimensiune, int distanta)
{
    int eliminari; // variabila ce retine numarul de tulpini eliminate
    eliminari = 0;
    tulpini_ramase = 0;
    for(int i = 0; i < dimensiune; i++)
    {
        if(vector[i+1] - vector[i] < distanta)
        {

            for(int j = i+1; j < dimensiune; j++)
            {
                // eliminarea tulpinilor, deplasand spre stanga cu o pozitie vectorul coordonate
                vector[j] = vector[j+1];
            }
            i--;
            dimensiune--;
            eliminari++;
        }
    }
    aux = dimensiune;

    while(eliminari <= nr_coordonate)
    {
        // determinarea numarului de tulpini ramase
        tulpini_ramase++;
        eliminari++;
    }
}
