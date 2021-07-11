#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

int main(void)
{
  Lista *li;

  li = cria_lista();
  libera_lista(li);

  int tamanho = tamanho_lista(li);

  system("pause");
  return 0;
}