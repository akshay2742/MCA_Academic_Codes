#include<stdio.h>
#include<stdlib.h>
 
void main(){
    int *p,i;
    int *ptr;

    p=(int *)malloc(4);

    ptr=(int *)calloc(5,4);
    printf("Enter the Integer value: ");
    scanf("%d",&*p);
    printf("%d",*p);
    printf("\nEnter the 5 Integer value:\n");
    for(i=0;i<5;i++){
        scanf("%d",&*(ptr+i));
    }
    printf("\nArray is:\n");
    for(i=0;i<5;i++){
        printf("%d\n",*(ptr+i));
    }




}