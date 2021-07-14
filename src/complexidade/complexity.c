#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergeSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "quickSort.h"

void main()
{

  int choose;
  int quantity;
  int *v;

  printf("\n1-BubbleSort; 2-InsertionSort; 3-SelectionSort; 4-MergeSort; 5-QuickSort;\nQualquer outro comando finalizará o sistema. ");
  printf("\nEscolha o metodo de ordenação: ");
  scanf("%d", &choose);

  if (choose >= 1 && choose <= 5)
  {
    printf("\nInforme a quantidade de valores: ");
    scanf("%d", &quantity);

    v = (int *)malloc(quantity * sizeof(int *));

    for (int i = 0; i < quantity; i++)
    {
      v[i] = rand() % 10;
    }
  }

  clock_t begin = clock();

  switch (choose)
  {
  case 1:
    bubbleSort(quantity);
    break;
  case 2:
    insertionSort(quantity);
    break;
  case 3:
    selectionSort(quantity);
    break;
  case 4:
    mergeSortMain(quantity);
    break;
  case 5:
    quickSortMain(quantity);
    break;
  default:
    printf("\nFINALIZANDO\n");
    system("pause");
    break;
  }

  clock_t end = clock();

  free(v);

  double time_spend = (double)(end - begin) * 100 / CLOCKS_PER_SEC;

  printf("\n\nTime: %f\n\n", time_spend);

  system("pause");
}
