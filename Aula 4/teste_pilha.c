#include "pilha.h"

t_pilha converte_base(int n){
    t_pilha p;
    constroi_pilha(n%2, &p);
    while(n > 1){
        push(n%2, &p);
        n = n%2;
    }
    push(n, &p);
    return p;
}

int main(){
    t_pilha pilha;
    constroi_pilha(10, &pilha);
    exibe_pilha(&pilha);

    push(10, &pilha);
    push(20, &pilha);
    if(push(30, &pilha)){
        printf("30 empilhado com sucesso\n");
    }
    else{
        printf("pilha cheia , nao foi possivel empilhar\n");
    }
    printf("------\n");
    exibe_pilha(&pilha);

    int aux;
    if(pop(&pilha, &aux)){
        printf("%d foi desempilhado\n", aux);
    }
    else{
        printf("pilha vazia, nao foi possivel desempilhar\n");
    }
    printf("------\n");
    exibe_pilha(&pilha);

    int i = 1;
    while(push(i++, &pilha)){
        exibe_pilha(&pilha);
    }
    while(pop(&pilha, &aux)){
        printf("%d foi desempilhado\n", aux);
    }     
    exibe_pilha(&pilha);

    push(10, &pilha);
    push(20, &pilha);
    push(30, &pilha);
    exibe_pilha(&pilha);
    inverte_pilha(&pilha);
    exibe_pilha(&pilha);
    
    return 0;
}