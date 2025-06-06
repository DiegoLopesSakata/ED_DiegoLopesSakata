#include "abb.h"
#include <time.h>

int main(){
    t_abb abb;
    constroi_abb(&abb);
    srand(time(0));

    int op;
    do{
        printf("-------Menu-------\n\n");
        printf("1. Adicionar n valores na arvore\n");
        printf("2. Adicionar um valor especifico\n");
        printf("3. Exibir arvore\n");
        printf("4. buscar valor\n");
        printf("5. buscar quantas vezes um valor se repete\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1: {int n;
                    printf("Quantos valores quer colocar na arvore? ");
                    scanf("%d", &n);
                    for(int i = 0; i < n; i++){
                        inserir_abb(rand() % 100, &abb);
                    }
                    break;}
            case 2: {int valor;
                    printf("Digite o valor: ");
                    scanf("%d", &valor);
                    inserir_abb(valor, &abb);
                    break;}
            case 3: exibir_abb(&abb);
                    break;
            case 4: {int x;
                    printf("Digite o valor para buscar: ");
                    scanf("%d", &x);
                    if(busca_abb(x, &abb)){
                        printf("%d esta na arvore!\n", x);
                    }
                    else{
                        printf("%d nao esta na arvore!\n", x);
                    }
                    break;}
            case 5:{
                    int count, x;
                    printf("Qual o valor vc deseja procurar? ");
                    scanf("%d", &x);
                    count = cont_x(x, &abb);
                    printf("%d aparece %d vezes na arvore!\n", x, count);
                    break;}
            case 0: printf("Saindo...\n");
                    break;
            default: printf("Isso nao eh uma opcao!\n");
                     break;
        }
    }while(op != 0);

    return 0;
}