struct pessoa
{
  int idade;
  char nome[30];
  float peso;
};

typedef struct elemento *Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_vazia(Lista *li);

int insere_inicio(Lista *li, struct pessoa pe);