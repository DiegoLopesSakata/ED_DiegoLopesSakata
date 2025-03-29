#include <stdio.h>
#include <stdlib.h>

int main(){
    //int v[50000]; não cabe na memória de alocação estática
    int *v = (int *) malloc (1000000000000000000 * sizeof(int));
    printf("foi");
    return 0;
}

// plinplinpon plinplonplim plimplom