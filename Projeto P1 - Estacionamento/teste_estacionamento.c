#include "estacionamento.h"

#define tam_placas 7

int main(){

    int tamanho, quant_car;
    
    printf("Digite a capacidade do estacionamento: ");
    scanf("%d", &tamanho);

    t_estacionamento est;
    construir_estacionamento(&est, tamanho);

    printf("Digite quantos carros vc quer construir: ");
    do{
        scanf("%d", &quant_car);
    }while(!isdigit(quant_car));

    // char placas[tamanho][tam_placas];

    // printf("Digite as placas de cada carro (sem espaço ou caracteres especiais): \n");

    // for(int i = 0; i < tamanho; i++){
    //     for(int j = 0; j < tam_placas; i++){
    //         do{
    //             scanf("%c", &placas[i][j]);
    //         }while(!ispunct(placas[i][j]))
    //     }
    // }


    return 0;
}