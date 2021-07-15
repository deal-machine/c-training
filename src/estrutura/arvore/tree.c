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
void imprime_pre(No *no);
void imprime_ordem(No *no);
void imprime_pos(No *no);
int insere(Arvore *ar, int valor);

int main()
{

  Arvore *ar = cria_arvore();
  int escolha = 0, valor, exibicao = 0;

  do
  {
    printf("\n******************************\nTrabalhando com ÁRVORE\nInforme uma opção\n\n1-Inserir valor\n2-Remover valor\n3-Visualizar\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
      printf("\nInforme um valor para inserir: ");
      scanf("%d", &valor);
      insere(ar, valor);
      break;
    case 2:
      printf("\nValor não excluido.\n");
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
    default:
      escolha = 0;
      printf("\nSaindo...\n");
      break;
    }
  } while (escolha >= 1 && escolha <= 3);

  remove_arvore(ar);

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

void remove_arvore(Arvore *ar)
{
  if (ar == NULL || ar->raiz == NULL)
  {
    free(ar);
    return;
  }

  No *no = ar->raiz;

  remove_filhos(no);

  free(ar);

  printf("\nÁrvore removida com sucesso.\n");
}

void remove_filhos(No *no)
{
  if (no == NULL)
    printf("\nNo inexistente.\n");

  remove_filhos(no->esquerda);
  remove_filhos(no->direita);

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

int insere(Arvore *ar, int valor)
{
  if (ar == NULL)
  {
    printf("\nÁrvore inexistente.\n");
    return 0;
  }

  No *novo = (No *)malloc(sizeof(No));
  novo->valor = valor;
  novo->direita = NULL;
  novo->esquerda = NULL;

  if (ar->raiz == NULL)
    ar->raiz = novo;
  else
  {
    No *no = ar->raiz;
    No *anterior = NULL;
    while (no != NULL)
    {
      anterior = no;
      if (valor == no->valor)
      {
        free(novo);
        printf("\nValor já existe.\n");
        return 0;
      }
      if (valor > no->valor)
        no = no->direita;
      else
        no = no->esquerda;
    }
    if (valor > anterior->valor)
      anterior->direita = novo;
    else
      anterior->esquerda = novo;
  }

  ar->total++;
  ar->altura++;

  printf("\nElemento inserido com sucesso.\n");
  return 1;
}