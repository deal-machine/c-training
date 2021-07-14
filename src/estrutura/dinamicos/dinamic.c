#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
  int valor;
  struct no *proximo;
} No;

typedef struct Lista
{
  int tamanho;
  No *inicio;
} Lista;

void insere_inicio(Lista *li, int valor)
{
  if (li == NULL)
    printf("NULL");

  No *no = (No *)malloc(sizeof(No));

  no->proximo = li->inicio;
  no->valor = valor;
  li->inicio = no;
  li->tamanho++;
}

void insere_fim(Lista *li, int valor)
{

  No *aux, *novo = (No *)malloc(sizeof(No));

  if (novo)
  {
    novo->valor = valor;
    novo->proximo = NULL;

    if (li->inicio == NULL)
      li->inicio = novo;
    else
    {
      aux = li->inicio;
      while (aux->proximo != NULL)
        aux = aux->proximo;

      aux->proximo = novo;
      li->tamanho++;
    }
  }
  else
    printf("ERRO ALOCAÇÃO DE MEMÓRIA.\n");
}

void insere_meio(Lista *li, int valor, int ref)
{
  No *aux, *novo = (No *)malloc(sizeof(No));

  if (novo)
  {
    novo->valor = valor;
    if (li == NULL)
    {
      novo->proximo = NULL;
      li->inicio = novo;
    }
    else
    {
      aux = li->inicio;
      while (aux->valor != ref && aux->proximo != NULL)
        aux = aux->proximo;

      novo->proximo = aux->proximo;
      aux->proximo = novo;
    }
  }
  else
    printf("ERRO ALOCAÇÃO DE MEMÓRIA.\n");
}

void imprime_lista(Lista *li)
{
  No *inicio = li->inicio;
  while (inicio != NULL)
  {
    printf("%d ", inicio->valor);
    inicio = inicio->proximo;
  }
  printf("\nTamanho da lista: %d\n", li->tamanho);
  printf("\n");
}

void remove_valor(Lista *li, int valor)
{
  No *aux = NULL;
  No *inicio = li->inicio;

  if (li->inicio != NULL && li->inicio->valor == valor)
  {
    aux = li->inicio;
    li->inicio = aux->proximo;
    inicio->valor = valor;
    li->tamanho--;
  }
  printf("Lista vazia.\n");
}

int main()
{
  Lista lista;
  lista.inicio = NULL;
  lista.tamanho = 0;
  int escolha, valor, ref;

  do
  {
    printf("\n***************\nInforme uma opção\n1-Inserir no começo\n2-Inserir por referencia\n3-Inserir no fim\n4-Imprimir Lista\n5-Sair\n***************\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {

    case 1:
      printf("\nInforme um para inserir no começo: ");
      scanf("%d", &valor);
      insere_inicio(&lista, valor);
      break;
    case 2:
      printf("\nInforme um valor para inserir por referência: ");
      scanf("%d", &valor);
      printf("Informe o valor da referencia: ");
      scanf("%d", &ref);
      insere_meio(&lista, valor, ref);
      break;
    case 3:
      printf("\nInforme um valor: ");
      scanf("%d", &valor);
      insere_fim(&lista, valor);
      break;
    case 4:
      printf("\nLista: ");
      imprime_lista(&lista);
      break;
    case 5:
      printf("\nSaindo...");
      break;
    default:
      printf("\nEscolha Inválida.\n\n");
      break;
    }

  } while (escolha != 5);

  free(lista.inicio);

  system("pause");
  return 0;
}