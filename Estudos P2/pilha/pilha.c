#include "pilha.h"

void constroi_pilha(t_lista * lista){
    lista->topo = NULL;
}

int pilha_vazia(t_lista * lista){
    return !lista->topo;
}

void insere_valor(int info, t_lista * lista){
    t_no * novo = constroi_no(info);
    if(!pilha_vazia(lista))
        novo->prox = lista->topo;
    lista->topo = novo;
}

int remove_valor(int * info, t_lista * lista){
    if(pilha_vazia(lista)) return 0;
    *info = lista->topo->info;
    t_no * aux = lista->topo;
    lista->topo = lista->topo->prox;
    free(aux);
    return 1;
}

void exibe_lista(t_lista * lista){
    if(pilha_vazia(lista))
        printf("Pilha vazia!\n");
    else{
        t_no * runner = lista->topo;
        while(runner != NULL){
            printf("[%d] -> ", runner->info);
            runner = runner->prox;
        }
        printf("\\\\\n");
    }
}