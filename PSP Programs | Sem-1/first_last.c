#include<stdio.h>

int main(){
    int first_num,last_num,num;

    scanf("%d",&num);
    last_num=num%10;

    while (num>=10)
    {
        num=num/10;
    }
    first_num=num;
    printf("The Sum of First and last Digits is: %d",first_num+last_num);
    
}