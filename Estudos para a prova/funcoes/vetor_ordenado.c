#include <stdio.h>

void bubbleSort(int a[], int cont){
    int aux;

    for(int i = 0; i < cont; i++){
        for(int j = 0; j < cont - i; j++){
            if(a[j] > a[j+1] ){
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}

void exibe_vetor(int a[], int cont){
    printf("-------------\n");
    for(int i = -1; i < cont; i++){
        printf("%d\n", a[i+1]);
    }
    printf("-------------\n");
}

int main(){

    int a[8];
    int cont = 0;

    for(int i = 0; i < 8; i++){
        scanf("%d", &a[i]);
        bubbleSort(a, cont);
        exibe_vetor(a, cont);
        cont++;
    }

    return 0;
}