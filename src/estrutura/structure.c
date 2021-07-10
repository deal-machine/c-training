#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sequentialList.h"
#include "sequentialStack.h"

int main(void)
{
  Lista *li;
  Pilha *pi;

  //criando referencia de uma nova lista
  li = &cria_lista();
  //criando um struct aluno
  struct aluno alu = {132, "Douglas", 10, 7, 9, 5};

  //insere aluno no final da lista
  int x = insere_final(li, alu);
  int y = insere_inicio(li, alu);
  int z = insere_ordenado(li, alu);

  if (lista_cheia(li))
    printf("LISTA CHEIA");
  else if (lista_vazia(li))
    printf("LISTA VAZIA");
  else
    printf("Tamanho da lista: %d", tamanho_lista(li)); //retorna valor em li->alocados

  pi = cria_pilha();
  libera_pilha(pi);

  system("pause");
  return 0;
}