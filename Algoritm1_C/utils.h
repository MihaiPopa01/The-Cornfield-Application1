#ifndef CODE_UTILS_H
#define CODE_UTILS_H
#include <stdio.h>

#define numar_teste 10
#define limita_maxima 100000

FILE *out;

int eliminari; // variabila ce retine numarul de eliminari
int tulpini_ramase; // variabila ce retine numarul de tulpini ramase

void generator(int n);
void afisare_coordonate(int vector[], int dimenisune);
void eliminare_tulpini(int vector[], int dimensiune, int distanta);

#endif
