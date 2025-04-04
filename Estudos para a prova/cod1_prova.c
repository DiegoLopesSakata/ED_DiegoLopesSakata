#include <stdio.h>
#include <stdlib.h>
    
int valor_repetido(int *v, int n, int x){
    int repetido = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == x) repetido++;
    }
    return repetido;
}

int main(){

    int *v, n, x;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);
    v = (int *) malloc (n * sizeof(int));

    for(int i = 0; i < n; i++){
        if(i % 2 == 0) v[i] = 3;
        else{
            v[i] = i;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Digite o numero que vc deseja procurar no vetor: ");
    scanf("%d", &x);

    int c = valor_repetido(v, n, x);

    printf("%d se repete %d no vetor\n", x, c);

    return 0;
}