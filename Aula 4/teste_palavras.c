#include "pilha_caracter.h"

int main(){
    char palavra[20];
    t_pilha_caracter pc;
    printf("digite uma palavra: ");
    scanf("%s", palavra);
    constroi_pilha(strlen(palavra), &pc);
    for(int i = 0; i < strlen(palavra); i++){
        push(palavra[i], &pc);
    }
    int e_palindromo = 1;
    int i = 0;
    char aux;
    while(!pilha_vazia(&pc) && e_palindromo){
        pop(&pc, &aux);
        if(palavra[i] != aux){
            e_palindromo = 0;
        }
        else{
            i++;
        }
    }
    if(e_palindromo){
        printf("%s e palindromo\n", palavra);
    }
    else{
        printf("%s nao e palindromo\n", palavra);
    }
    return 0;
}
