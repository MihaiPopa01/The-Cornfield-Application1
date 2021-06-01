#ifndef CODE_SORT_H
#define CODE_SORT_H
#include "utils.h"

void interchange_values(int *address_1, int *address_2);
int partition(int *vector, int left, int right);
void quick_sort(int *vector, int left, int right);

#endif
