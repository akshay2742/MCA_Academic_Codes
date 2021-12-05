#include<stdio.h>

void main(){

    int n,m,remainder;
    float quotient;

    printf("Enter the dividend: ");
    scanf("%d",&n);
    printf("\nEnter the divisor: ");
    scanf("%d",&m);
    quotient=n/m;
    remainder=n%m;
    printf("\nQuotient is: %f",quotient);
    printf("\nRemainder is: %d",remainder);

}