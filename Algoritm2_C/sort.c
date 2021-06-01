#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void interchange_values(int *address_1, int *address_2)
{
    int aux;
    aux = *address_1;
    *address_1 = *address_2;
    *address_2 = aux;
}

int partition(int *vector, int left, int right)
{
    int pivot = vector[left];
    int i = left - 1;
    int j = right + 1;

    while (1)
    {
        do
        {
            i++;
        }
        while (*(vector + i) < pivot);

        do
        {
            j--;
        }
        while (*(vector + j) > pivot);

        if (i >= j)
            return j;

        interchange_values(vector + i, vector + j);
    }
}

void quick_sort(int *vector, int left, int right)
{
    int pivot_position = 0;

    if (left < right)
    {
        pivot_position = partition(vector, left, right);
        quick_sort(vector, left, pivot_position);
        quick_sort(vector, pivot_position + 1, right);
    }
}
