#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preenche_vetor (int *v, int tamanho, int inicio, int fim){
    int x;
    for(int i = 0; i < tamanho; i++){
        x = inicio + rand() % (fim - inicio);
        if(x == inicio){
            x += 1;
            v[i] = x;
        }
        else{
            v[i] = x;
        }
    }
}

int valor_repetido (int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        for(int j = i + 1; j < tamanho; j++){
            if(v[i] == v[j]) return 1;
        }
    }
    return 0;
}

void exibir_vetor(int *v, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d", v[i]);
        if(i == tamanho -1) printf("");
        else printf(" ");
    }
}

int main(){

    int *v, tamanho, ini, fim;
    srand(time(NULL));

    printf("Entre com o tamanho do vetor: ");
    do{
        scanf("%d", &tamanho);
        if(tamanho <= 0){
            printf("O tamanho precisa ser um valor positivo, digite novamente: ");
        }
    }while(tamanho <= 0);

    v = (int *) malloc (tamanho * sizeof(int));
    if(v == NULL){
        printf("Erro de alocacao de memoria.\n");
        return 1;
    }

    do{
        printf("Digite o intervalo que o vetor sera preenchido: ");
        scanf("%d %d", &ini, &fim);
        if(ini > fim){
            printf("O primeiro valor precisa ser maior do que o segundo.\n");
        }
        else if(ini == fim){
            printf("O primeiro valor nao pode ser igual ao segundo.\n");
        }
        else if(ini == fim - 1){
            printf("O primeiro valor precisa ser menor do que o segundo valor - 1.\n");
        }
    }while(ini > fim || ini == fim || ini == fim - 1);

    preenche_vetor(v, tamanho, ini, fim);
    exibir_vetor(v, tamanho);

    if(valor_repetido(v, tamanho)){
        printf("\nExistem valores que se repetem!\n");
    }
    else{
        printf("\nNenhum valor se repete!\n");
    }

    free(v);

    return 0;
}
