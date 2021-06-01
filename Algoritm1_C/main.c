#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

int main()
{
    FILE *in;
    char nume_in[30],nume_out[30];
    int Max; // variabila ce retine maximul coordonatelor
    int coord; // variabila ce retine coordonata unui cocean de porumb
    int lan[100000]; // vector care reprezinta lanul de porumb
    int nr_coordonate; // variabila ce reprezinta numarul de coordonate
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

        fscanf(in,"%d", &nr_coordonate);
        fscanf(in,"%d", &distanta_minima);

        start = clock();

        for(int j = 0; j < nr_coordonate; j++)
        {
            lan[j]= 0; // initializarea vectorului lan cu 0
        }

        Max = 0; // initializarea maximului cu 0
        tulpini_ramase = 0; // initializarea numarului de tulpini ramase cu 0

        for(int k = 0; k < nr_coordonate; k++)
        {
            fscanf(in, "%d", &coord);
            if(coord >= Max)
            {
                Max = coord; // determinarea maximului coordonatelor
            }
            if(lan[coord] == 1)
            {
                eliminari++; // cresterea numarului de eliminari datorita coordonatelor ce se repeta
            }
            else
            {
                lan[coord] = 1; // marcarea cu 1 a cocenilor de porumb existenti in vectorul lan
            }
        }

        if(distanta_minima <= Max)
        {
            eliminare_tulpini(lan, Max, distanta_minima);

            fprintf(out, "Numarul minim de tulpini eliminate: %d \n", nr_coordonate-tulpini_ramase);

            afisare_coordonate(lan, Max);
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
