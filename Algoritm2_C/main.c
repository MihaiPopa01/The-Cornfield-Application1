#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

int main()
{
    FILE *in;
    char nume_in[30], nume_out[30];
    int nr_copie; // variabila ce retine o copie a numarului de coordonate
    int distanta_minima; // variabila ce retine distanta minima intre 2 coceni

    srand(time(0));

    generator(limita_maxima);

    for(int i = 1; i <= numar_teste; i++)
    {
        clock_t start, finish;
        double  duration;

        sprintf(nume_in, "Data/input%d.txt", i);
        sprintf(nume_out, "Data/output%d.txt", i);
        in = fopen(nume_in, "r");
        out = fopen(nume_out, "w");

        fscanf(in, "%d", &nr_coordonate);
        fscanf(in, "%d", &distanta_minima);

        for(int j = 0; j < nr_coordonate; j++)
        {
            coordonate[j] = 0; // initializarea vectorului coordonate cu 0
        }

        nr_copie = nr_coordonate;
        aux = 0;

        for(int k = 0; k <= nr_coordonate - 1; k++)
        {
            fscanf(in,"%d", &coordonate[k]);  // stocarea coordonatelor in vector
        }

        start = clock();

        quick_sort(coordonate, 0, nr_coordonate); // sortarea strict crescatoare a vectorului coordonate

        if(distanta_minima <= coordonate[nr_coordonate])
        {
            eliminare_tulpini(coordonate, nr_coordonate, distanta_minima);

            fprintf(out,"Numarul minim de tulpini eliminate: %d \n", nr_copie-tulpini_ramase);
            fprintf(out, "\n");

            afisare_coordonate(coordonate, aux);
        }
        else
        {
            fprintf(out, "IMPOSIBIL\n");
        }

        finish = clock();
        duration = (double)(finish - start) / CLOCKS_PER_SEC;

        fprintf(out, "\nDurata testului %d : %.13fs", i, duration);

        fclose(in);
        fclose(out);
    }

    return 0;

}
