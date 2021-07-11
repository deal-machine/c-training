#define MAX 100

struct pessoa
{
  int idade;
  char nome[30];
};

typedef struct fila Fila;

Fila *cria_fila();

void limpa_fila(Fila *fi);

int tamanho_fila(Fila *fi);

int fila_cheia(Fila *fi);

int fila_vazia(Fila *fi);

int insere_fila(Fila *fi, struct pessoa pe);

int remove_fila(Fila *fi);

int consulta_fila(Fila *fi, struct pessoa *pe);