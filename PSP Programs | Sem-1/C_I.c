#include<stdio.h>
#include<math.h>

int main(){

    int principal;
    float Amount, rate, time, C_I;

    printf("Enter the Principal: ");
    scanf("%d",&principal);

    printf("\nEnter the Rate: ");
    scanf("%f",&rate);

    printf("\nEnter the Time: ");
    scanf("%f",&time);

    Amount=principal*(pow(1+(rate/100),time));

    printf("\n\nThe Desired Compound Interest is: %f",Amount-principal);
}