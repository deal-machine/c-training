#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "mergeSort.h"
#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"

int main(void)
{
  clock_t begin = clock();

  int quantity;
  printf("\nInforme a quantidade de valores: ");
  scanf("%d", &quantity);

  // bubbleSort(quantity);
  //insertionSort(quantity);
  //selectionSort(quantity);
  mergeSortMain(quantity);

  clock_t end = clock();

  double time_spend = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("\n\n%f\n", time_spend);

  system("pause");
  return 0;
}
