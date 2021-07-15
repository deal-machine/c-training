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

int insere_inicio(Lista *li, int valor);
int insere_ordenado(Lista *li, int valor);
int insere_fim(Lista *li, int valor);

int remove_inicio(Lista *li);
int remove_fim(Lista *li);
int remove_valor(Lista *li, int valor);

void visualiza_valor(Lista *li, int valor);
void visualiza_posicao(Lista *li, int posicao);
void imprime_lista(Lista *li);

int main()
{
  Lista *li = cria_lista();
  int escolha = 0, valor, remove = 0, insere = 0, visualiza = 0, posicao;

  do
  {
    printf("\n******************************\nTrabalhando com LISTAS\nInforme uma opção\n\n1-Inserir\n2-Remover valor\n3-Visualizar\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      printf("\n1-Inserir no começo\n2-Inserir ordenado\n3-Inserir no fim\n4-Voltar\nEscolha: ");
      scanf("%d", &insere);
      switch (insere)
      {
      case 1:
        printf("\nInforme um valor para inserir no começo: ");
        scanf("%d", &valor);
        if (insere_inicio(li, valor))
          printf("\nValor inserido com sucesso.\n");
        else
          printf("\nFalha ao inserir valor.\n");
        break;
      case 2:
        printf("\nInforme um valor para inserir ordenado: ");
        scanf("%d", &valor);
        if (insere_ordenado(li, valor))
          printf("\nValor inserido com sucesso.\n");
        else
          printf("\nFalha ao inserir valor.\n");
        break;
      case 3:
        printf("\nInforme um valor para inserir no fim: ");
        scanf("%d", &valor);
        if (insere_fim(li, valor))
          printf("\nValor inserido com sucesso.\n");
        else
          printf("\nFalha ao inserir valor.\n");
        break;
      case 4:
        printf("\nVoltando...\n");
        break;
      default:
        break;
      }
      break;
    case 2:
      printf("\n1-Remover do inicio\n2-Remover valor\n3-Remover do fim.\n4-Voltar\nEscolha: ");
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
        printf("\nInforme o valor para remover: ");
        scanf("%d", &valor);
        if (remove_valor(li, valor))
          printf("\nValor removido.\n");
        else
          printf("\nErro ao remover valor.\n");
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
    case 3:
      printf("\n1-Visualizar por posição\n2-Visualizar por valor\n3-Visualizar todas as informações.\n4-Voltar\nEscolha: ");
      scanf("%d", &visualiza);
      switch (visualiza)
      {
      case 1:
        printf("\nInforme a posicao: ");
        scanf("%d", &posicao);
        visualiza_posicao(li, posicao);
        break;
      case 2:
        printf("\nInforme o valor: ");
        scanf("%d", &valor);
        visualiza_valor(li, valor);
        break;
      case 3:
        printf("\nLista: ");
        imprime_lista(li);
        break;
      case 4:
        printf("\nVoltando...");
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

int insere_inicio(Lista *li, int valor)
{
  if (li == NULL)
    return 0;

  No *novo = (No *)malloc(sizeof(No));

  novo->valor = valor;
  novo->proximo = li->inicio;
  novo->anterior = NULL;

  if (li->inicio != NULL) //lista não vazia
    li->inicio->anterior = novo;

  li->inicio = novo;
  li->tamanho++;

  return 1;
}

int insere_fim(Lista *li, int valor)
{
  if (li == NULL)
    return 0;

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

  return 1;
}

int insere_ordenado(Lista *li, int valor)
{
  if (li == NULL)
    return 0;

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

  return 1;
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

int remove_valor(Lista *li, int valor)
{
  if (li == NULL || li->inicio == NULL)
    return 0;

  No *no = li->inicio;

  while (no->proximo != NULL && no->valor != valor)
    no = no->proximo;

  if (no->anterior == NULL)
    li->inicio = no->proximo;
  else
    no->anterior->proximo = no->proximo;

  if (no->proximo != NULL)
    no->proximo->anterior = no->anterior;

  free(no);

  li->tamanho--;
}

void visualiza_valor(Lista *li, int valor)
{
  if (li == NULL || li->inicio == NULL)
    printf("\nLista inexistente.\n");
  else
  {

    No *no = li->inicio;

    while (no->proximo != NULL && no->valor != valor)
      no = no->proximo;

    printf("\nValor: %d\n", no->valor);
  }
}

void visualiza_posicao(Lista *li, int posicao)
{
  if (li == NULL || li->inicio == NULL || posicao <= 0)
    printf("\nLista inexistente.\n");
  else
  {

    No *no = li->inicio;
    int i = 0;
    while (no->proximo != NULL && i < posicao)
    {
      no = no->proximo;
      i++;
    }
    printf("\nValor: %d\n", no->valor);
  }
}