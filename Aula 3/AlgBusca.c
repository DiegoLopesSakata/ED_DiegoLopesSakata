#include <stdio.h>

#define TAMANHO 20;

int main(){

    int achou = 0, i, v[TAMANHO], x;
    x = 30;

    for(i = 0; i < TAMANHO && !achou; i++){
        if(v[i] == x){
            achou = 1;
        }
    }

    return 0;
}