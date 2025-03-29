#include <stdio.h>

void f1(const int a){
    //a++;
}
int main(){
    int x= 10;
    f1(x);
    printf("digite um inteiro: ");
    int i, j, k;
    j = scanf("%d%d", &i, &k);
    printf("i = %d\nk= %d\nj= %d\n", i, k, j);
    return 0;
}