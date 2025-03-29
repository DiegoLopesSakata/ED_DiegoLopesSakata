#include <stdio.h>
int main(){
    int a = 100;
    printf("Valor de a (Decimal) = %d\n", a);
    printf("Valor de a (Hexadecimal) = %x\n", a);
    printf("Endereco de a = %p\n", &a);
    printf("Caracter equivalente de a: %c \n", a);
    // printf("String de a: %s\n", a); erro de acesso à memória
    printf("string de referencia de a: %s\n" ,&a);
    return 0;
}