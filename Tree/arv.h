#include <stdio.h>
#include <stdlib.h>

#define fmt "%d"
typedef int Item;
typedef struct arv {
    struct arv *esq;
    Item item;
    struct arv *dir;
} *Arv;

Arv arv (Arv e, Item x, Arv d) {
    Arv n = malloc(sizeof(struct arv));
    n->esq = e;
    n->item = x;
    n->dir = d;

    return n;
}

//Em Ordem:
void emOrdem(Arv A) {
    if (A == NULL) return;
    emOrdem(A->esq);
    printf(fmt, A->item);
    emOrdem(A->dir);
}

//Pre Ordem:
void preOrdem(Arv A) {
    if (A == NULL) return;
    printf(fmt, A->item);
    preOrdem(A->esq);
    preOrdem(A->dir);   
}

//Pos Ordem:
void posOrdem(Arv A) {
    if (A == NULL) return;
    posOrdem(A->esq);
    posOrdem(A->dir);
    printf(fmt, A->item);
}

//Total de nós:
int nos(Arv A) {
    if (A == NULL) {
        return 0;
    }
    return 1 + nos(A->esq) + nos(A->dir);
}

//Total de folhas:
int folhas(Arv A) {
    if (A == NULL) return 0;

    //Se não tem filhos à esquerda nem à direita, é uma folha!
    if (A->esq == NULL && A->dir == NULL) return 1;

    //Se não for folha, continua procurando nos dois lados
    return folhas(A->esq) + folhas(A->dir);
}

//Destruição de árvore binária:
void destroi(Arv *A) {
    if (A == NULL) return;
    destroi(&(*A)->esq);
    destroi(&(*A)->dir);
    free(*A);
    *A = NULL;
}

//Inserção em árvore de busca binária:
void ins(Item x, Arv *A) {
    if (*A == NULL) *A = arv(NULL, x, NULL);
    else if (x <= (*A)->item) ins(x, &(*A)->esq);
    else ins(x, &(*A)->dir);
}

//Busca em árvore de busca binária:
int busca(Item x, Arv A) {
    if (A == NULL) return 0; 
    if (x == A->item) return 1;

    if (x <= A->item) return busca(x, A->esq);
    else return busca(x, A->dir);
}

int tem(Arv A, Item x) {
    if (A == NULL) return 0;

    if (x == A->item) return 1;

    return tem(A->esq, x) || tem(A->dir, x);
}

//Estritamente binária:
int eb(Arv A) {
    //Árvore vazia é estritamente binária
    if (A == NULL) return 1;

    // Se for uma folha (zero filhos), é tbm
    if (A->esq == NULL && A->dir == NULL) return 1;

    // Se tiver os dois filhos, precisamos verificar se os filhos também são estritamente binários
    if (A->esq != NULL && A->dir != NULL) {
        return eb(A->esq) && eb(A->dir);
    }
}




//Remoção em árvore de busca binária:
Item remMax(Arv *A) {
    if (*A == NULL) abort();
    while ( (*A)->dir != NULL) A = &(*A)->dir;
    Arv n = *A;
    Item x = n->item;
    *A = n->esq;

    free(n);
    return x;
}