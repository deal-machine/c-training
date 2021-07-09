#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *v, int start, int mid, int end)
{
  int *temp;
  int size, partOne, partTwo, endOne = 0, endTwo = 0;

  size = end - start + 1;
  partOne = start;
  partTwo = mid + 1;

  temp = (int *)malloc(size * sizeof(int));

  if (temp != NULL)
  {
    for (int x = 0; x < size; x++)
    {
      if (!endOne && !endTwo) //verifica se não chegou ao fim
      {
        if (v[partOne] < v[partTwo]) //compara os dois vetores
        {
          temp[x] = v[partOne];
          partOne++;
        }
        else
        {
          temp[x] = v[partTwo];
          partTwo++;
        }

        if (partOne > mid) //verifica se finalizou a parte
          endOne = 1;
        if (partTwo > end)
          endTwo = 1;
      }
      else
      {
        if (!endOne) //completa vetor temporario
        {
          temp[x] = v[partOne];
          partOne++;
        }
        else
        {
          temp[x] = v[partTwo];
          partTwo++;
        }
      }
    }
  }

  for (int y = 0, z = start; y < size; y++, z++)
    v[z] = temp[y];

  free(temp);
}

void mergeSort(int *v, int start, int end)
{
  int mid;

  if (start < end)
  {
    mid = floor((start + end) / 2); //divide o vetor
    mergeSort(v, start, mid);       //trata metade inicial
    mergeSort(v, mid + 1, end);     //trata metade final
    merge(v, start, mid, end);      //combina os dados
  }
}

void mergeSortMain(int quantity)
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

  mergeSort(v, 0, quantity);

  printf("\nMergeSort\n");
  for (int i = 1; i <= quantity; i++)
  {
    printf(" %d - ", v[i]);
  }

  free(v);
}