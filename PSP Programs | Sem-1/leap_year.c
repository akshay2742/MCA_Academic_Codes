#include<stdio.h>

int main(){

    int year=0,result=0;

    printf("Enter the year: ");
    scanf("%d",&year);

    if(year%400==0){
        printf("Year is a Leap year");
    }
    else if(year%100==0){
        printf("Year is not a leap year");
    }
    else if(year%4==0){
        printf("Year is a leap year");
    }
    else{
        printf("Year is not a leap year");
    }
}