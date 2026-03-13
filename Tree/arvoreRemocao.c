#include "arv.h"

int main() {
    Arv R = NULL;

    ins(8, &R);
    ins(3, &R);
    ins(11, &R);
    ins(1, &R);
    ins(4, &R);
    ins(10, &R);
    ins(13, &R);
    ins(0, &R);
    ins(2, &R);
    ins(6, &R);
    ins(12, &R);
    ins(14, &R);
    ins(5, &R);
    ins(7, &R);

    printf("Arvore Antes: ");
    preOrdem(R);

    printf("\nAltura: %d", altura(R));
    printf("\nNos: %d", nos(R));

    printf("\n-----> Remocao por Copia: <-----\n");
    rem(8, &R);
    preOrdem(R);

    /*printf("\n-----> Remocao por Fusao: <-----");
    remFusao(8, &R);*/

    destroi(&R);

    //Elas são diferentes, uma a raiz vira o 7 e a outra a raiz é o 3, e possuem níveis diferentes.
    return 0;

}