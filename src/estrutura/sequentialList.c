#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sequentialList.h"

struct lista
{
  int alocados;
  struct aluno dados[MAX];
};

Lista cria_lista()
{
  Lista *li;                                  //instancia Lista
  li = (Lista *)malloc(sizeof(struct lista)); //libera memoria para nova lista
  if (li != NULL)                             //verifica alocação
    li->alocados = 0;                         //li aponta quantidade de alocados
  return li;                                  //retorna o primeiro dado da lista
}

void libera_lista(Lista *li)
{
  free(li); //libera memoria da lista
}

int tamanho_lista(Lista *li)
{
  if (li == NULL)
    return -1;
  else
    return li->alocados;
}

int lista_cheia(Lista *li)
{
  if (li == NULL)
    return -1;

  return (li->alocados == MAX);
}

int lista_vazia(Lista *li)
{
  if (li == NULL)
    return -1;

  return (li->alocados == 0);
}

int insere_final(Lista *li, struct aluno alu)
{
  if (li == NULL)
    return 0;
  if (lista_cheia(li))
    return 0;

  li->dados[li->alocados] = alu;
  li->alocados++;

  return 1;
}

int insere_inicio(Lista *li, struct aluno alu)
{
  if (li == NULL)
    return 0;
  if (lista_cheia(li))
    return 0;

  int i;
  for (i = li->alocados - 1; i >= 0; i--)
    li->dados[li->alocados + 1] = li->dados[i];

  li->dados[0] = alu;
  li->alocados++;

  return 1;
}

int insere_ordenado(Lista *li, struct aluno alu)
{
  if (li == NULL)
    return 0;
  if (lista_cheia(li))
    return 0;

  int i = 0, j;

  while (i < li->alocados && li->dados[i].matricula < alu.matricula)
    i++;

  for (j = li->alocados - 1; j >= i; j--)
    li->dados[j + 1] = li->dados[j];

  li->dados[i] = alu;
  li->alocados++;

  return 1;
}

int remove_inicio(Lista *li)
{
  if (li == NULL)
    return 0;
  if (lista_vazia(li))
    return 0;

  for (int i = 0; i < li->alocados - 1; i++)
    li->dados[i] = li->dados[i + 1];

  li->alocados--;

  return 1;
}

int remove_ordenado(Lista *li, int matricula)
{
  if (li == NULL)
    return 0;
  if (lista_vazia(li))
    return 0;
  int i = 0, j;

  while (i < li->alocados && li->dados[i].matricula != matricula)
    i++;

  if (i == li->alocados) //nao encontrado
    return 0;

  for (j = i; j <= li->alocados - 1; j++)
    li->dados[j] = li->dados[j + 1];

  li->alocados--;

  return 1;
}

int remove_fim(Lista *li)
{
  if (li == NULL)
    return 0;
  if (lista_vazia(li))
    return 0;

  li->alocados--;

  return 1;
}

int consulta_posicao(Lista *li, int posicao, struct aluno *alu)
{
  if (li == NULL || posicao <= 0 || posicao > li->alocados)
    return 0;

  *alu = li->dados[posicao - 1];

  return 1;
}

int consulta_valor(Lista *li, int valor, struct aluno *alu)
{
  if (li == NULL)
    return 0;

  int i = 0;
  while (i < li->alocados && li->dados[i].matricula != valor)
    i++;

  if (i == li->alocados) //nao encontrado
    return 0;

  *alu = li->dados[i];

  return 1;
}

int main(void)
{

  system("pause");
  return 0;
}