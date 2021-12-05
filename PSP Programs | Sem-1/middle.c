#include<stdio.h>

int main(){
    int i,n,temp=0,count=0,middle_digit;

    printf("Enter the Number: ");
    scanf("%d",&n);
    temp=n;
    while(temp!=0){
        temp=temp/10;
        count++;
    }
    for(i=0;i<count/2;i++){
        n=n/10;
    }
    middle_digit=n%10;
    printf("\nMiddle Digit is %d",middle_digit);
}