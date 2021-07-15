#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
  int valor;
  int alturaEsquerda;
  int alturaDireita;
  struct no *esquerda;
  struct no *direita;
} No;

typedef struct arvore
{
  int altura;
  int total;
  struct no *raiz;
} Arvore;

Arvore *cria_arvore();
void remove_arvore(Arvore *ar);
void remove_filhos(No *no);
int arvore_vazia(Arvore *ar);
int arvore_total(Arvore *ar);

void imprime_pre(Arvore *ar);

void imprime_ordem(Arvore *ar);

void imprime_pos(Arvore *ar);

int main()
{

  Arvore *ar = cria_arvore();

  free(ar);
  system("pause");
  return 0;
}

Arvore *cria_arvore()
{
  Arvore *ar = (Arvore *)malloc(sizeof(Arvore));

  ar->tamanho = 0;
  ar->altura = 0;
  ar->raiz = NULL;

  return ar;
}

void remove_arvore(Arvore *ar)
{
  if (ar == NULL)
    printf("\nÁrvore inexistente.\n");

  remove_filhos(ar->raiz);

  free(ar);

  printf("\nÁrvore removida com sucesso.\n");
}

void remove_filhos(No *no)
{
  if (no == NULL)
    printf("\nNo inexistente.\n");

  libera_filhos(no->esquerda);
  libera_filhos(no->direita);

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

void imprime_pre(Arvore *ar)
{
  if (ar == NULL)
    printf("\nÁrvore inexistente.\n");

  // No *raiz = ar->raiz;

  if (ar->raiz != NULL)
  {
    printf("%d\n", ar->raiz->valor);
    imprime_pre(ar->raiz->esquerda);
    imprime_pre(ar->raiz->direita);
  }
}

void imprime_ordem(Arvore *ar)
{
  if (ar == NULL)
    printf("\nÁrvore inexistente.\n");

  if (ar->raiz != NULL)
  {
    imprime_ordem(ar->raiz->esquerda);
    printf("%d\n", ar->raiz->valor);
    imprime_ordem(ar->raiz->direita);
  }
}

void imprime_pos(Arvore *ar)
{
  if (ar == NULL)
    printf("\nÁrvore inexistente.\n");

  if (ar->raiz != NULL)
  {
    imprime_pos(ar->raiz->esquerda);
    imprime_pos(ar->raiz->direita);
    printf("%d\n", ar->raiz->valor);
  }
}