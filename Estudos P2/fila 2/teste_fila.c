#include "fila.h"

int main(){

    int capacidade;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &capacidade);

    t_fila * fila = constroi_fila(capacidade);

    return 0;
}