#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *dados;
    int topo;
    int capacidade;
}t_pilha;

void constroi_pilha(t_pilha *p, int tamanho){
    p->dados = (int *) malloc (tamanho * sizeof(int));
    p->topo = 0;
    p->capacidade = tamanho;
}

int p_vazia(t_pilha *p){
    return p->topo == 0;
}

int p_cheia(t_pilha *p){
    return p->topo == p->capacidade;
}

int push(t_pilha *p, int dado){
    if(p_cheia(p)) return 0;
    p->dados[p->topo++] = dado;
    return 1;
}

int pop(t_pilha *p, int *removido){
    if(p_vazia(p)) return 0;
    *removido = p->dados[--p->topo];
    return 1;
}

void exibe_pilha(t_pilha *p){
    for(int i = p->topo - 1; i >= 0; i--){
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int pilhas_iguais(t_pilha *p1, t_pilha *p2){
    if(p1->capacidade != p2->capacidade){
        return 0;
    }

    if(p1->topo != p2->topo){
        return 0;
    }

    for(int i = 0; i < p1->topo; i++){
        if(p1->dados[i] != p2->dados[i]) return 0;
    }
    
    return 1;
}

int pilhas_iguais2(t_pilha *p1, t_pilha *p2){
    
    if(p1->capacidade != p2->capacidade || p1->topo != p2->topo){
        return 0;
    }

    t_pilha temp_p1, temp_p2;
    constroi_pilha(&temp_p1, p1->capacidade);
    constroi_pilha(&temp_p2, p2->capacidade);
    
    int iguais = 1;
    int item1, item2;
    
    while(!p_vazia(p1) && iguais){  
        pop(p1, &item1);
        pop(p2, &item2);
        push(&temp_p1, item1);
        push(&temp_p2, item2);

        if(item1 != item2) iguais = 0;
    }

    while(!p_vazia(&temp_p1)){
        pop(&temp_p1, &item1);
        pop(&temp_p2, &item2);
        push(p1, item1);
        push(p2, item2);
    }

    free(temp_p1.dados);
    free(temp_p2.dados);

    return iguais;
}

int main(){
    t_pilha p1, p2;
    int ca1, ca2;

    printf("Digite o tamanho da pilha 1: ");
    scanf("%d", &ca1);
    printf("Digite o tamanho da pilha 2: ");
    scanf("%d", &ca2);

    constroi_pilha(&p1, ca1);
    constroi_pilha(&p2, ca2);

    push(&p1, 10);
    push(&p1, 20);    
    push(&p1, 30);    
    push(&p2, 10);
    push(&p2, 20);
    push(&p2, 30);

    printf("\nPilhas originais:\n");
    exibe_pilha(&p1);
    exibe_pilha(&p2);

    if(pilhas_iguais2(&p1, &p2)){
        printf("\nAs pilhas sao iguais.\n");
    }
    else{
        printf("\nAs pilhas sao diferentes.\n");
    }

    printf("\nPilhas depois da funcao:\n");
    exibe_pilha(&p1);
    exibe_pilha(&p2);

    free(p1.dados);
    free(p2.dados);

    return 0;
}