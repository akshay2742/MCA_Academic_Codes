#include<stdio.h>
#include<string.h>

char Stack[100];

int top = -1;

void push(char ch)
{
    top = top + 1;
    Stack[top] = ch;
}

char pop()
{
    if(top == -1)
    {
        return '\n'; 
    }
    else
    {
        char temp;
        temp = Stack[top];
        top = top - 1;
        return temp;
    }
}

int main()
{
    char ch, rev_ch;
     
    printf("\n!-----------------Program to reverse a string using stack-----------------!\n");
    printf("\nEnter the string to reverse it: ");

    while(ch!='\n')
    {
      scanf("%c",&ch);
      if(ch!='\n')
      {
        push(ch);
      }
      
    }

    printf("\nString after reversing it: ");

    while(rev_ch!='\n')
    {
        rev_ch = pop();
        printf("%c",rev_ch);
    }

    printf("\n");
    
}