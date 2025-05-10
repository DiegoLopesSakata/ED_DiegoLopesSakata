#include "pilha.h"

void constroi_pilha(t_pilha *p, int capacidade){
    p->dados = (int *) malloc (capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade;
}

int pilha_cheia(t_pilha *p){
    return p->topo == p->capacidade;
}

int pilha_vazia(t_pilha *p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

int pop(t_pilha *p, int *removido){
    if(pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

int push(t_pilha *p, int dados){
    if(pilha_cheia(p)) return 0;
    p->dados[p->topo++] = dados;
    return 1;
}

void exibe_pilha(t_pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia");
    }
    else{
        for(int i = p->topo-1; i >= 0; i--){
            printf("%d\n", p->dados[i]);
        }
    }
    printf("------\n");
}

int pop_mais(t_pilha *p, int quantidade, int *removidos){
    int a;
    *removidos = 0;
    if(pilha_vazia(p)) return 0;
    if(quantidade > p->topo){
        printf("Nao existem tantos dados para serem retirados da pilha.\n");
    }
    while(pop(p, &a) && *removidos < quantidade){
        printf("O valor %d foi removido\n", a);
        (*removidos)++;
    }   
    return 1;
}

t_pilha* par_impar(t_pilha *p){
    int a, countp = 0, counti = 0;

    for(int i = 0; i < p->topo; i++){
        if(p->dados[i] % 2 == 0){
            countp++;
        }
        else{
            counti++;
        }
    }

    t_pilha *pilhas, aux;
    pilhas = (t_pilha *) malloc (2 * sizeof(t_pilha));
    constroi_pilha(&pilhas[0], countp);
    constroi_pilha(&pilhas[1], counti);
    constroi_pilha(&aux, p->capacidade);
    for(int i = 0; i < p->topo; i++){
        push(&aux, p->dados[i]);
    }

    while(pop(&aux, &a)){
        if(a % 2 == 0){
            push(&pilhas[0], a);
        }
        else{
            push(&pilhas[1], a);
        }
    }

    free(aux.dados);
    return pilhas;
}