#include <stdio.h>

void somaprod(int a, int b, int *c, int *d){
    *c = a + b;
    *d = a * b;
}

int main(){

    int soma, prod;
    somaprod(3, 5, &soma, &prod);
    printf("soma = %d, produto = %d\n", soma, prod);

    return 0;
}