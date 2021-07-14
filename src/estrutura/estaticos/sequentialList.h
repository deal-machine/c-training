#define MAX 100

struct aluno
{
  int matricula;
  char nome[30];
  float nota1, nota2, nota3, nota4;
};

typedef struct lista Lista;

Lista cria_lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_final(Lista *li, struct aluno alu);

int insere_inicio(Lista *li, struct aluno alu);

int insere_ordenado(Lista *li, struct aluno alu);

int remove_inicio(Lista *li);

int remove_meio(Lista *li);

int remove_fim(Lista *li);

int consulta_posicao(Lista *li, int posicao, struct aluno *alu);

int consulta_valor(Lista *li, int valor, struct aluno *alu);
