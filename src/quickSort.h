#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int fim)
{
  int esquerda, direita, aux, pivo;

  esquerda = inicio;
  direita = fim;
  pivo = v[inicio];

  while (esquerda < direita)
  {
    while (v[esquerda] <= pivo)
      esquerda++;
    while (v[direita] > pivo)
      direita--;
    if (esquerda < direita)
    {
      aux = v[esquerda];
      v[esquerda] = v[direita];
      v[direita] = aux;
    }
  }
  v[inicio] = v[direita];
  v[direita] = pivo;

  return direita;
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

void quickSortMain(int quantity)
{
  int *v;
  int i;

  v = (int *)malloc(quantity * sizeof(int *));

  for (i = 0; i < quantity; i++)
  {
    v[i] = rand() % 10;
  }

  printf("\nVetor criado\n");
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