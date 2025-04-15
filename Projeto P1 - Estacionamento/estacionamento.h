#ifdef

#include <stdio.h>
#include <string.h>

void construir_carro(t_carro *c, char placa[]);
void construir_carro_estacionado(t_carro_estacionado *ct, t_carro c);
void construir_estacionamento(int espaco);
void exibir_estacionamento(t_estacionamento estacionamento);
int estacionamento_vazio(t_estacionamento estacionamento);
int estacionamento_cheio(t_estacionamento estacionamento);
int estacionar(t_estacionamento estacionamento, t_carro *carro);
int sair(t_estacionamento estacionamento, t_carro carro);

#endif