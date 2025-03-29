#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    // for(int i=0; i < argc; i++){
    //     printf("Argumento %d: %s\n", i, argv[i]);
    // }
    int i, soma;
    for( i=1, soma= 0; i <= argc; i++){
        soma += atoi(argv[i]);
    }
    i = printf("soma = %d\n", soma);
    printf("fyk: i = %d\n",i);
    return 0;
}