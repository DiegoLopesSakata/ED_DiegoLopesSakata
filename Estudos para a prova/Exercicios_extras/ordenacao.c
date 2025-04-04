#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int *v, int tamanho){
    int aux;
    
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho - i; j++){
            if(v[j] < v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j+1] = aux;
            }
        }
    }
}

void preencher(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        v[i] = rand() % tamanho;
    }
}

void exibe(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(){

    int *v, tam;
    srand(time(NULL));

    printf("Digite o tamanho do vetor: ");
    do{
        scanf("%d", &tam);
        if(tam <= 0){
            printf("O tamanho do vetor precisa ser maior do que 0: ");
        }
    }while(tam <= 0);

    v = (int *) malloc (tam * sizeof(int));
    preencher(v, tam);
    printf("Vetor Original:\n");
    exibe(v, tam);
    bubbleSort(v, tam);
    printf("Vetor Ordenado:\n");
    exibe(v, tam);

    return 0;
}