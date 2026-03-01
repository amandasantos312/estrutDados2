#include <arv.h>

Arv R = NULL;

int main() {
    R = arv(arv(arv(NULL, 4, NULL), 2, arv(NULL, 5, NULL)),
            1, 
            arv(NULL, 3, arv(NULL, 6, NULL)));         

    printf("Raiz: " fmt "\n", R->item);        

    return 0;
}
