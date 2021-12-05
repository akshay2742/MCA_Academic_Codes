#include<stdio.h>
int main(){
    int principal;
    float rate, time, S_I;

    printf("Enter the Principal: ");
    scanf("%d",&principal);

    printf("\nEnter the Rate: ");
    scanf("%f",&rate);

    printf("\nEnter the Time: ");
    scanf("%f",&time);

    S_I=(principal*rate*time)/100;
    printf("\n\nThe Desired Simple Interest is: %f",S_I);

}