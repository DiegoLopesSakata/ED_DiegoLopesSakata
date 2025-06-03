#include "fila.h"
#include <time.h>

int main(){
    srand(time(0));

    int capacidade;
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &capacidade);

    t_fila * fila = constroi_fila(capacidade);

    int op;
    do{
        printf("-------Menu-------\n\n");
        printf("1. Adicionar n valores na fila\n");
        printf("2. Adicionar um valor especifico\n");
        printf("3. remover um valor da fila\n");
        printf("4. Exibir fila\n");
        printf("5. Exibir vetor\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                    int n;
                    printf("Quantos valores vc deseja entrar? ");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++){
                        if(!inserir_fila(rand() % 20, fila)){
                            printf("Fila cheia!\n");
                            break;
                        }
                    }
                    break;
                    }
            case 2: {
                    int valor;
                    printf("Digite o valor: ");
                    scanf("%d", &valor);
                    if(!inserir_fila(valor, fila)){
                        printf("Fila cheia!\n");
                    }
                    break;
                    }
            case 3: {
                    int valor;
                    if(remover_fila(&valor, fila)){
                        printf("%d saiu da pilha!\n", valor);
                    }
                    else{
                        printf("Fila vazia!\n");
                    }
                    break;
                    }
            case 4: exibe_fila(fila);
                    break;
            case 5: exibe_vetor(fila);
                    break;
            case 0: printf("Saindo...");
                    break;
            default: printf("Isso nao eh uma opcao!\n");
                     break;
        }

    }while(op != 0);

    return 0;
}