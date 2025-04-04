#include <stdio.h>
#include <string.h>

void bubbleSort(char *v, int tamanho){
    char aux;
    
    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - i - 1; j++){
            if(v[j] > v[j + 1]){
                aux = v[j];
                v[j] = v[j + 1];
                v[j+1] = aux;
            }
        }
    }
}

void exibe(char *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%c ", v[i]);
    }
    printf("\n");
}

int main(){

    char c[] = {"diegolop"};
    int tam = strlen(c);

    printf("Vetor Original:\n");
    exibe(c, tam);
    bubbleSort(c, tam);
    printf("Vetor Ordenado:\n");
    exibe(c, tam);

    return 0;
}