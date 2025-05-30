#include "abb.h"

void inicia_abb(t_abb * abb){
    abb->raiz = NULL;
}

int abb_vazia(t_abb * abb){
    return !abb->raiz; 
}

void insere_rec(t_no * novo, t_no * atual){
    if(novo->info > atual->info){ //vai para a direita
        if(atual->dir == NULL)
            atual->dir = novo;
        else
            insere_rec(novo, atual->dir);
    }
    else{ //vai para a esquerda
        if(atual->esq == NULL)
            atual->esq = novo; 
        else
            insere_rec(novo, atual->esq);
    }
}

void insere(int info, t_abb * abb){
    t_no * novo = constroi_no(info);
    if(abb_vazia(abb)){
        abb->raiz = novo;
    }
    else{
        insere_rec(novo, abb->raiz);
    }
}

void imprime_rec (t_no * atual){
    if(atual != NULL){
        imprime_rec(atual->esq);
        printf("%d ", atual->info);
        imprime_rec(atual->dir);
    }
}

void imprime (t_abb * abb){
    if(abb_vazia(abb)) printf("A arvore esta vazia!");
    else imprime_rec(abb->raiz);
    printf("\n");
}

int busca_rec(int x, t_no * atual){
    if(atual == NULL) return 0;
    if(atual->info == x) return 1;
    if(atual->info < x) busca_rec(x, atual->dir);
    return busca_rec(x, atual->esq);
}

int busca (int x, t_abb * abb){
    //devolver 1 (verdadeiro), se x estiver na árvore, ou 0 (falso), caso contrário
    if(abb_vazia(abb)) return 0;
    return busca_rec(x, abb->raiz);
}