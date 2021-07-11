#define MAX 100

struct produto
{
  int codigo;
  char nome[30];
  float valor;
};
typedef struct pilha Pilha;

Pilha *cria_pilha();

void libera_pilha(Pilha *pi);

int pilha_cheia(Pilha *pi);

int pilha_vazia(Pilha *pi);

int tamanho_pilha(Pilha *pi);

int insere_pilha(Pilha *pi, struct produto prod);

int remove_pilha(Pilha *pi);

int consulta_pilha(Pilha *pi, struct produto *prod);