#include "abb.h"
#include <time.h>

int main(){
    
    t_abb abb;
    inicia_abb(&abb);

    // if(abb_vazia(&abb))
    //     printf("Arvore inicializada, esta vazia");
    // else
    //     printf("Arvore inicializada, nao esta vazia");

    int op;
    srand(time(0));

    do{
        printf("Escolha uma opcao:\n");
        printf("1. Inserir n valores na arvore\n");
        printf("2. Mostrar a arvore\n");
        printf("3. Buscar um valor na arvore\n");
        printf("0. Sair\n");
        scanf("%d", &op);

        switch(op){
            case 1: {
                    int valor, n;
                    printf("Digite quanto valores vc deseja colocar na arvore: ");
                    scanf("%d", &valor);
                    for(int i = 0; i < valor; i++){
                        n = rand() % 20 + 1;
                        insere(n, &abb);
                    }
                    printf("\n");
                    break;
                    }
            case 2: imprime(&abb);
                    printf("\n");
                    break;
            case 3: {
                    printf("Digite o valor que deseja buscar: ");
                    int valor;
                    scanf("%d", &valor);
                    if(busca(valor, &abb)) printf("%d esta na arvore!\n\n", valor);
                    else printf("%d nao esta na arvore\n\n", valor);
                    break;
                    }
            case 0: printf("saindo...\n");
                    break;
            default: printf("Isso nao eh uma opcao\n");
                    break;
        }
    }while(op != 0);

    return 0;
}
