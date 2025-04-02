#include <stdio.h>
#include <stdlib.h>

int lanca_dado(){
    int a = 1 + rand() % 6;
    return a;
}

int main(){

    int a;

    printf("Lançamento | Face Dado\n");
    for(int i = 0; i < 6000; i++){
        a = lanca_dado();
        printf("%d: %d  |  ", i + 1, a);
    }

    return 0;
}