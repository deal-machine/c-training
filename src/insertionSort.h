#include <stdio.h>
#include <stdlib.h>

void insertionSort(int quantity)
{
  int i, x, y, aux;
  int *v;

  v = (int *)malloc(quantity * sizeof(int));

  for (i = 0; i < quantity; i++)
  {
    v[i] = rand() % 100;
  }
  if (quantity <= 15)
  {
    printf("\nVetor Criado\n");
    for (i = 0; i < quantity; i++)
    {
      printf(" %d -", v[i]);
    }
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
  if (quantity <= 15)
  {
    for (i = 0; i < quantity; i++)
    {
      printf(" %d -", v[i]);
    }
  }
  free(v);
}
