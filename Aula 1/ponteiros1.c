#include <stdio.h>
int main(){
    
    int a= 23;
    // int *p = 6789;
    int *p = &a;
    int **x = &p;
    printf("x = %p\n", a, p);

    int *j;
    int **k;
    int b=10;
    k= &j;
    j= &b;
    *k = &a;
       

    printf("foi");
    return 0;
}