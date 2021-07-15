
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
