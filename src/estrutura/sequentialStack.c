#include <stdlib.h>
#include <stdio.h>

#include "sequentialStack.h"

struct pilha
{
  int alocados;
  struct produto dados[MAX]
};

Pilha *cria_pilha()
{
  Pilha *pi;
  pi = (Pilha *)malloc(sizeof(struct pilha));

  if (pi != NULL)
    pi->alocados = 0;

  return pi;
};

void libera_pilha(Pilha *pi)
{
  free(pi);
}

int pilha_cheia(Pilha *pi)
{
  if (pi == NULL)
    return -1;

  return (pi->alocados == MAX);
}

int pilha_vazia(Pilha *pi)
{
  if (pi == NULL)
    return -1;

  return (pi->alocados == 0);
}

int tamanho_pilha(Pilha *pi)
{
  if (pi == NULL)
    return -1;
  else
    return pi->alocados;
}

int insere_pilha(Pilha *pi, struct produto prod)
{
  if (pi == NULL || pilha_cheia(pi))
    return 0;

  pi->dados[pi->alocados] = prod;
  pi->alocados++;

  return 1;
}

int remove_pilha(Pilha *pi)
{
  if (pi == NULL || pilha_vazia(pi))
    return 0;

  pi->alocados--;

  return 1;
}

int consulta_pilha(Pilha *pi, struct produto *prod)
{
  if (pi == NULL || pilha_vazia(pi))
    return 0;

  *prod = pi->dados[pi->alocados - 1];

  return 1;
}

int main(void)
{
  system("pause");
  return 0;
}