#ifdef

#include <stdio.h>
#include <ctype.h>

void construir_carro(t_carro *c, char placa[]);
void construir_carro_estacionado(t_carro_estacionado *ct, t_carro c);
void construir_estacionamento(t_estacionamento *e, int max);
void exibir_estacionamento(t_estacionamento *estacionamento);
int estacionamento_vazio(t_estacionamento *estacionamento);
int estacionamento_cheio(t_estacionamento *estacionamento);
int estacionar(t_estacionamento *estacionamento, t_carro_estacionado *carro);
int retirar(t_estacionamento *estacionamento, t_carro_estacionado *removido);
int manobrar(t_estacionamento *estacionamento, t_carro_estacionado carro);

#endif