#include <time.h>
#include "fila.h"

int main(){
    t_fila * fila = constroi_fila();
    int a;
    srand(time(0));
    do{
        if(rand() % 2){
            enfileira(rand() % 10, fila);
        }
        else{
            desenfileira(&a, fila);
        }
        mostra_fila(fila);
    }while(!fila_vazia(fila));

    for(int i = 0; i < 12; i++){
        enfileira(rand () % 10, fila);
    }

    t_fila ** separada = (t_fila **) malloc (2 * sizeof(t_fila));
    separada = par_impar(fila);
    printf("\nFila Original\n");
    mostra_fila(fila);
    printf("\nFila par\n");
    mostra_fila(separada[0]);
    printf("\nFila impar\n");
    mostra_fila(separada[1]);

    printf("\nTeste - esvazia uma fila\n\n");
    esvazia_menor(separada[0], separada[1]);
    mostra_fila(separada[0]);
    mostra_fila(separada[1]);

    return 0;
}