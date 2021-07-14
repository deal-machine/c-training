#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
  int valor;
  struct no *proximo;
  struct no *anterior;
} No;

typedef struct lista
{
  int tamanho;
  No *inicio;
} Lista;

Lista *cria_lista();
void libera_lista(Lista *li);
void insere_inicio(Lista *li, int valor);
void insere_ordenado(Lista *li, int valor);
void insere_fim(Lista *li, int valor);
void imprime_lista(Lista *li);
void remove_valor(Lista *li, int valor);

int main()
{
  Lista *li = cria_lista();
  int escolha = 0, valor;

  do
  {
    printf("\n******************************\nInforme uma opção\n1-Inserir no começo\n2-Inserir por referencia\n3-Inserir no fim\n4-Remove valor\n5-Imprimir Lista\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      printf("\nInforme um para inserir no começo: ");
      scanf("%d", &valor);
      insere_inicio(li, valor);
      break;
    case 2:
      printf("\nInforme um valor para inserir: ");
      scanf("%d", &valor);
      insere_ordenado(li, valor);
      break;
    case 3:
      printf("\nInforme um valor: ");
      scanf("%d", &valor);
      insere_fim(li, valor);
      break;
    case 4:
      printf("\nInforme um valor para remover: ");
      scanf("%d", &valor);
      remove_valor(li, valor);
      break;
    case 5:
      printf("\nLista: ");
      imprime_lista(li);
      break;
    default:
      printf("\nSaindo...\n");
    }
  } while (escolha >= 1 && escolha <= 5);

  libera_lista(li);
  system("pause");
  return 0;
}

Lista *cria_lista()
{
  Lista *lista = (Lista *)malloc(sizeof(Lista));

  lista->inicio = NULL;
  lista->tamanho = 0;

  return lista;
}

void libera_lista(Lista *li)
{
  free(li);
}

void insere_inicio(Lista *li, int valor)
{

  No *novo = (No *)malloc(sizeof(No));

  novo->valor = valor;
  novo->proximo = li->inicio;
  novo->anterior = NULL;

  if (li->inicio != NULL) //lista não vazia
    li->inicio->anterior = novo;

  li->inicio = novo;
  li->tamanho++;
}

void insere_fim(Lista *li, int valor)
{

  No *novo = (No *)malloc(sizeof(No));

  novo->valor = valor;
  novo->proximo = NULL;

  //lista vazia, insere no começo
  if (li->inicio == NULL)
  {
    novo->anterior = NULL;
    li->inicio = novo;
  }
  else
  {
    No *fim = li->inicio;
    while (fim->proximo != NULL)
      fim = fim->proximo;

    fim->proximo = novo;
    novo->anterior = fim;
  }

  li->tamanho++;
}

void insere_ordenado(Lista *li, int valor)
{
  No *novo = (No *)malloc(sizeof(No));

  novo->valor = valor;
  if (li->inicio == NULL)
  {
    novo->proximo = NULL;
    novo->anterior = NULL;
    li->inicio = novo;
  }
  else
  {
    No *antes, *atual = li->inicio;

    while (atual->proximo != NULL && atual->valor < valor)
    {
      antes = atual;
      atual = atual->proximo;
    }
    if (atual == li->inicio)
    {
      novo->anterior = NULL;
      li->inicio->anterior = novo;
      novo->proximo = li->inicio;
      li->inicio = novo;
    }
    else
    {
      novo->proximo = antes->proximo;
      novo->anterior = antes;
      antes->proximo = novo;
      if (atual != NULL)
        atual->anterior = novo;
    }
  }
  li->tamanho++;
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
  No *inicio = li->inicio;
  if (inicio == NULL)
    printf("\nLista vazia.\n");
  else
  {
    No *aux = inicio->proximo;

    while (inicio->valor != valor && aux != NULL)
      aux = inicio->proximo;

    inicio->proximo = aux->proximo;
    free(aux);
    li->tamanho--;
  }
}
