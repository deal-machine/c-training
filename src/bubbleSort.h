#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int quantity)
{
  float *v;
  int i, y, x, aux;

  /*
    quantity * sizeof(float) => quantidade de bytes necessários 
    malloc() => reservar quantidade de memória, retorna ponteiro   
    (float *) => converte ponteiro para tipo de dado 
  */
  v = (float *)malloc(quantity * sizeof(float));

  for (i = 0; i < quantity; i++)
  {
    v[i] = rand();
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

  //libera espaço em memoria
  free(v);
}