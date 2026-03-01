#include "arv.h"

int main() {
    Arv R = arv(arv(arv(NULL, 
                        4, NULL), 
                    2, arv(NULL, 
                        5, NULL)),
                1, 
                arv(NULL, 
                    3, 
                    arv(NULL,
                        6, 
                        NULL))); 

    printf("Exibicao Em Ordem: ");
    emOrdem(R);

    destroi(&R);      

    return 0;
}