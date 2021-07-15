#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
  int valor;
  struct no *proximo;
} No;

typedef struct pilha
{
  int tamanho;
  struct no *inicio;
} Pilha;

Pilha *cria_pilha();
void limpa_pilha(Pilha *pi);

int insere_pilha(Pilha *pi, int valor);
int remove_pilha(Pilha *pi);
void visualiza_pilha(Pilha *pi);

int main()
{
  Pilha *pi = cria_pilha();
  int escolha = 0, valor;

  do
  {
    printf("\n******************************\nPILHA\nInforme uma opção\n\n1-Inserir\n2-Remover valor\n3-Visualizar\nQualquer outra tecla para sair\n******************************\nEscolha: ");
    scanf("%d", &escolha);
    switch (escolha)
    {
    case 1:
      printf("\nInforme o valor: ");
      scanf("%d", &valor);
      if (insere_pilha(pi, valor))
        printf("\nValor inserido com sucesso.\n");
      else
        printf("\nErro ao inserir valor.\n");
      break;
    case 2:
      if (remove_pilha(pi))
        printf("\nValor removido com sucesso.\n");
      else
        printf("\nErro ao remover valor.\n");
      break;
    case 3:
      visualiza_pilha(pi);
      break;
    case 4:
      printf("\nSaindo...\n");
      break;
    default:
      escolha = 0;
      printf("\nSaindo...\n");
      break;
    }
  } while (escolha >= 1 && escolha <= 3);

  limpa_pilha(pi);

  system("pause");
  return 0;
}

Pilha *cria_pilha()
{
  Pilha *pi = (Pilha *)malloc(sizeof(Pilha));

  return pi;
}

void limpa_pilha(Pilha *pi)
{
  free(pi);
}

int insere_pilha(Pilha *pi, int valor)
{
  if (pi == NULL)
    return 0;

  No *no = (No *)malloc(sizeof(No));

  no->valor = valor;
  no->proximo = pi->inicio;
  pi->inicio = no;

  pi->tamanho++;

  return 1;
}

int remove_pilha(Pilha *pi)
{
  if (pi == NULL || pi->inicio == NULL)
    return 0;

  No *aux = pi->inicio;

  pi->inicio = aux->proximo;

  free(aux);

  pi->tamanho--;

  return 1;
}

void visualiza_pilha(Pilha *pi)
{
  if (pi == NULL)
    printf("\nLista inexistente.\n");
  else if (pi->inicio == NULL)
    printf("\nLista vazia.\n");
  else
  {
    No *no = pi->inicio;
    while (no != NULL)
    {
      printf("\n| %d |\n", no->valor);
      no = no->proximo;
    }

    printf("\nTamanho da pilha: %d\n", pi->tamanho);
  }
}