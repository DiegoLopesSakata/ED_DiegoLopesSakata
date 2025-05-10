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
int inverte_pilha(t_pilha *p);
int encontrar_valor(t_pilha *p, int x);
t_pilha* par_impar(t_pilha *p);
t_pilha* pilha_decrescente(t_pilha *p1, t_pilha *p2);
t_pilha* binario(int n);
t_pilha* transfere_pilha(t_pilha *p);

#endif