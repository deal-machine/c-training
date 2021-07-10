#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sequentialList.h"

void main()
{
  Lista *li;

  Lista *lo;
  lo = cria_lista();
  libera_lista(lo);

  li = cria_lista(); //criando referencia de uma nova lista

  //criando um struct aluno
  struct aluno alu = {132, "Douglas", 10, 7, 9, 5};

  struct aluno alu1 = {248, "Alc", 0, 7, 6, 5};

  struct aluno alu3 = {131, "Edu", 10, 7, 10, 5};

  //insere aluno no final da lista
  int x = insere_final(li, alu);
  int y = insere_inicio(li, alu1);
  int z = insere_ordenado(li, alu3);

  if (lista_cheia(li))
    printf("LISTA CHEIA");
  else if (lista_vazia(li))
    printf("LISTA VAZIA");
  else
    printf("Tamanho da lista: %d", tamanho_lista(li)); //retorna valor em li->alocados
}