#include <stdio.h>
#include <stdlib.h>

#include "linkedQueue.h"

int main()
{
  Fila *fila = cria_fila();
  int escolha = 0, valor;
  do
  {
    printf("\n******************************\nNOVA FILA - Informe uma opção\n\n1-Inserir elemento\n2-Remover elemento\n3-Visualizar\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
      printf("\nInforme um valor: ");
      scanf("%d", &valor);
      if (insere_fila(fila, valor))
        printf("\nValor inserido com sucesso.\n");
      else
        printf("\nFalha ao inserir valor.\n");
      break;
    case 2:
      if (remove_fila(fila))
        printf("\nElemento removido com sucesso.\n");
      else
        printf("\nFalha ao remover elemento.\n");
      break;
    case 3:
      exibe_fila(fila);
      break;
    default:
      escolha = 0;
      printf("\nSaindo...\n");
      break;
    }
  } while (escolha >= 1 && escolha <= 3);

  limpa_fila(fila);
  system("pause");
  return 0;
}

Fila *cria_fila()
{
  Fila *fi = (Fila *)malloc(sizeof(Fila));
  fi->inicio = NULL;
  fi->tamanho = 0;

  return fi;
}

void limpa_fila(Fila *fi)
{
  free(fi);
}

int insere_fila(Fila *fi, int valor)
{
  if (fi == NULL)
    return 0;

  No *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->proximo = NULL;

  No *no = fi->inicio;

  if (no == NULL)
    fi->inicio = novo;
  else
  {
    while (no->proximo != NULL)
      no = no->proximo;

    no->proximo = novo;
  }

  fi->tamanho++;

  return 1;
}

int remove_fila(Fila *fi)
{
  if (fi == NULL || fi->inicio == NULL)
    return 0;

  No *aux = fi->inicio;
  fi->inicio = aux->proximo;

  fi->tamanho--;
  return 1;
}

void exibe_fila(Fila *fi)
{
  if (fi == NULL)
    printf("\nFila inexistente.\n");
  else if (fi->inicio == NULL)
    printf("\nFila vazia.\n");
  else
  {
    No *no = fi->inicio;
    printf("\n| ");
    while (no != NULL)
    {
      printf(" %d  ", no->valor);
      no = no->proximo;
    }
    printf(" | \n");
    printf("\nTamanho da fila: %d\n", fi->tamanho);
  }
}