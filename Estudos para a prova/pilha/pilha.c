#include "pilha.h"

void constroi_pilha(t_pilha *p, int capacidade){
    p->dados = (int *) malloc (capacidade * sizeof(int));
    p->topo = 0;
    p->capacidade = capacidade;
}

int pilha_cheia(t_pilha *p){
    return p->topo == p->capacidade;
}

int pilha_vazia(t_pilha *p){
    if(p->topo == 0){
        return 1;
    }
    return 0;
}

int pop(t_pilha *p, int *removido){
    if(pilha_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

int push(t_pilha *p, int dados){
    if(pilha_cheia(p)) return 0;
    p->dados[p->topo++] = dados;
    return 1;
}

void exibe_pilha(t_pilha *p){
    if(pilha_vazia(p)){
        printf("Pilha vazia");
    }
    else{
        for(int i = p->topo-1; i >= 0; i--){
            printf("%d\n", p->dados[i]);
        }
    }
    printf("------\n");
}

int pop_mais(t_pilha *p, int quantidade, int *removidos){
    int a;
    *removidos = 0;
    if(pilha_vazia(p)) return 0;
    if(quantidade > p->topo){
        printf("Nao existem tantos dados para serem retirados da pilha.\n");
    }
    while(pop(p, &a) && *removidos < quantidade){
        printf("O valor %d foi removido\n", a);
        (*removidos)++;
    }   
    return 1;
}

int inverte_pilha(t_pilha *p){
    t_pilha *inv;
    inv = (t_pilha *) malloc (sizeof(t_pilha));
    constroi_pilha(inv, p->capacidade);
    int aux;
    while(pop(p, &aux)){
        push(inv, aux);
    }
    free(p->dados);
    p->dados = inv->dados;
    p->topo = inv->topo;
    free(inv);
    return 1;
}

int encontrar_valor(t_pilha *p, int x){
    for (int i = 0; i <= p->topo; i++) {
        if (p->dados[i] == x) {
            return i;
        }
    }
    return -1;
}

t_pilha* par_impar(t_pilha *p){
    int a, countp = 0, counti = 0;

    for(int i = 0; i < p->topo; i++){
        if(p->dados[i] % 2 == 0){
            countp++;
        }
        else{
            counti++;
        }
    }

    t_pilha *pilhas, aux;
    pilhas = (t_pilha *) malloc (2 * sizeof(t_pilha));
    constroi_pilha(&pilhas[0], countp);
    constroi_pilha(&pilhas[1], counti);
    constroi_pilha(&aux, p->capacidade);
    for(int i = 0; i < p->topo; i++){
        push(&aux, p->dados[i]);
    }

    while(pop(&aux, &a)){
        if(a % 2 == 0){
            push(&pilhas[0], a);
        }
        else{
            push(&pilhas[1], a);
        }
    }

    free(aux.dados);
    return pilhas;
}

t_pilha *pilha_decrescente(t_pilha *p1, t_pilha *p2){
    t_pilha *p3;
    int tam;
    tam = p1->capacidade + p2->capacidade;
    p3 = (t_pilha *) malloc (sizeof(t_pilha)); 
    constroi_pilha(p3, tam);

    int a, b;
    int tem_a = !pilha_vazia(p1) && pop(p1, &a);
    int tem_b = !pilha_vazia(p2) && pop(p2, &b);

    while(tem_a || tem_b){
        if(tem_a && (!tem_b || a < b)){
            push(p3, a);
            tem_a = !pilha_vazia(p1) && pop(p1, &a);
        }
        else if(tem_b){
            push(p3, b);
            tem_b = !pilha_vazia(p2) && pop(p2, &b);
        }

    }

    return p3;
}

t_pilha* binario(int n){
    if(n == 0){
        t_pilha *p = (t_pilha *) malloc (sizeof(t_pilha));
        constroi_pilha(p, 1);
        push(p, 0);
        return p;
    }

    int temp = n;
    int capacidade = 0;

    while(temp != 0){
        capacidade++;
        temp = temp / 2;
    }

    t_pilha *p = (t_pilha *) malloc (sizeof(t_pilha));
    constroi_pilha(p, capacidade);

    if(n < 0){
        n = n * -1;

        while(n != 0){
            int bit = n % 2;
            push(p, bit);
            n = n / 2;
        }
        inverte_pilha(p);
    }
    else{
        while(n != 0){
            int bit = n % 2;
            push(p, bit);
            n = n / 2;
        }
    }

    return p;
}

t_pilha* transfere_pilha(t_pilha *p){
    t_pilha *aux = (t_pilha *) malloc (sizeof(t_pilha));
    constroi_pilha(aux, p->capacidade);
    aux->dados = p->dados;
    aux->topo = p->topo;
    return aux;
}