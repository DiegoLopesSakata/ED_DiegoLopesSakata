#include "caracter.h"

#define TAM 100

int main(){
    pilha_carac p;
    char frase[TAM];

    constroi_pilha(&p, TAM);
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';

    for(int i = 0; i < strlen(frase); i++) {
        push(&p, frase[i]);
    }

    exibir_pilha(&p);
    if(palindromo(&p)){
        printf("A frase eh um palindromo\n");
    }
    else{
        printf("A frase nao eh palindromo\n");
    }

    if(parenteses_corretos(&p)){
        printf("A frase tem a parentizacao correta\n");
    }
    else{
        printf("A parentizacao nao esta correta\n");
    }

    return 0;
}