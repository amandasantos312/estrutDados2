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

    printf("Pos Ordem(esq/dir/r): ");
    posOrdem(R);

    printf("\nEm Ordem(esq/r/dir): ");
    emOrdem(R);

    printf("\nPre Ordem(r/esq,dir): ");
    preOrdem(R);

    printf("\nTotal de nos: %d\n", nos(R));
    printf("Total de folhas: %d\n", folhas(R));

    if(tem(R, 5)) {
        printf("\nO item 5 esta na arvore!\n");
    } else {
        printf("Item nao encontrado!");
    }

    printf("\nEstritamente binaria (1-sim 0-nao)");
    int resultado = eb(R);
    printf("\n%d", resultado);

    




    destroi(&R);      

    return 0;
}