#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergeSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"

int main(void)
{

  int choose;
  int quantity;

  printf("\n1-BubbleSort; 2-InsertionSort; 3-SelectionSort; 4-MergeSort; 5-QuickSort;\nQualquer outro comando finalizará o sistema. ");
  printf("\nEscolha o metodo de ordenação: ");
  scanf("%d", &choose);

  if (choose == 1 || choose == 2 || choose == 3 || choose == 4 || choose == 5)
  {
    printf("\nInforme a quantidade de valores: ");
    scanf("%d", &quantity);
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
    printf("\nQUICKSORT CHOOSED");
    break;
  default:
    printf("\nFINALIZANDO\n");
    system("pause");
    return 0;
    break;
  }
  clock_t end = clock();
  double time_spend = (double)(end - begin) * 100 / CLOCKS_PER_SEC;

  printf("\n\nTime: %f\n\n", time_spend);

  system("pause");
  return 0;
}
