#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

int main()
{
  Arvore *ar = cria_arvore();
  int escolha = 0, valor, exibicao = 0;

  do
  {
    printf("\n******************************\nTrabalhando com ÁRVORE\nInforme uma opção\n\n1-Inserir valor\n2-Remover valor\n3-Visualizar\n4-Buscar por valor\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
      printf("\nInforme um valor para inserir: ");
      scanf("%d", &valor);
      insere_valor(ar, valor);
      break;
    case 2:
      printf("\nInforme um valor para remover: ");
      scanf("%d", &valor);
      remove_valor(ar, valor);
      break;
    case 3:
      printf("\nInforme um metodo de exibição\n1-Pré-Ordem\n2-Ordem\n3-Pós-Ordem\n4-Tamanho da árvore\nQualquer outra tecla para voltar\nEscolha: ");
      scanf("%d", &exibicao);
      switch (exibicao)
      {
      case 1:
        printf("\nPré-Ordem\n");
        imprime_pre(ar->raiz);
        break;
      case 2:
        printf("\nOrdem\n");
        imprime_ordem(ar->raiz);
        break;
      case 3:
        printf("\nPós-Ordem\n");
        imprime_pos(ar->raiz);
        break;
      case 4:
        printf("\nTamanho da árvore: %d\n", arvore_total(ar));
        break;
      case 5:
        printf("\nVoltando...\n");
        break;
      default:
        break;
      }
      break;
    case 4:
      printf("\nInforme um valor para buscar: ");
      scanf("%d", &valor);
      if (consulta_arvore(ar, valor))
        printf("\nValor %d encontrado.\n", valor);
      else
        printf("\nValor %d não encontrado.\n", valor);
      break;
    default:
      escolha = 0;
      printf("\nSaindo...\n");
    }
  } while (escolha >= 1 && escolha <= 4);

  limpa_arvore(ar);

  system("pause");
  return 0;
}

Arvore *cria_arvore()
{
  Arvore *ar = (Arvore *)malloc(sizeof(Arvore));

  ar->total = 0;
  ar->altura = 0;
  ar->raiz = NULL;

  return ar;
}

No *cria_no(int valor)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->direita = NULL;
  novo->esquerda = NULL;

  return novo;
}

void limpa_arvore(Arvore *ar)
{
  if (ar == NULL || ar->raiz == NULL)
  {
    free(ar);
    return;
  }

  No *no = ar->raiz;

  limpa_filhos(no);

  free(ar);

  printf("\nÁrvore removida com sucesso.\n");
}

void limpa_filhos(No *no)
{
  if (no == NULL)
    printf("\nNo inexistente.\n");

  limpa_filhos(no->esquerda);
  limpa_filhos(no->direita);

  free(no);
  no = NULL;

  printf("\nFilhos removidos com sucesso.\n");
}

int arvore_vazia(Arvore *ar)
{
  if (ar == NULL || ar->raiz == NULL)
    return 1;

  return 0;
}

int arvore_total(Arvore *ar)
{
  if (ar == NULL || ar->raiz == NULL)
    return 0;

  return ar->total;
}

void imprime_pre(No *no)
{
  if (no != NULL)
  {
    printf("%d\n", no->valor);
    imprime_pre(no->esquerda);
    imprime_pre(no->direita);
  }
}

void imprime_ordem(No *no)
{
  if (no != NULL)
  {
    imprime_ordem(no->esquerda);
    printf("%d\n", no->valor);
    imprime_ordem(no->direita);
  }
}

void imprime_pos(No *no)
{
  if (no != NULL)
  {
    imprime_pos(no->esquerda);
    imprime_pos(no->direita);
    printf("%d\n", no->valor);
  }
}

void insere_valor(Arvore *ar, int valor)
{
  if (ar == NULL)
  {
    printf("\nÁrvore inexistente.\n");
    return;
  }

  if (ar->raiz == NULL)
    ar->raiz = cria_no(valor);
  else
  {
    No *no = ar->raiz;
    No *anterior = NULL;
    while (no != NULL)
    {
      anterior = no;
      if (valor == no->valor)
      {
        printf("\nValor já existe.\n");
        return;
      }
      if (valor > no->valor)
        no = no->direita;
      else
        no = no->esquerda;
    }

    if (valor > anterior->valor)
      anterior->direita = cria_no(valor);
    else
      anterior->esquerda = cria_no(valor);
  }

  ar->total++;

  printf("\nElemento inserido com sucesso.\n");
}

No *remove_no(No *no)
{
  No *aux, *sub;

  if (no->esquerda == NULL)
  {
    sub = no->direita;
    free(no);
    return sub;
  }
  aux = no;
  sub = no->esquerda;
  while (sub->direita != NULL)
  {
    aux = sub;
    sub = sub->direita;
  }
  if (aux != no)
  {
    aux->direita = sub->esquerda;
    sub->esquerda = no->esquerda;
  }
  sub->direita = no->direita;
  free(no);
  return sub;
}

void remove_valor(Arvore *ar, int valor)
{
  if (arvore_vazia(ar))
    return;

  No *no = ar->raiz;
  No *anterior = NULL;
  while (no != NULL)
  {
    if (valor == no->valor)
    {
      if (no == ar->raiz)
        ar->raiz = remove_no(no);
      else
      {
        if (anterior->direita == no)
          anterior->direita = remove_no(no);
        else
          anterior->esquerda = remove_no(no);
      }

      ar->total--;
      printf("\nValor removido. \n");
      return;
    }
    anterior = no;
    if (valor > no->valor)
      no = no->direita;
    else
      no = no->esquerda;
  }
}

int consulta_arvore(Arvore *ar, int valor)
{
  if (arvore_vazia(ar))
    return 0;

  No *no = ar->raiz;
  while (no != NULL)
  {
    if (no->valor == valor)
      return 1;
    if (no->valor > valor)
      no = no->esquerda;
    else
      no = no->direita;
  }
  return 0;
}