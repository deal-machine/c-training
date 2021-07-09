#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim);

void quickSort(int *v, int inicio, int fim);

void quickSortMain(int quantity)
{
  int *v, i;

  v = (int *)malloc(quantity * sizeof(int *));

  for (i = 0; i < quantity; i++)
  {
    v[i] = rand() % 10;
  }

  printf("\nVetor Criado\n");
  for (i = 0; i < quantity; i++)
  {
    printf(" %d - ", v[i]);
  }

  quickSort(v, 0, quantity);

  printf("\nQuickSort\n");
  for (i = 1; i <= quantity; i++)
  {
    printf(" %d - ", v[i]);
  }

  free(v);
}

void quickSort(int *v, int inicio, int fim)
{
  int pivo;

  if (fim > inicio)
  {
    pivo = particiona(v, inicio, fim);

    quickSort(v, inicio, pivo - 1);
    quickSort(v, pivo + 1, fim);
  }
}

int particiona(int *v, int inicio, int fim)
{
  int esq, dir, aux, pivo, i;
  esq = inicio;
  dir = fim;
  pivo = v[inicio];

  while (esq < dir)
  {
    while (v[esq] <= pivo)
      esq++; // --->
    while (v[dir] > pivo)
      dir--; // <---
    if (esq < dir)
    {
      aux = v[esq];
      v[esq] = v[dir];
      v[dir] = aux;
    }
  }
  v[inicio] = v[dir];
  v[dir] = pivo;

  return dir;
}