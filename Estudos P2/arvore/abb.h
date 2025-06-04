#include <stdio.h>
#include "no.h"

typedef struct{
    t_no * raiz;
} t_abb;

void constroi_abb(t_abb *);
int abb_vazia(t_abb *);
void inserir_abb(int, t_abb *);
void exibir_abb(t_abb *);
int busca_abb(int, t_abb *);