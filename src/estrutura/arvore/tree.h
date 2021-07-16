
typedef struct no
{
  int valor;
  int alturaEsquerda;
  int alturaDireita;
  struct no *esquerda;
  struct no *direita;
} No;

typedef struct arvore
{
  int altura;
  int total;
  struct no *raiz;
} Arvore;

Arvore *cria_arvore();
No *cria_no(int valor);
void limpa_arvore(Arvore *ar);
void limpa_filhos(No *no);
int arvore_vazia(Arvore *ar);
int arvore_total(Arvore *ar);
void imprime_pre(No *no);
void imprime_ordem(No *no);
void imprime_pos(No *no);
void insere_valor(Arvore *ar, int valor);
No *remove_no(No *no);
void remove_valor(Arvore *ar, int valor);
int consulta_arvore(Arvore *ar, int valor);
