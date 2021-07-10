#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int quantity)
{
  int *v;
  int i, cont, fim = quantity, aux;

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

  do
  {
    cont = 0;
    for (i = 0; i < fim - 1; i++)
    {
      if (v[i] > v[i + 1])
      {
        aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
        cont = i;
      }
    }
    fim--;
  } while (cont != 0);

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