#include <stdio.h>
#include <stdlib.h>

int lanca_dado(){
    int a = 1 + rand() % 6;
    return a;
}

int lanca_moeda(){
    int a = rand() % 2;
    return a;
}

int main(){

    int a, b;

    printf("Lançamento | Face Dado | Face Moeda\n");
    for(int i = 0; i < 6000; i++){
        a = lanca_dado();
        b = lanca_moeda();
        printf("%d: %d %d  |  ", i + 1, a, b);
    }

    return 0;
}