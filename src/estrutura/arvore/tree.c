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
No *cria_no(int valor);
void limpa_arvore(Arvore *ar);
void limpa_filhos(No *no);
int arvore_vazia(Arvore *ar);
int arvore_total(Arvore *ar);
void imprime_pre(No *no);
void imprime_ordem(No *no);
void imprime_pos(No *no);
void insere_valor(Arvore *ar, int valor);
No *remove_valor(No *no);
void remove_valor_arvore(Arvore *ar, int valor);

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
      insere_valor(ar, valor);
      break;
    case 2:
      printf("\nInforme um valor para remover: ");
      scanf("%d", &valor);
      remove_valor_arvore(ar, valor);
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
    }
  } while (escolha >= 1 && escolha <= 3);

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

No *remove_valor(No *no)
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

void remove_valor_arvore(Arvore *ar, int valor)
{
  if (arvore_vazia(ar))
  {
    printf("\nÁrvore inexistente ou vazia.\n");
    return;
  }

  No *no = ar->raiz;
  No *anterior = NULL;
  while (no != NULL)
  {
    if (valor == no->valor)
    {
      if (no == ar->raiz)
        ar->raiz = remove_valor(no);
      else
      {
        if (anterior->direita == no)
          anterior->direita = remove_valor(no);
        else
          anterior->esquerda = remove_valor(no);
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