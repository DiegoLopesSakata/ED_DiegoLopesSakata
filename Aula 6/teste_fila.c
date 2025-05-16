#include "fila.h"

int main(){
    t_fila * fila;
    int *pi = (int *) malloc (sizeof(int));
    fila = constroi_fila(4);
    printf("fila construida\n");
    mostra_fila(fila);
    if(enfileira(10, fila))
        printf("Insercao realizada com sucesso!\n");
    else
        printf("falha na insercao, fila cheia!\n");
    enfileira(20, fila);
    printf("10 e 20 enfileirados\n");
    mostra_fila(fila);
    if(desenfileira(pi, fila)){
        printf("%d saiu da fila\n", *pi);
    }
    else{
        printf("falha no desenfileiramento, fila vazia");
    }
    mostra_fila(fila);
    enfileira(30, fila);
    enfileira(40, fila);
    printf("30 e 40 enfileirados\n");
    mostra_fila(fila);


    return 0;
}
