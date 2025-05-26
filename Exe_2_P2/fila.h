#include <stdio.h>
#include "no.h"

typedef struct{
    t_no * primeiro;
    t_no * ultimo;
} t_fila;

t_fila * constroi_fila();
int fila_vazia(t_fila *);
int enfileira(int, t_fila *);
int desenfileira(int *, t_fila *);
void mostra_fila(t_fila *);
t_fila ** par_impar(t_fila *);
int esvazia_menor(t_fila *, t_fila *);