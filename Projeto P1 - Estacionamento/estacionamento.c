#include "estacionamento.h"

typedef struct{
    char placa[7];
} t_carro;

typedef struct{
    t_carro carro;
    int manobras;
} t_carro_estacionado;

typedef struct{
    t_carro_estacionado *carros;
    int capacidade;
    int quantidade;
} t_estacionamento;

void construir_carro(t_carro *c, char placa[]){
    c.placa = placa;
}

void construir_carro_estacionado(t_carro_estacionado *ct, t_carro c){
    ct.carro = c;
    ct.manobras = -1;
}

void construir_estacionamento(t_estacionamento *e, int max){
    e.carros = (t_carro_estacionado *) malloc (max * sizeof(t_carro_estacionado));
    e.capacidade = max;
    e.quantidade = 0;
}

void exibir_estacionamento(t_estacionamento estacionamento){

}

int estacionamento_vazio(t_estacionamento estacionamento){
    return estacionamento.quantidade == 0;
}

int estacionamento_cheio(t_estacionamento estacionamento){
    return estacionamento.quantidade == estacionamento.capacidade;
}

int estacionar(t_estacionamento *estacionamento, t_carro_estacionado carro){
    if(estacionamento_cheio) return 0;
    estacionamento.carros[quantidade++] = carro;
    carro.manobras++;
    return 1;
}

int sair(t_estacionamento estacionamento, t_carro carro){
    if(estacionamento_vazio) return 0;
    estacionamento.carros[--quantidade];
    return 1;
}
