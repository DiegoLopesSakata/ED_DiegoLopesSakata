#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lança_dado(){
    int a = 1 + rand() % 6
    return a;
}

int main(){

    int a;

    for(int i = 1; i <= 6000; i++){
        a = lança_dado();
        printf("")
    }

    return 0;
}