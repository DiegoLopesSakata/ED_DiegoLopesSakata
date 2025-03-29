#include <stdio.h>
int main(){

    int a;
    float x= 5.75;

    a= (int)x;
    printf("a = %d\n", a);
    
    x= a;
    printf("x = %.2f\n", x);
    
    int m = 17, n= 3;
    float p = (float)m / n;
    printf("divisão = %f\n", p);

    float decimal = p - (int)p;
    printf("Decimal = %.3f\n", decimal);
    return 0;
}