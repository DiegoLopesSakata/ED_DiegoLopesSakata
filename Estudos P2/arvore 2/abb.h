#include "no.h"
#include <stdio.h>

typedef struct{
    t_no * raiz;
} t_abb;

void inicia_abb(t_abb *);
int abb_vazio(t_abb *);
void insere_abb(int, t_abb *);
void imprime_abb(t_abb *);
int busca_abb(int, t_abb *);