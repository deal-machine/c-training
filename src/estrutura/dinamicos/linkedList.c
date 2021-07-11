#include <stdlib.h>
#include <stdio.h>

#include "linkedList.h"

struct elemento
{
  struct pessoa dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Lista *cria_lista()
{
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL)
    *li = NULL;

  return li;
}

void libera_lista(Lista *li)
{
  if (li != NULL)
  {
    Elem *no;
    while ((*li) != NULL)
    {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

int tamanho_lista(Lista *li)
{
  if (li == NULL)
    return 0;

  int cont = 0;
  Elem *no = *li;
  while (*li != NULL)
  {
    cont++;
    no = no->prox;
  }
  return cont;
}

int lista_vazia(Lista *li)
{
  if (li == NULL || *li == NULL)
    return 1;

  return 0;
}