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