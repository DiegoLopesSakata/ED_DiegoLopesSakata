#include "caracter.h"

void constroi_pilha(pilha_carac *p, int capacidade){
    p->dados = (char *) malloc (capacidade * sizeof(char));
    p->topo = 0;
    p->capacidade = capacidade;
}

void exibir_pilha(pilha_carac *p){
    printf("--------");
    if(pilha_vazia(p)){
        printf("A pilha esta vazia\n");
    }
    else{
        for(int i = p->topo; i >= 0; i--){
            printf("%c\n", p->dados[i]);
        }
    }
    printf("--------");
}

int pilha_vazia(pilha_carac *p){
    return p->topo == 0;
}

int pilha_cheia(pilha_carac *p){
    return p->topo == p->capacidade;
}

int pop(pilha_carac *p, char *removido){
    if(pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

int push(pilha_carac *p, char carac){
    if(pilha_cheia(p)) return 0;
    p->dados[p->topo++] = carac;
    return 1;
}

int parenteses_corretos(pilha_carac *p){
    for(int i = p->topo; i <= 0; i--){
        if(p->dados[i] == '('){
            if(p->dados[i] == ')'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}