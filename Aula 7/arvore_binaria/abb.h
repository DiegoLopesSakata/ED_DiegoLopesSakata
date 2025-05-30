//abb = arvore binaria de busca
//bst = binary search tree

#include "no.h"

typedef struct{
    t_no * raiz;
}t_abb;

void inicia_abb(t_abb *);
int abb_vazia(t_abb *);
void insere(int, t_abb *);
void imprime(t_abb *);
int busca (int, t_abb *);