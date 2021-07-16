#include <iostream>
#include <string>

using namespace std;

class No
{
private:
  No *antes;
  No *depois;
  No *no;
  int valor;
  //
public:
  No(No *antes, No *depois, int valor);
  ~No();
  No *cria_no();
  void libera_no(No *no);
  No *getAntes() { return antes; }
  No *getDepois() { return depois; }
  No *getNo() { return no; }
  No *setNo() { return (No *)malloc(sizeof(No)); }
  int getValor() { return valor; }
};

No::No(No *antes, No *depois, int valor)
{
  antes = antes;
  depois = depois;
  valor = valor;
}

No *cria_no()
{
  No *no = (No *)malloc(sizeof(No));
  return no;
};

class Lista
{
private:
  No *inicio;
  No *ultimo;

public:
  int tamanho;
  Lista();
  ~Lista();
  No *getInicio() { return inicio; }
  void setInicio(No *no) { inicio = no; }
  void libera_lista(Lista li);

  int insere_inicio(int valor);
  int insere_ordenado(Lista *li, int valor);
  int insere_fim(Lista *li, int valor);
  int remove_inicio(Lista *li);
  int remove_fim(Lista *li);
  int remove_valor(Lista *li, int valor);
  void visualiza_valor(Lista *li, int valor);
  void visualiza_posicao(Lista *li, int posicao);
  void imprime_lista(Lista *li);
};

//construtor
Lista::Lista()
{
  inicio = NULL;
  ultimo = NULL;
  tamanho = 0;
};

void Lista::libera_lista(Lista li)
{
  li.~Lista();
}

int Lista::insere_inicio(int valor)
{

  No novo = No(NULL, this->getInicio(), valor);
  novo.setNo();

  No *anterior = inicio->getAntes();

  if (this->inicio != NULL)
    anterior = novo.getNo();

  setInicio(novo.getNo());
  tamanho++;

  return 1;
}

int Lista::insere_fim(Lista *li, int valor)
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
};

int Lista::insere_ordenado(Lista *li, int valor)
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
};

void Lista::imprime_lista(Lista *li)
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

int Lista::remove_inicio(Lista *li)
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
};

int Lista::remove_fim(Lista *li)
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

int Lista::remove_valor(Lista *li, int valor)
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

void Lista::visualiza_valor(Lista *li, int valor)
{
  if (li == NULL || li->inicio == NULL)
    printf("\nLista inexistente.\n");
  else
  {

    No *no = li->inicio;

    while (no->proximo != NULL && no->valor != valor)
      no = no->proximo;

    if (no->valor == valor)
      printf("\nValor: %d\n", no->valor);
    else
      printf("\nValor não encontrado.\n");
  }
}

void Lista::visualiza_posicao(Lista *li, int posicao)
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
};

int main()
{

  Lista lista;

  return 0;
}