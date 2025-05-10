#include "pilha.h"

int main(){

    t_pilha p;
    int capacidade, rem;

    printf("Digite o tamanho da pilha: ");
    scanf("%d",&capacidade);

    constroi_pilha(&p, capacidade);

    printf("Teste - pop_mais!\n");

    push(&p, 93);
    push(&p, 38);
    push(&p, 72);
    push(&p, 25);
    push(&p, 85);
    push(&p, 41);
    push(&p, 24);
    push(&p, 79);
    push(&p, 36);
    exibe_pilha(&p);
    pop_mais(&p, 10, &rem);
    printf("Foram removidos %d valores\n", rem);
    exibe_pilha(&p);

    printf("Outro Teste - par_impar!\n");

    t_pilha *resultado;

    push(&p, 79);
    push(&p, 58);
    push(&p, 3);
    push(&p, 12);
    push(&p, 24);
    push(&p, 67);
    push(&p, 1);
    exibe_pilha(&p);
    resultado = par_impar(&p);
    exibe_pilha(&resultado[0]);
    exibe_pilha(&resultado[1]);

    return 0;
}
