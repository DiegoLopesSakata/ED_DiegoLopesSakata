#include <stdio.h>

void celsius_fahrenheit(float c){
    c = (c * 1.8) + 32;
    printf("Fahrenheit: %.2f\n", c);
}

void fahrenheit_celsius(float f){
    f = (f - 32) / 1.8;
    printf("Celsius: %.2f\n", f);
}

void escolha(){
    printf("Escolha a conversao que vc deseja:\n");
    printf("1. Celsius para Fahrenheit\n");
    printf("2. Fahrenheit para Celsius\n");
    printf("-1. Sair\n");
}

int main(){

    int decisao;
    float a; 

    do{
        escolha();
        scanf("%d", &decisao);
        switch(decisao){
            case 1: printf("Digite a temperatura em Celsius: ");
                    scanf("%f", &a);
                    celsius_fahrenheit(a);
                    break;
            case 2: printf("Digite a temperatura em Fahrenheit: ");
                    scanf("%f", &a);
                    fahrenheit_celsius(a);
                    break;
            case -1: printf("Saindo...\n");
                     return 1;
            default: printf("o valor %d nao eh uma opcao.\n", decisao);
        }
    }while(1);

    return 0;
}