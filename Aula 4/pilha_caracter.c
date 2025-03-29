#include "pilha_caracter.h"

void constroi_pilha(int capacidade, t_pilha_caracter *p){
    p->dados = (char *) malloc (capacidade);
    p->topo = 0;
    p->capacidade = capacidade;
}

int pilha_vazia(t_pilha_caracter *p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

int pilha_cheia(t_pilha_caracter *p){
    return p->topo == p->capacidade;
}

int push (char i, t_pilha_caracter *p){
    if(pilha_cheia(p)) return 0;
    p->dados[p->topo++] = i;
    return 1;
}

int pop (t_pilha_caracter *p, char *removido){
    if(pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

void exibe_pilha(t_pilha_caracter *p){
    if(pilha_vazia(p)) printf("pilha vazia\n");
    else{
        for(int i = p->topo-1; i >= 0; i--){
            printf("%c\n", p->dados[i]);
        }
    }
    printf("------\n");
}

int inverte_pilha(t_pilha_caracter *p){
    t_pilha_caracter *invertida;
    invertida = (t_pilha_caracter *) malloc (sizeof(t_pilha_caracter));
    constroi_pilha(p->capacidade, invertida);
    char aux;
    while(pop(p, &aux)){
        push(aux, invertida);
    }
    p->dados = invertida->dados;
    p->topo = invertida->topo;
    
    return 1;
}