#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} ponto;

typedef struct{
    ponto p;
    float raio;
} circulo;

void constroi_ponto(ponto *p, float a, float b){
    p->x = a;
    p->y = b;
}

void constroi_circulo(circulo *c, ponto a, float b){
    c->p = a;
    c->raio = b;
}

float distancia_ponto(ponto p1, ponto p2){
    int d;
    d = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2));
    return d;
}

int ponto_circulo(circulo c, ponto d){
    float a;
    a = distancia_ponto(c.p, d);
    if(a > c.raio) return 0;
    return 1;
}

int main(){

    ponto p, a;
    circulo c;

    constroi_ponto(&a, 4.5, 3.7);
    constroi_ponto(&p, 7.2, 2.75);
    constroi_circulo(&c, p, 2);

    if(ponto_circulo(c, a) == 1){
        printf("O ponto esta dentro do circulo!\n");
    }
    else{ 
        printf("O ponto nao esta no circulo!\n");
    }

    return 0;
}