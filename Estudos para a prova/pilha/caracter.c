#include "caracter.h"

void constroi_pilha(pilha_carac *p, int capacidade){
    p->dados = (char *) malloc (capacidade * sizeof(char));
    p->topo = 0;
    p->capacidade = capacidade;
}

void exibir_pilha(pilha_carac *p){
    printf("--------\n");
    if(pilha_vazia(p)){
        printf("A pilha esta vazia\n");
    }
    else{
        for(int i = p->topo - 1; i >= 0; i--){
            printf("%c\n", p->dados[i]);
        }
    }
    printf("--------\n");
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

int parenteses_corretos(pilha_carac *p) {
    pilha_carac a;
    constroi_pilha(&a, p->capacidade);

    for (int i = 0; i < p->topo; i++) {
        if (p->dados[i] == '(' || p->dados[i] == '[' || p->dados[i] == '{') {
            push(&a, p->dados[i]);
        }
        else if (p->dados[i] == ')' || p->dados[i] == ']' || p->dados[i] == '}') {
            if (pilha_vazia(&a)) {
                return 0; 
            }
            char topo;
            pop(p, &topo);
            if ((p->dados[i] == ')' && topo != '(') ||
                (p->dados[i] == ']' && topo != '[') ||
                (p->dados[i] == '}' && topo != '{')) {
                return 0;
            }
        }
    }

    return pilha_vazia(&a);
}

int palindromo(pilha_carac *p){
    for(int i = 0; i < p->topo; i++){
        if(p->dados[i] != p->dados[--p->topo]) return 0;
    }
    return 1;
}