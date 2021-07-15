typedef struct no
{
  int valor;
  struct no *proximo;
} No;

typedef struct fila
{
  int tamanho;
  struct no *inicio;
} Fila;

Fila *cria_fila();
void limpa_fila(Fila *fi);

int insere_fila(Fila *fi, int valor);
int remove_fila(Fila *fi);
void exibe_fila(Fila *fi);