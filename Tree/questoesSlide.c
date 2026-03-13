#include "arv.h"

int main() {
    
    Arv R = NULL;
    ins(5, &R); ins(7, &R), ins(3, &R); ins(9, &R); ins(1, &R);
    ins(6, &R); ins(4, &R); ins(8, &R); ins(0, &R); ins(2, &R);


    printf("\nTotal de nos: %d\n", nos(R));

    printf("\nAltura da arvore: %d\n", altura(R));

    ehCheia(R);

    ehCompleta(R);

    destroi(&R);

    return 0;
}