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
int remove_inicio(Lista *li);
int remove_fim(Lista *li);

int main()
{
  Lista *li = cria_lista();
  int escolha = 0, valor, remove = 0;

  do
  {
    printf("\n******************************\nInforme uma opção\n1-Inserir no começo\n2-Inserir ordenado\n3-Inserir no fim\n4-Remover valor\n5-Imprimir Lista\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      printf("\nInforme um valor para inserir no começo: ");
      scanf("%d", &valor);
      insere_inicio(li, valor);
      break;
    case 2:
      printf("\nInforme um valor para inserir ordenado: ");
      scanf("%d", &valor);
      insere_ordenado(li, valor);
      break;
    case 3:
      printf("\nInforme um valor para inserir no fim: ");
      scanf("%d", &valor);
      insere_fim(li, valor);
      break;
    case 4:

      printf("\n1-Remover do inicio\n2-Remover por referência\n3-Remover do fim.\n4-Voltar\nEscolha: ");
      scanf("%d", &remove);
      switch (remove)
      {
      case 1:
        if (remove_inicio(li))
          printf("\nValor removido do inicio.\n");
        else
          printf("\nErro ao remover do inicio.\n");
        break;
      case 2:
        printf("remover por referencia");
        break;
      case 3:
        if (remove_fim(li))
          printf("\nValor removido do fim.\n");
        else
          printf("\nErro ao remover do fim.\n");
        break;
      case 4:
        printf("\nVoltando...\n");
        break;
      default:
        break;
      }

      break;
    case 5:
      printf("\nLista: ");
      imprime_lista(li);
      break;
    default:
      escolha = 0;
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

int remove_inicio(Lista *li)
{
  if (li == NULL || li->inicio == NULL)
    return 0;

  No *no = li->inicio;

  li->inicio = no->proximo;

  if (no->proximo == NULL)
    no = NULL;

  free(no);

  li->tamanho--;

  return 1;
}

int remove_fim(Lista *li)
{
  if (li == NULL || li->inicio == NULL)
    return 0;

  No *no = li->inicio;

  while (no->proximo != NULL)
    no = no->proximo;

  if (no->anterior == NULL)
    li->inicio = no->proximo;
  else
    no->anterior->proximo = NULL;

  free(no);

  li->tamanho--;

  return 1;
}