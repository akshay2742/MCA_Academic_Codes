#include<stdio.h>
int main(){

    int temp,i,x,count,num, middle_num, last_num;
    scanf("%d",&num);
    last_num=num%10;

    x=num;
    count=0;
    while (x!=0)
    {
        x=x/10;
        count++;
    }
    temp= count/2;
   
    for ( i = 0; i < temp; i++)
    {
        num=num/10;
    }
    middle_num=num%10;
    
    printf("sum of middle and last digit: %d", middle_num+last_num);
    
}