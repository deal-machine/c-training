#include <stdlib.h>
#include <stdio.h>

#include "sequentialQueue.h"

struct fila
{
  int inicio, fim, alocados;
  struct pessoa dados[MAX]
};

Fila *cria_fila()
{
  Fila *fi;
  fi = (Fila *)malloc(sizeof(struct fila));
  if (fi != NULL)
  {
    fi->inicio = 0;
    fi->fim = 0;
    fi->alocados = 0;
  }
  return fi;
}

void limpa_fila(Fila *fi)
{
  free(fi);
}

int tamanho_fila(Fila *fi)
{
  if (fi == NULL)
    return -1;

  return (fi->alocados);
}

int fila_cheia(Fila *fi)
{
  if (fi == NULL)
    return -1;

  return (fi->alocados == MAX);
}

int fila_vazia(Fila *fi)
{
  if (fi == NULL)
    return -1;

  return (fi->alocados == 0);
}

int insere_fila(Fila *fi, struct pessoa pe)
{
  if (fi == NULL || fila_cheia(fi))
    return 0;

  fi->dados[fi->fim] = pe;
  fi->fim = (fi->fim + 1) % MAX;
  fi->alocados++;

  return 1;
}

int remove_fila(Fila *fi)
{
  if (fi == NULL || fila_vazia(fi))
    return 0;

  // fi->inicio = (fi->inicio+1)%MAX;
  fi->inicio++;
  if (fi->inicio == MAX)
    fi->inicio = 0;

  fi->alocados--;

  return 1;
}

int consulta_fila(Fila *fi, struct pessoa *pe)
{
  if (fi == NULL || fila_vazia(fi))
    return 0;

  *pe = fi->dados[fi->inicio];

  return 1;
}

int main(void)
{
  syste("pause");
  return 0;
}