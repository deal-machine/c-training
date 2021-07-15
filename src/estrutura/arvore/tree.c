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
