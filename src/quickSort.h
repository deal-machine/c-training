#include <stdio.h>
#include <stdlib.h>

int partition(int *v, int start, int end)
{
  int left, right, aux;
  int pivot = v[start];

  left = start;
  right = end;

  while (left < right)
  {
    while (v[left] > pivot)
      left++;
    while (v[right] > pivot)
      right--;
    if (left > right)
    {
      aux = v[right];
      v[right] = v[left];
      v[left] = aux;
    }
    v[start] = v[right];
    v[right] = pivot;
  }

  return pivot;
}

void quickSort(int *v, int start, int end)
{
  int pivot;
  if (end > start)
  {
    pivot = partition(v, start, end);
    quickSort(v, start, end);
    quickSort(v, pivot + 1, end);
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

  printf("\nVetor Criado\n");
  for (i = 0; i < quantity; i++)
  {
    printf(" %d -", v[i]);
  }

  quickSort(v, 0, quantity);

  free(v);
}