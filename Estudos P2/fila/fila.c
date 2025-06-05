#include "fila.h"

t_fila * constroi_fila(int capacidade){
    t_fila * fila = (t_fila *) malloc (sizeof(fila));
    fila->dados = (int *) malloc (capacidade * sizeof(int));
    fila->primeiro = 0;
    fila->ultimo = 0;
    fila->ocupacao = 0;
    fila->capacidade = capacidade;
    return fila;
}

int proximo(int pos, int capacidade){
    return (pos + 1) % capacidade;
}

int fila_cheia(t_fila * fila){
    return fila->ocupacao == fila->capacidade;
}

int fila_vazia(t_fila * fila){
    return !fila->ocupacao;
}

int inserir_fila(int valor, t_fila * fila){
    if(fila_cheia(fila)) return 0;
    fila->dados[fila->ultimo] = valor;
    fila->ultimo = proximo(fila->ultimo, fila->capacidade);
    fila->ocupacao++;
    return 1;
}

int remover_fila(int * removido, t_fila * fila){
    if(fila_vazia(fila)) return 0;
    *removido = fila->dados[fila->primeiro];
    fila->primeiro = proximo(fila->primeiro, fila->capacidade);
    fila->ocupacao--;
    return 1;
}

void exibe_fila(t_fila * fila){
    if(fila_vazia(fila)){
        printf("fila vazia!");
    }
    else{
        int i = fila->primeiro;
        do{
            printf("[%d] ",fila->dados[i]);
            i = proximo(i, fila->capacidade);
        }while(i != fila->ultimo);
    } 
    printf("\n");
}

void exibe_vetor(t_fila * fila){
    if(fila_vazia(fila)){
        for(int i = 0; i < fila->capacidade; i++){
            if(i == fila->capacidade -1){
                printf("[-]");
            }
            else{
                printf("[-] -> ");
            }
        }
        printf("\n");
    }
    else if(fila_cheia(fila)){
        for(int i = 0; i < fila->capacidade; i++){
            if(i == fila->capacidade -1){
                printf("[%d]", fila->dados[i]);
            }
            else{
                printf("[%d] -> ", fila->dados[i]);
            }
        }
        printf("\n");
    }
    else if(fila->primeiro < fila->ultimo){
        for(int i = 0; i < fila->primeiro; i++){
            printf("[-] -> ");
        }
        for(int i = fila->primeiro; i < fila->ultimo; i++){
            printf("[%d] -> ", fila->dados[i]);
        }
        for(int i = fila->ultimo + 1; i < fila->capacidade; i++){
            if(i == fila->capacidade - 1){
                printf("[-]");
            }
            else{    
                printf("[-] -> ");
            }
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < fila->ultimo; i++){
            printf("[%d] -> ", fila->dados[i]);
        }
        for(int i = fila->ultimo; i < fila->primeiro; i++){
            printf("[-] -> ");
        }
        for(int i = fila->primeiro; i < fila->capacidade; i++){
            if(i == fila->capacidade - 1){
                printf("[%d]", fila->dados[i]);
            }
            else{
                printf("[%d] -> ", fila->dados[i]);
            }
        }
        printf("\n");
    }
}