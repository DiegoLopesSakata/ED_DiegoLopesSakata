#include <stdio.h>

typedef struct{
    int numerador;
    int denominador;

} fracao;

void ler_fracao(fracao *f, int a, int b){
    f->numerador = a;
    f->denominador = b;
}

void exibir_fracao(fracao f){
    printf("%d/%d\n", f.numerador, f.denominador);
}

fracao maior_fracao(fracao a, fracao b){
    if(a.numerador/a.denominador > b.numerador/b.denominador){
        return a;
    }
    else if(a.numerador/a.denominador < b.numerador/b.denominador){
        return b;
    }
    else{
        printf("As fracoes sao iguais\n");
        return a;
    }
}

fracao multiplica_fracao(fracao a, fracao b){
    fracao c;
    int nc, dc;
    nc = a.numerador * b.numerador;
    dc = a.denominador * b.denominador;
    ler_fracao(&c, nc, dc);
    return c;
}

int main(){

    fracao a, b, maior, c;

    ler_fracao(&a, 3, 5);
    ler_fracao(&b, 21, 7);

    exibir_fracao(a);
    exibir_fracao(b);

    maior = maior_fracao(a, b);
    exibir_fracao(maior);

    c = multiplica_fracao(a, b);
    exibir_fracao(c);

    return 0;
}