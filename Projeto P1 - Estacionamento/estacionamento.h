//Integrantes: Diego Lopes Sakata, Cauê Ferreira Lacerda, Pedro Yun Han

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 10
#define MAX_PLACA 8

typedef struct{
    char placa[MAX_PLACA];
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

void construir_estacionamento(t_estacionamento *e);
void exibir_estacionamento(t_estacionamento *e);
int estacionamento_vazio(t_estacionamento *estacionamento);
int estacionamento_cheio(t_estacionamento *estacionamento);
int estacionar(t_estacionamento *estacionamento, t_carro carro);
int retirar(t_estacionamento *estacionamento, t_carro carro);