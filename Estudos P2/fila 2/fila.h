#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int * dados;
    int primeiro, ultimo;
    int capacidade, quantidade;
}t_fila;

t_fila * constroi_fila(int);
int fila_cheia(t_fila *);
int fila_vazia(t_fila *);
int enfileira(t_fila *, int);
int desenfileira(t_fila *, int *);
void exibir_fila(t_fila *);