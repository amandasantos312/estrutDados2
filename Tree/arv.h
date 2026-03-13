#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define fmt "%d "
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
    if (A == NULL) return 0;

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

//Altura de uma árvore:
int altura(Arv A) {
    if (A == NULL) return 0;

    int h_esq = altura(A->esq);
    int h_dir = altura(A->dir);

    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

//Destruição de árvore binária:
void destroi(Arv *A) {
    if (A == NULL) return;
    destroi(&(*A)->esq);
    destroi(&(*A)->dir);
    free(*A);
    *A = NULL;
}

//ÁRVORE DE BUSCA BINÁRIA

//Inserção:
void ins(Item x, Arv *A) {
    if (*A == NULL) *A = arv(NULL, x, NULL);
    else if (x <= (*A)->item) ins(x, &(*A)->esq);
    else ins(x, &(*A)->dir);
}

//Busca:
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

//Remoção:
Item remMax(Arv *A) {
    if (*A == NULL) abort();
    while ((*A)->dir != NULL) A = &(*A)->dir;
    Arv n = *A;
    Item x = n->item;
    *A = n->esq;

    free(n);
    return x;
}

void rem(Item  x, Arv *A) {
    if (*A == NULL) return;

    if (x == (*A)->item) {
        Arv n = *A;
        if (n->esq == NULL) *A = n->dir;
        else if (n->dir == NULL) *A = n->esq;
        else n->item = remMax(&n->esq);
        if (n != *A) free(n);
    }
    else if (x <= (*A)->item) rem(x, &(*A)->esq);
    else rem(x, &(*A)->dir);
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

void ehCheia(Arv A) {
    if (A == NULL){
        printf("\nA arvore esta vazia e cheia por definicao!\n");
    }

    int h = altura(A);
    int n = nos(A);

    if (n == pow(2, h) - 1) {
        printf("\nA arvore eh cheia!");
    } else {
        printf("\nA arvore nao eh cheia!");
    }
}

void ehCompleta(Arv A) {
    if (A == NULL) {
        printf("\nA arvore esta vazia e completa por definicao!\n");
    }

    int n = nos(A);
    int h_real = altura(A);

    int h_min = 1 + floor(log2(n));

    if (h_real == h_min) {
        printf("\nA arvore eh completa!");
    } else {
        printf("\nA arvore nao eh completa!");
    }
}

void remFusao(Item x, Arv *A) {

    if (*A == NULL) return;

    if (x < (*A)->item) remFusao(x, &(*A)->esq);

    else if (x > (*A)->item) remFusao(x, &(*A)->dir);

    else {
        Arv n = *A;

        if (n->esq == NULL) *A = n->dir;

        else if (n->dir == NULL) *A = n->esq;

        else {
            Arv p = n->esq;

            while (p->dir != NULL)
                p = p->dir;

            p->dir = n->dir;
            *A = n->esq;
        }
        free(n);
    }
}