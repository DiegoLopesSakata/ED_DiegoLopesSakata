#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *dados;
    int topo;
    int capacidade;
} pilha_carac;

void constroi_pilha(pilha_carac *p, int capacidade);
void exibir_pilha(pilha_carac *p);
int pilha_vazia(pilha_carac *p);
int pilha_cheia(pilha_carac *p);
int pop(pilha_carac *p, char *removido);
int push(pilha_carac *p, char carac);
int parenteses_corretos(pilha_carac *p);