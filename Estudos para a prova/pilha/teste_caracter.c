#include "caracter.h"

#define TAM 100

int main(){
    pilha_carac p;
    char frase[TAM];

    constroi_pilha(&p, TAM);
    fgets(frase, sizeof(frase), stdin);
    for(int i = 0; i < strlen(frase); i++){
        push(&p, frase[i]);
    }

    exibir_pilha(&p);

    return 0;
}