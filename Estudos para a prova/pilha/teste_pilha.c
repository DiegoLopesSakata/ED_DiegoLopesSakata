#include "pilha.h"

int main(){

    t_pilha p;
    int capacidade, rem;

    printf("Digite o tamanho da pilha: ");
    scanf("%d",&capacidade);

    constroi_pilha(&p, capacidade);
    push(&p, 93);
    push(&p, 38);
    push(&p, 72);
    exibe_pilha(&p);
    inverte_pilha(&p);
    exibe_pilha(&p);

    printf("Outro Teste - pop_mais!\n");

    push(&p, 25);
    push(&p, 85);
    push(&p, 41);
    push(&p, 24);
    push(&p, 79);
    push(&p, 36);
    exibe_pilha(&p);
    rem = pop_mais(&p, 9);
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

    printf("Outro Teste - pilha_decrescente!\n");

    t_pilha p2, *p3;
    constroi_pilha(&p2, p.capacidade);
    pop_mais(&p, 7);
    push(&p, 76);
    push(&p, 71);
    push(&p, 54);
    push(&p, 49);
    push(&p, 42);
    push(&p, 38);
    push(&p, 18);
    push(&p, 16);
    push(&p, 6);
    push(&p, 1);
    push(&p2, 81);
    push(&p2, 71);
    push(&p2, 53);
    push(&p2, 48);
    push(&p2, 40);
    push(&p2, 35);
    push(&p2, 27);
    push(&p2, 11);
    push(&p2, 9);
    push(&p2, 4);
    p3 = pilha_decrescente(&p, &p2);
    exibe_pilha(p3);

    printf("Outro Teste - binario!\n");

    int n;

    printf("Digite um numero inteiro para ser transformado em binario: ");
    scanf("%d", &n);

    t_pilha *bin;
    bin = binario(n);
    exibe_pilha(bin);

    printf("Outro Teste - transfere_pilha!\n");

    t_pilha *a;
    a = transfere_pilha(bin);
    exibe_pilha(a);

    printf("Outro Teste - encontrar_valor!\n");

    pop_mais(&p, p.topo);
    push(&p, 76);
    push(&p, 71);
    push(&p, 54);
    push(&p, 49);
    push(&p, 42);
    push(&p, 38);
    push(&p, 18);
    push(&p, 16);
    push(&p, 6);
    push(&p, 1);
    exibe_pilha(&p);
    printf("Digite o valor que deseja encontrar na pilha: ");
    scanf("%d", &n);
    if(encontrar_valor(&p, n) == -1){
        printf("O valor %d nao esta na pilha\n", n);
    }
    else{
        printf("O valor %d esta na pilha!\n", n);
    }

    return 0;
}
