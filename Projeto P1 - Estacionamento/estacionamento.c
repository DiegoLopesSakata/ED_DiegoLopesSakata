//Integrantes: Diego Lopes Sakata, Cauê Ferreira Lacerda, Pedro Yun Han

#include "estacionamento.h"

void construir_estacionamento(t_estacionamento *e){
    e->carros = (t_carro_estacionado *) malloc (MAX_CARROS * sizeof(t_carro_estacionado));
    e->capacidade = MAX_CARROS;
    e->quantidade = 0;
}

void exibir_estacionamento(t_estacionamento *e){
    for(int i = e->quantidade - 1; i >= 0; i--){
        printf("%d: %s\n", i + 1, e->carros[i].carro.placa);
    }
    printf("\n");
}

int estacionamento_vazio(t_estacionamento *estacionamento){
    return estacionamento->quantidade == 0;
}

int estacionamento_cheio(t_estacionamento *estacionamento){
    return estacionamento->quantidade == estacionamento->capacidade;
}

int estacionar(t_estacionamento *estacionamento, t_carro carro){
    if(estacionamento_cheio(estacionamento)) return 0;
    strncpy(estacionamento->carros[estacionamento->quantidade].carro.placa, carro.placa, MAX_PLACA);
    estacionamento->carros[estacionamento->quantidade].carro.placa[MAX_PLACA] = '\0';
    estacionamento->carros[estacionamento->quantidade].manobras = 0;
    estacionamento->quantidade++;
    
    return 1;
}

int retirar(t_estacionamento *estacionamento, t_carro carro){
    if(estacionamento_vazio(estacionamento)) return -1;
    
    int pos = -1;
    for(int i = 0; i < estacionamento->quantidade; i++){
        if(strcmp(estacionamento->carros[i].carro.placa, carro.placa) == 0){
            pos = i;
            break;
        }
    }

    if(pos == -1) return -2;

    int manobras = estacionamento->carros[pos].manobras;

    if(pos == estacionamento->quantidade - 1){
        estacionamento->quantidade--;
        return manobras;
    }

    for(int i = pos; i < estacionamento->quantidade; i++){
        estacionamento->carros[i] = estacionamento->carros[i + 1];
        estacionamento->carros[i].manobras++;
    }

    estacionamento->quantidade--;

    return manobras;
}