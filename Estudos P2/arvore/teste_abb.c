#include "abb.h"
#include <time.h>

int main(){
    t_abb abb;
    constroi_abb(&abb);
    srand(time(0));

    for(int i = 0; i < 20; i++){
        inserir_abb(rand() % 20, &abb);
        exibir_abb(&abb);
    }

    if(busca_abb(5, &abb)){
        printf("\nO 5 esta na arvore!\n");
    }
    else{
        printf("\nO 5 nao esta na arvore!\n");
    }

    return 0;
}