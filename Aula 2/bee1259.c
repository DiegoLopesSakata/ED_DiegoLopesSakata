// Ta errado

#include <stdio.h>
#include <stdlib.h>

int particiona(int *v, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = v[inicio];
    while(esq < dir){
        while(v[esq] <= pivo)
            esq++;
        while(v[dir] > pivo)
            dir--;
        if(esq < dir){
            aux = v[esq];
            v[esq] = v[dir];
            v[dir] = aux;
        }
    }
    v[inicio] = v[dir];
    v[dir] = pivo;
    return dir;
}

void quickSort(int *v, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(v, inicio, fim);
        quickSort(v, inicio, pivo - 1);
        quickSort(v, pivo + 1, fim);
    }
}

int main(){

    int n, x, *par, *imp;
    int contp = 0;
    int conti = 0;
    scanf("%d", &n);
    par = (int *) malloc (n * sizeof(int));
    imp = (int *) malloc (n * sizeof(int));

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x % 2 == 0){
            par[contp] = x;
            contp++;
        }
        else{
            imp[conti] = x;
            conti++;
        }
    }

    quickSort(par, 0, n);
    quickSort(imp, 0, n);

    for(int i = 0; i < n; i++){
        printf("%d\n", par[i]);
    }

    for(int i = n-1; i >= 0; i--){
        printf("%d\n", imp[i]);
    }

    return 0;
}