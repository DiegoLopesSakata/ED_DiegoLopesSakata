#include "pilha.h"
#include <time.h>

int main(){
    srand(time(0));
    t_lista lista;
    constroi_pilha(&lista);

    int op;
    do{
        printf("-------Menu-------\n\n");
        printf("1. Adicionar n valores na pilha\n");
        printf("2. Adicionar um valor especifico\n");
        printf("3. remover um valor da pilha\n");
        printf("4. Exibir pilha\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1: {
                    int n;
                    printf("Quantos valore vc deseja entrar? ");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++){
                        insere_valor(rand() % 20, &lista);
                    }
                    break;
                    }
            case 2: {
                    int valor;
                    printf("Digite o valor: ");
                    scanf("%d", &valor);
                    insere_valor(valor, &lista);
                    break;
                    }
            case 3: {
                    int valor;
                    remove_valor(&valor, &lista);
                    printf("%d saiu da pilha!\n", valor);
                    break;
                    }
            case 4: exibe_lista(&lista);
                    break;
            case 0: printf("Saindo...");
                    break;
            default: printf("Isso nao eh uma opcao!\n");
                     break;
        }

    }while(op != 0);

    return 0;
}