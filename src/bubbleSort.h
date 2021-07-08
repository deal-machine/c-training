#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int quantity)
{
  int *v;
  int i, y, x, aux;

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

  for (x = 0; x < quantity; x++)
  {
    for (y = x + 1; y < quantity; y++)
    {
      if (v[x] > v[y])
      {
        aux = v[x];
        v[x] = v[y];
        v[y] = aux;
      }
    }
  }

  printf("\nBubbleSort\n");
  if (quantity <= 15)
  {
    for (i = 0; i < quantity; i++)
    {
      printf(" %d -", v[i]);
    }
  }

  //libera espaço em memoria
  free(v);
}