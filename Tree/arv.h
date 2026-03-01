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
void emordem(Arv A) {
    if (A == NULL) return;
    emordem(A->esq);
    printf(fmt, A->item);
    emordem(A->dir);
}

//Pre Ordem:
void preordem(Arv A) {
    if (A == NULL) return;
    printf(fmt, A->item);
    preordem(A->esq);
    preordem(A->dir);   
}

//Pos Ordem:
void posordem(Arv A) {
    if (A == NULL) return;
    posordem(A->esq);
    posordem(A->dir);
    printf(fmt, A->item);
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

//Remoção em árvore de busca binária:
Item remmax(Arv *A) {
    if (*A == NULL) abort();
    while ( (*A)->dir != NULL) A = &(*A)->dir;
    Arv n = *A;
    Item x = n->item;
    *A = n->esq;

    free(n);
    return x;
}