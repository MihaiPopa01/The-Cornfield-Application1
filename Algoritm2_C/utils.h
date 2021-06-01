#ifndef CODE_UTILS_H
#define CODE_UTILS_H
#include <stdio.h>
#include <stdlib.h>

#define numar_teste 10
#define limita_maxima 100000

FILE *out;

int aux; // variabila ce retine numarul de elemente ale vectorului coordonate dupa eliminarea tulpinilor
int nr_coordonate; // variabila ce retine numarul de coordonate
int tulpini_ramase; // variabila ce retine numarul de tulpini ramase
int coordonate[100000]; // vector al coordonatelor

void generator(int n);
void afisare_coordonate(int vector[], int dimensiune);
void eliminare_tulpini(int vector[], int dimensiune, int distanta);

#endif
