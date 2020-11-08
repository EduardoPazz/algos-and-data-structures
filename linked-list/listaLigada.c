/******************************************************************************
//     listaLigadaEstatica.c
// Este programa gerencia listas lineares ligadas (implementacao estatica).
// As listas gerenciadas podem ter MAX elementos (posicoes de 0 a MAX-1 no
//   arranjo A). N�o usaremos sentinela nesta estrutura.
******************************************************************************/
#include <stdio.h>
#define MAX 50
#define INVALIDO -1
#define true 1
#define false 0
typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct{
  REGISTRO reg;
  int prox;
} ELEMENTO;

typedef struct {
  ELEMENTO A[MAX];
  int inicio;
  int dispo;
} LISTA;

/* Inicializa��o da lista sequencial (a lista jah esta criada e eh apontada 
pelo endereco em l) */
void inicializarLista(LISTA* l){
  int i;
  l->inicio=INVALIDO;
  l->dispo=0;
  for (i=0; i<MAX-1; i++)
    l->A[i].prox = i + 1;
  l->A[MAX-1].prox = INVALIDO;
} /* inicializarLista */

/* Exibi��o da lista seq�encial */
void exibirLista(LISTA* l){
  int i = l->inicio;
  printf("Lista: \" ");
  while (i != INVALIDO){
    printf("%d ", l->A[i].reg.chave); // soh lembrando TIPOCHAVE = int
    i = l->A[i].prox;
  }
  printf("\"\n");
} /* exibirLista */ 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  int i = l->inicio;
  int tam = 0;
  while (i != INVALIDO){
    tam++;
    i = l->A[i].prox;
  }
  return tam;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados, pois a alocacao de memoria eh estatica.
   A priori, nao precisariamos do ponteiro para a lista, vamos utiliza-lo apenas
   porque teremos as mesmas funcoes para listas ligadas implementacao nao estatica.   
*/
int tamanhoEmBytes(LISTA* l) {
  return sizeof(LISTA);
} /* tamanhoEmBytes */

/* Busca sequencial (lista ordenada ou nao) */
int buscaSeq(LISTA* l, TIPOCHAVE ch){
  int i = l->inicio;
  while (i != INVALIDO){
    if (l->A[i].reg.chave == ch) return i;
    i = l->A[i].prox;
  }
  return INVALIDO;
} /* buscaSeq */

/* Busca sequencial - funcao de exclusao (retorna no endere�o *ant o indice do
   elemento anterior ao elemento que est� sendo buscado [ant recebe o elemento
   anterior independente do elemento buscado ser ou n�o encontrado]) */
int buscaSeqExc(TIPOCHAVE ch, LISTA* l, int *ant){
  *ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<ch)){
    *ant = i;
    i = l->A[i].prox;
  }
  if ((i != INVALIDO) && (l->A[i].reg.chave == ch)) return i;
  return INVALIDO;
} /* buscaSeqExc */

/* Obter n� dispon�vel e marc�-lo como n�o dispon�vel - esta opera��o ser� usada
  junto com inser��es, por exemplo */
int obterNo(LISTA* l){
  int resultado = l->dispo;
  if (l->dispo != INVALIDO) l->dispo = l->A[l->dispo].prox;
  return resultado;
} /* obterNo */

/* Devolver n� da posi��o j para a lista de n�s dispon�veis - coloca-se o n� j
   como primeiro na lista de dispon�veis */
void devolverNo(LISTA* l, int j){
     l->A[j].prox = l->dispo;
     l->dispo = j;
} /* devolverNo */

bool excluirElemLista(LISTA* l, TIPOCHAVE ch){
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<ch)){
    ant = i;
    i = l->A[i].prox;
  }
  if (i==INVALIDO || l->A[i].reg.chave!=ch) return false; // Aqui quer dizer que o elemento não foi achado

  if (ant == INVALIDO) l->inicio = l->A[i].prox; 
  /* Aqui, para o caso do elemento a ser excluído ser o primeiro */

  else l->A[ant].prox = l->A[i].prox;

  devolverNo(l,i);
  
  return true;
} /* excluirElemListaEnc */


/* Exclus�o do elemento de chave indicada */
bool excluirElemLista2(LISTA* l, TIPOCHAVE ch){
  int ant, i;
  i = buscaSeqExc(ch, l, &ant);
  if (i == INVALIDO) return false;
  if (ant == INVALIDO) l->inicio = l->A[i].prox;
  else l->A[ant].prox = l->A[i].prox;
  devolverNo(l,i);
  return true;
} /* excluirElemListaEnc */


/* Destrui��o da lista sequencial */
void reinicializarLista(LISTA* l) {
  inicializarLista(l);
} /* destruirLista */


/* Inser��o em lista ordenada sem duplica��o */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if (l->dispo == INVALIDO) return false; // se lista cheia, n�o � poss�vel inserir
  int ant, i;
  i = buscaSeqExc(reg.chave, l, &ant); 
  /* Testará se o elemento a ser inserido já existe na lista 
     Se não, retorna INVALIDO e passa no teste a seguir.
     Também mantém atualizado o elemento anterior (ant) do elemento a ser inserido*/
  if (i!=INVALIDO) return false;

  i = obterNo(l); 
  /* Essa função passa para o ponteiro seguinte o cargo de "disponível", e retorna o disponível que
  dará lugar para o novo elemento.  */ 

  l->A[i].reg = reg; // Insere o elemento

  // A partir daqui, será feita a correção dos ponteiros.
  if (ant == INVALIDO) { // o novo elemento ser� o 1o da lista (a lista podia estar vazia ou n�o)
    l->A[i].prox = INVALIDO;
    l->inicio = i;
  } else {  // inser��o ap�s um elemento j� existente
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }  
  return true;
} /* inserirElemListaOrd */


/* Inser��o em lista ordenada sem duplica��o - n�o utilize o m�todo auxiliar */
bool inserirElemListaOrd2(LISTA* l, REGISTRO reg) {
  if (l->dispo == INVALIDO) return false; // se lista cheia, n�o � poss�vel inserir
  int ant = INVALIDO;
  int i = l->inicio;
  while ((i != INVALIDO) && (l->A[i].reg.chave<reg.chave)){
    ant = i;
    i = l->A[i].prox;
  }
  if (i!=INVALIDO && l->A[i].reg.chave==reg.chave) return false;
  i = obterNo(l);
  l->A[i].reg = reg;
  if (ant == INVALIDO) { // o novo elemento ser� o 1o da lista (a lista podia estar vazia ou n�o)
    l->A[i].prox = l->inicio;
    l->inicio = i;
  } else {  // inser��o ap�s um elemento j� existente
    l->A[i].prox = l->A[ant].prox;
    l->A[ant].prox = i;
  }  
  return true;
} /* inserirElemListaOrd2 */
