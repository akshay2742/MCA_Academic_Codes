#include<stdio.h>
#include<string.h>

char Stack[100];              //Stack of 100 characters

int top = -1;           //top of the stack

void push(char ch)
{
    top = top + 1;              //push a character
    Stack[top] = ch;
}

char pop()
{
    if(top == -1)
    {
        return '\n'; 
    }
    else
    {                           //pop a character
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
      scanf("%c",&ch);          //take a character from user
      if(ch!='\n')
      {                     
        push(ch);               //push the character to stack
      }
      
    }

    printf("\nString after reversing it: ");

    while(rev_ch!='\n')
    {
        rev_ch = pop();
        printf("%c",rev_ch);            //print the string in reverse
    }

    printf("\n");
    
}