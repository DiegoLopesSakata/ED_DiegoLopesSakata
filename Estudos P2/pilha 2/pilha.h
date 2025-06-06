#include "no.h"

typedef struct{
    t_no * topo;
} t_pilha;

void constroi_pilha(t_pilha *);
void exibir_pilha(t_pilha *);
int pop(t_pilha *);
void push(int, t_pilha *);
int pilha_vazia(t_pilha *);