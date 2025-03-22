#include <stdio.h>
#include <time.h>

int main(){
    int *v;
    int n;
    srand(time(0));
    printf("escolha o tamanho do vetor: ");
    scanf("%d",&n);
    v = (int *) malloc (n * sizeof(int));
    preenche_vetor(v, n);
    exibe_vetor(v, n);
    return 0;
}

void preenche_vetor(int v[], int n){
    for (int i =0; i<n; i++){
        v[i] = rand();
    }
}

int exibe_vetor(int v[], int n){
    for (int i =0; i<n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
}