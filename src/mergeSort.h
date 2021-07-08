#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *v, int start, int mid, int end)
{
  int *temp;
  int size, partOne, partTwo, endOne, endTwo;

  size = end - start + 1;
  partOne = start;
  partTwo = mid + 1;

  temp = (int *)malloc(size * sizeof(int));

  if (temp != NULL)
  {
    for (int x = 0; x < size; x++)
    {
      if (!endOne && !endTwo)
      { //merge array ordened
        if (v[partOne] < v[partTwo])
          temp[x] = v[partOne++];
        else
          temp[x] = v[partTwo++];
        //verify end of array
        if (partOne > mid)
          endOne = 1;
        if (partTwo > end)
          endTwo = 1;
      }
      else
      { //merge rest of array
        if (!endOne)
          temp[x] = v[partOne++];
        else
          temp[x] = v[partTwo++];
      }
    }
  }

  for (int y = 0, z = start; y < size; y++, z++)
  {
    v[z] = temp[y]; //return aux to vector
  }

  for (int i = 0; i < size; i++)
  {
    printf("\n%d", v[i]);
  }

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

  for (int i = 0; i < end; i++)
  {
    printf("\n%d", v[i]);
  }
}

void mergeSortMain(int quantity)
{
  int *v;
  int start, mid, end;

  v = (int *)malloc(quantity * sizeof(int *));

  for (int i = 0; i < quantity; i++)
  {
    v[i] = rand();
  }

  for (int i = 0; i < quantity; i++)
  {
    printf("\n%d", v[i]);
  }

  mergeSort(v, 0, quantity);

  printf("\nMergeSort\n");

  free(v);
}