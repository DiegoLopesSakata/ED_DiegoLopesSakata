#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *dados;
    int topo;
    int capacidade;
}t_pilha;

void constroi_pilha(t_pilha *p, int capacidade);
int pilha_cheia(t_pilha *p);
int pilha_vazia(t_pilha *p);
int pop(t_pilha *p, int *removido);
int push(t_pilha *p, int dado);
void exibe_pilha(t_pilha *p);
int pop_mais(t_pilha *p, int quantidade, int *removidos);
t_pilha* par_impar(t_pilha *p);

#endif