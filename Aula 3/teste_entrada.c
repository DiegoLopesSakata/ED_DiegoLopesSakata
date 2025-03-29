#include <stdio.h>

//ler uma sequencida de numeros, até encontrar EOF, somá-los e exibir a soma;

int main(){

    int a, b, n;   
    
    // printf("digite 2 numeros: ");
    // n = scanf("%d%d", &a, &b);
    // printf("n = %d\n", n);

    while((scanf("%d", &a)) != EOF){
        printf("%d\n", a);
    }
    printf("acabou arquivo");

    return 0;
}