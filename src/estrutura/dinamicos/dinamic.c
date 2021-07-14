#include <stdlib.h>
#include <stdio.h>

struct pessoa
{
  int idade;
  char nome[30];
  float peso;
};

typedef struct elemento *Lista;

struct elemento
{
  struct pessoa dados;
  struct elemento *prox;
};
typedef struct elemento Elem;

Lista *cria_lista()
{
  Lista *li = (Lista *)malloc(sizeof(Lista));
  if (li != NULL)
    *li = NULL;

  return li;
}

void libera_lista(Lista *li)
{
  if (li != NULL)
  {
    Elem *no;
    while ((*li) != NULL)
    {
      no = *li;
      *li = (*li)->prox;
      free(no);
    }
    free(li);
  }
}

int tamanho_lista(Lista *li)
{
  if (li == NULL)
    return 0;

  int cont = 0;
  Elem *no = *li;
  while (*li != NULL)
  {
    cont++;
    no = no->prox;
  }
  return cont;
}

int lista_vazia(Lista *li)
{
  if (li == NULL || *li == NULL)
    return 1;

  return 0;
}

int insere_inicio(Lista *li, struct pessoa pe)
{
  if (li == NULL)
    return 0;

  Elem *no = (Elem *)malloc(sizeof(Elem));

  if (no == NULL)
    return 0;

  no->dados = pe;
  no->prox = (*li);
  *li = no;

  return 1;
}

int insere_fim(Lista *li, struct pessoa pe)
{
  if (li == NULL)
    return 0;

  Elem *no = (Elem *)malloc(sizeof(Elem));
  no->dados = pe;
  no->prox = NULL;

  if ((*li) == NULL) //lista vazia
    *li = no;
  else
  {
    Elem *aux = *li;
    while (aux->prox != NULL)
      aux = aux->prox;

    aux->prox = no;
  }

  return 1;
}

int main(void)
{
  Lista *li;

  li = cria_lista();
  struct pessoa p = {26, "Douglas", 60.0};
  struct pessoa p1 = {28, "Eduardo", 70.0};

  int x = insere_inicio(li, p);
  // int y = insere_fim(li, p1);

  int estaVazia = lista_vazia(li);
  int tamanho = tamanho_lista(li);

  printf("Tamanho lista: %d\n", tamanho);
  printf("Lista vazia: %d\n", estaVazia);

  libera_lista(li);

  system("pause");
  return 0;
}