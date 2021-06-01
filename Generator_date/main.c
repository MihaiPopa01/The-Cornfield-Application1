#include <stdio.h>
#include <stdlib.h>
#define limita_maxima 100000

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
int main()
{
    generator(limita_maxima);
    return 0;
}
