#include "pilha.h"

void constroi_pilha(t_pilha * pilha){
    pilha->topo = NULL;
}

int pilha_vazia(t_pilha * pilha){
    return pilha->topo == NULL;
}

int pop(t_pilha * pilha){
    if(pilha_vazia(pilha)) return 0;
    t_no * aux = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(aux);
    return 1;
}

void push(int valor, t_pilha * pilha){
    t_no * novo = constroi_no(valor);
    if(!pilha_vazia(pilha)){
        novo->prox = pilha->topo;
    }
    pilha->topo = novo;
}

void exibir_pilha(t_pilha * pilha){
    if(pilha_vazia(pilha)){
        printf("Pilha vazia!\n");
    }
    else{
        printf("-----Pilha-----\n");
        t_no * runner = pilha->topo;
        while(runner == NULL){
            printf("%d ", runner->info);
            runner = runner->prox;
        }
    }
}