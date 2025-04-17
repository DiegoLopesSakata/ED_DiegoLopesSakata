#include <stdio.h>
#include <string.h>
#include "estacionamento.h"

int main() {
    t_estacionamento estacionamento;
    construir_estacionamento(&estacionamento);
    
    int operacao, manobras;
    t_carro carro;
    
    while (1) {

        printf("Estacionamento Bashemin\n");
        printf("Operacoes:\n");
        printf("0 - Entrada de carro\n");
        printf("1 - Saida de carro\n");
        printf("2 - Sair do programa\n\n");

        printf("Escolha: ");
        scanf("%d", &operacao);

        switch(operacao){
            case 0: printf("Digite a placa do carro (7 caracteres): ");
                    scanf("%7s", carro.placa);
                    carro.placa[7] = '\0';
                    if (estacionar(&estacionamento, carro)) {
                        printf("Carro %s estacionado!\n\n", carro.placa);
                    }
                    else {
                        printf("Nao ha vagas para o carro %s.\n\n", carro.placa);
                    }
                    break;
            case 1: printf("Digite a placa do carro (sem caracteres especiais ou espacos): ");
                    scanf("%7s", carro.placa);
                    carro.placa[7] = '\0';
                    manobras = retirar(&estacionamento, carro);
                    if (manobras == -1) {
                        printf("Estacionamento vazio. Nao ha carros para sair.\n\n");
                    }
                    else if (manobras == -2) {
                        printf("Carro %s nao encontrado no estacionamento.\n\n", carro.placa);
                    }
                    else {
                        printf("Carro %s saiu. Foi manobrado %d vezes.\n\n", carro.placa, manobras);
                    }
                    break;
            case 2: if (operacao == 2) {
                    return 0;
                    }
            default: printf("Operacao invalida.\n\n");
        }
    
    }
}