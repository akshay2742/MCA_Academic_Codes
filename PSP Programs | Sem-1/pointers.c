#include<stdio.h>

int main(){

    int *p,a;
    char *c,ch;

    scanf("%c\n",&ch);

    scanf("%d",&a);

    p=&a;
    c=&ch;



    printf("Value of a: %d\n",*p);
    printf("address of a: %d\n",p);

    printf("\nValue of ch: %c\n",*c);
    printf("address of ch: %d\n",c);

    printf("\nScale factor of a: %d",sizeof(*p));
    printf("\nScale factor of ch: %d\n",sizeof(*c));

    p=p+1;
    c=c+1;
    printf("\naddress of incremented a: %d",p);
    printf("\naddress of incremented ch: %d",c);

    printf("\nValue of incremented a: %d",*p);
    printf("\nValue of incremented c: %d",*c);




}