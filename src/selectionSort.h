#include <stdio.h>
#include <stdlib.h>

void selectionSort(int quantity)
{
  float *v;
  int x, y, aux, min;

  v = (float *)malloc(quantity * sizeof(float));

  for (int i = 0; i < quantity; i++)
  {
    v[i] = rand();
  }

  for (x = 0; x < quantity - 1; x++)
  {
    min = x;
    for (y = x + 1; y < quantity; y++)
    {
      if (v[y] < v[min])
      {
        min = y;
      }
    }
    if (x != min)
    {
      aux = v[x];
      v[x] = v[min];
      v[min] = aux;
    }
  }

  printf("\nSelectionSort\n");

  free(v);
}