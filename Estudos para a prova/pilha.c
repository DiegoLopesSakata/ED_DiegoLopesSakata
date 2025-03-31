#include "pilha.h"

void constroi_pilha(t_pilha *p, int capacidade){
    p = (t_pilha *) malloc (capacidade * sizeof(t_pilha));
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

int push(t_pilha *p, int dado){
    if(pilha_cheia(p)) return 0;

}

void exibe_pilha(t_pilha *p);
int pop_mais(t_pilha *p, int quantidade);
int inverte_pilha(t_pilha *p);