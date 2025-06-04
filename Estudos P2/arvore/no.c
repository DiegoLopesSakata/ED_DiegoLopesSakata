#include "no.h"

t_no * constroi_no(int info){
    t_no * novo = (t_no *) malloc (sizeof(t_no));
    if(novo != NULL){
        novo->info = info;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}