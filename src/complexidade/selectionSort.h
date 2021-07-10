#include <stdio.h>
#include <stdlib.h>

void selectionSort(int quantity)
{
  int *v;
  int x, y, aux, min;

  v = (int *)malloc(quantity * sizeof(int));

  for (int i = 0; i < quantity; i++)
  {
    v[i] = rand() % 100;
  }
  if (quantity <= 15)
  {
    printf("\nVetor Criado\n");
    for (int i = 0; i < quantity; i++)
    {
      printf(" %d -", v[i]);
    }
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
  if (quantity <= 15)
  {
    for (int i = 0; i < quantity; i++)
    {
      printf(" %d -", v[i]);
    }
  }
  free(v);
}