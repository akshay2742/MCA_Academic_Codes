#include<stdio.h>

void callbyref(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void callbyval(int n1, int n2){
    int temp=n1;
    n1=n2;
    n2=temp;
    printf("\nAfter Swapping:\n%d\n%d\n",n1,n2);
}
int main(){

    int n1,n2,n;
    char ch;

    do{
        printf("How do you want to perform the swap:\n1.Call by Reference\n2.Call by Value\n");
        scanf("%d",&n);
        switch(n){

            case 1:
                printf("\nEnter the numbers:\n");
                scanf("%d\n%d",&n1,&n2);
                printf("\nBefore Swapping:\n%d\n%d\n",n1,n2);
                callbyref(&n1,&n2);
                printf("\nAfter Swapping:\n%d\n%d\n",n1,n2);
                break;

            case 2:
                printf("\nEnter the numbers:\n");
                scanf("%d\n%d",&n1,&n2);
                printf("\nBefore Swapping:\n%d\n%d\n",n1,n2);
                callbyval(n1,n2);
                break;

        }
        
        printf("\nDo you want to continue: ");
        ch=getchar();
        scanf("%c", &ch);
        printf("\n\n");
        


    }
    while(ch=='y');
    


}