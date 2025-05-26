#include "fila.h"

t_fila * constroi_fila(){
    t_fila * pf = (t_fila *) malloc (sizeof(t_fila));
    pf->primeiro = NULL;
    pf->ultimo = NULL;
    return pf;
}
int fila_vazia(t_fila * pf){
    return pf->primeiro == NULL;
}

int enfileira(int i, t_fila * pf){
    t_no * novo = constroi_no(i);
    if(novo == NULL) return 0;
    if(fila_vazia(pf))
        pf->primeiro = novo;
    else
        pf->ultimo->prox = novo;
    pf->ultimo = novo;
    return 1; //retorna sucesso
}
int desenfileira(int * i, t_fila * pf){
    if(fila_vazia(pf)) return 0;
    *i = pf->primeiro->info;
    t_no * aux = pf->primeiro;
    pf->primeiro = pf->primeiro->prox;
    if(pf->primeiro == NULL) //esvaziou a fila
        pf->ultimo = NULL;
    free(aux);
    return 1;
}
void mostra_fila(t_fila * pf){
    if(fila_vazia(pf))
        printf("Fila vazia\n");
    else{
        t_no * aux = pf->primeiro;
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

t_fila ** par_impar(t_fila * pf){
    if(fila_vazia(pf)) return NULL;
    if(pf->primeiro->prox == NULL) return NULL;

    t_fila ** filas = (t_fila **) malloc (2 * sizeof(t_fila));
    filas[0] = constroi_fila();
    filas[1] = constroi_fila();

    t_no * aux = pf->primeiro;
    while(aux != NULL){
        if(aux->info % 2 == 0){
            enfileira(aux->info, filas[0]);
        }
        else{
            enfileira(aux->info, filas[1]);
        }
        aux = aux->prox;
    }

    return filas;
}

int esvazia_menor(t_fila *fila1, t_fila *fila2){
    if(fila_vazia(fila1) || fila_vazia(fila2)) return 0;

    int count1 = 0, count2 = 0;
    t_no * aux = fila1->primeiro;
    while(aux != NULL){
        count1++;
        aux = aux->prox;
    }
    aux = fila2->primeiro;
    while(aux != NULL){
        count2++;
        aux = aux->prox;
    }

    int valor;
    if(count1 > count2){
        while(desenfileira(&valor, fila2)){
            enfileira(valor, fila1);
        }
    }
    else{
        while(desenfileira(&valor, fila1)){
            enfileira(valor, fila2);
        }
    }
    return 1;
}