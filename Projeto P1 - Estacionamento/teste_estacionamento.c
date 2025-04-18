//Integrantes: Diego Lopes Sakata, Cauê Ferreira Lacerda, Pedro Yun Han

#include "estacionamento.h"

int main(int argc, char *argv[]) {
    t_estacionamento estacionamento;
    construir_estacionamento(&estacionamento);
    
    FILE *arquivo = NULL;
    int operacao, manobras;
    t_carro carro;
    
    if(argc > 1) {
        arquivo = fopen(argv[1], "r");
        if(arquivo == NULL) {
            printf("Erro ao abrir o arquivo %s\n", argv[1]);
            return 1;
        }
    } else {
        printf("Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    while (fscanf(arquivo, "%d", &operacao) != EOF) {

        printf("Estacionamento Bashemin\n");
        printf("Operacoes:\n");
        printf("0 - Entrada de carro\n");
        printf("1 - Saida de carro\n");
        printf("2 - Sair do programa\n");
        printf("3 - Exibir Estacionamento\n\n");

        printf("Escolha: %d\n\n", operacao);

        switch(operacao){
            case 0: fscanf(arquivo, "%7s", carro.placa);
                    if (estacionar(&estacionamento, carro)) {
                        printf("Carro %s estacionado!\n\n", carro.placa);
                    }
                    else {
                        printf("Nao ha vagas para o carro %s.\n\n", carro.placa);
                    }
                    break;
            case 1: fscanf(arquivo, "%7s", carro.placa);
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
            case 2: fclose(arquivo);
                    return 0;
            case 3: printf("Carros no estacionamento (ordem de chegada):\n");
                    exibir_estacionamento(&estacionamento);
                    break;
            default: printf("Operacao invalida.\n\n");
        }
    
    }

    fclose(arquivo);
    return 0;
}