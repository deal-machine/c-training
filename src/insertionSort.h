#include <stdio.h>
#include <stdlib.h>

void insertionSort(int quantity)
{
  int i, x, y, aux;
  float *v;

  v = (float *)malloc(quantity * sizeof(float));

  for (i = 0; i < quantity; i++)
  {
    v[i] = rand();
  }

  for (x = 1; x < quantity; x++)
  {
    aux = v[x];
    y = x - 1;

    while ((y >= 0) && (aux < v[y]))
    {
      v[y + 1] = v[y];
      y--;
    }
    v[y + 1] = aux;
  }

  printf("\nInsertionSort\n");

  free(v);
}
