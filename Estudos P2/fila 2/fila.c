#include "fila.h"

t_fila * constroi_fila(int capacidade){
    t_fila * fila = (t_fila *) malloc (sizeof(t_fila));
    fila->quantidade = 0;
    fila->ultimo = 0;
    fila->primeiro = 0;
    fila->capacidade = capacidade;
    fila->dados = (int *) malloc (capacidade * sizeof(int));
    return fila;
}

int proximo(int pos, int capacidade){
    return (pos + 1) % capacidade;
}

int fila_cheia(t_fila * fila){
    return fila->quantidade == fila->capacidade;
}

int fila_vazia(t_fila * fila){
    return fila->quantidade == 0;
}

int enfileira(t_fila * fila, int valor){
    if(fila_cheia(fila)) return 0;
    fila->dados[fila->ultimo] = valor;
    fila->quantidade++;
    fila->ultimo = proximo(fila->ultimo, fila->capacidade);
    return 1;
}

int desenfileira(t_fila * fila, int * valor){
    if(fila_vazia(fila)) return 0;
    fila->dados[fila->primeiro];
}

void exibir_fila(t_fila *);