#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int gera_aleatorio(int n){
    Sleep(500);
    srand(time(NULL));
    int a = rand() % n;
    return a;
}

int gera_aleatorio2(int primeiro, int ultimo){
    Sleep(500);
    srand(time(NULL));
    int a = primeiro + rand() % ultimo;
    return a;
}

int main(){

    int a, b, n, pri, ult;
    n = 100;
    pri = 20;
    ult = 80;

    for(int i = 0; i < 10; i++){
        a = gera_aleatorio(n);
        printf("%d ", a);
    }
    printf("\n\n");
    for(int i = 0; i < 10; i++){
        b = gera_aleatorio2(pri, ult);
        printf("%d ", b);
    }

    return 0;
}