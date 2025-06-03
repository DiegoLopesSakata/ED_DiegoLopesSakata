//fila sobre vetor circular

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int * dados;
    int primeiro, ultimo;
    int capacidade, ocupacao;
} t_fila;

t_fila * constroi_fila(int);
int fila_cheia(t_fila *);
int fila_vazia(t_fila *);
int inserir_fila(int, t_fila *);
int remover_fila(int *, t_fila *);
void exibe_fila(t_fila *);
void exibe_vetor(t_fila *);