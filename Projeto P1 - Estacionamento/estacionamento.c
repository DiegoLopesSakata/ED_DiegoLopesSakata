#include "estacionamento.h"

void construir_estacionamento(t_estacionamento *e){
    e->carros = (t_carro_estacionado *) malloc (MAX_CARROS * sizeof(t_carro_estacionado));
    e->capacidade = MAX_CARROS;
    e->quantidade = 0;
}

int estacionamento_vazio(t_estacionamento *estacionamento){
    return estacionamento->quantidade == 0;
}

int estacionamento_cheio(t_estacionamento *estacionamento){
    return estacionamento->quantidade == estacionamento->capacidade;
}

int estacionar(t_estacionamento *estacionamento, t_carro carro){
    if(estacionamento_cheio(estacionamento)) return 0;
    strncpy(estacionamento->carros[estacionamento->quantidade].carro.placa, carro.placa, 7);
    estacionamento->carros[estacionamento->quantidade].carro.placa[7] = '\0';
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

    t_carro_estacionado *aux;
    aux = (t_carro_estacionado *) malloc (estacionamento->capacidade * sizeof(t_carro_estacionado));
    int num_removidos = 0;

    for(int i = estacionamento->quantidade - 1; i > pos; i--){
        aux[num_removidos++] = estacionamento->carros[i];
    }

    estacionamento->quantidade = pos;   

    for(int i = num_removidos; i >= 0; i--){
        estacionamento->carros[estacionamento->quantidade++] = aux[i];
        estacionamento->carros[estacionamento->quantidade - 1].manobras++;
    }

    free(aux);
    return manobras;
}