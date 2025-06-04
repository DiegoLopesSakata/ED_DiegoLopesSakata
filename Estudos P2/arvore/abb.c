#include "abb.h"

void constroi_abb(t_abb * abb){
    abb->raiz = NULL;
}

int abb_vazia(t_abb * abb){
    return !abb->raiz;
}

void inserir_rec(t_no * novo, t_no * atual){
    if(atual->info < novo->info){
        if(atual->dir == NULL){
            atual->dir = novo;
        }
        else{
            inserir_rec(novo, atual->dir);
        }
    }
    else{
        if(atual->esq == NULL){
            atual->esq = novo;
        }
        else{
            inserir_rec(novo, atual->esq);
        }
    }
}

void inserir_abb(int info, t_abb * abb){
    t_no * novo = constroi_no(info);
    if(abb_vazia(abb))
        abb->raiz = novo;
    else{
        inserir_rec(novo, abb->raiz);
    }
}

void exibir_rec(t_no * no){
    if(no != NULL){
        exibir_rec(no->esq);
        printf("%d ", no->info);
        exibir_rec(no->dir);
    }
}

void exibir_abb(t_abb * abb){
    if(abb_vazia(abb)){
        printf("Arvore vazia!\n");
    }
    else{
        exibir_rec(abb->raiz);
        printf("\n");
    }
}

int busca_rec(t_no * atual, int x){
    if(atual == NULL) return 0;
    if(atual->info == x) return 1;
    if(x > atual->info){
        busca_rec(atual->dir, x);
    }
    else{
        busca_rec(atual->esq, x);
    }
}

int busca_abb(int x, t_abb * abb){
    if(abb_vazia(abb)) return 0;
    return busca_rec(abb->raiz, x);
}