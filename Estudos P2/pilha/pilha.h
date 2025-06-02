// pilha sobre lista ligada

#include <stdio.h>
#include "no.h"

typedef struct{
    t_no * topo;
}t_lista;

void constroi_pilha(t_lista *);
int pilha_vazia(t_lista *);
void insere_valor(int, t_lista *);
int remove_valor(int *, t_lista *);
void exibe_lista(t_lista *);
