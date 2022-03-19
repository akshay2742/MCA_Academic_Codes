//Problem1(infix to postfix) and Problem2(infix to prefix) are in the this program I've implemented them using switch case

#include<stdio.h>
#include<string.h>

char Stack[100];              //Stack of 100 characters

int top = -1;           //top of the stack

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')         //checking priority of operators
        return 2;
    else if(ch == '^')
        return 3;
    else
        return 0;
}

void push(char ch)
{
    if(top == 99)
    {
        printf("\nStack is full\n");
        return;
    }
    else
    {   
        top = top + 1;                  //push a character
        Stack[top] = ch;
    }
}

char pop()
{
    if(top == -1)
    {
        return '\n'; 
    }
    else
    {       
        char temp = Stack[top];                    //pop a character
        top = top - 1;
        return temp;
    }
}

void infix_to_postfix(char infix[])
{
    for(int i=0 ; infix[i]!='\0'; i++)
    {
        if(infix[i] == '(')
        {
            push(infix[i]);             //pushing the opening bracket
        }
        else if (infix[i] == ')')
        {
            while(Stack[top] != '(')
            {
                printf("%c",pop());             //printing the operators till it find the opening bracket
            }
            pop();
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')    
        {
            while(top != -1 && (priority(Stack[top]) >= priority(infix[i])))        
            {
                if(Stack[top] == '^' && infix[i] == '^')        //checking ^ operator because of its associativity
                {
                    break;              
                }
                else
                {
                    char ch = pop();
                    printf("%c",ch);        //printing the operators till it find the lower & equal priority operator
                }
                
            }
            push(infix[i]);     //pushing the operators
        }
        else
        {
            printf("%c",infix[i]);      //printing the operands
        }
    }

    while (top!=-1)
    {
        char ch = pop();
        printf("%c",ch);        //printing the remaining operators
    }
    
}

void infix_to_prefix(char infix[])
{
    char prefix[100];       //Prefix Stack used for reversing the final expression
    int top_prefix  = -1;       //top of the prefix stack

    for(int i=strlen(infix)-1 ; i>=0; i--)
    {
        if(infix[i] == ')')
        {
            push(infix[i]);         //pushing the closing bracket
        }
        else if (infix[i] == '(')
        {
            while(Stack[top] != ')')
            {
                top_prefix = top_prefix + 1;        //pushing the operators in the prefix stack till it find the opening bracket
                prefix[top_prefix] = pop();
            }
            pop();
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while(top != -1 && (priority(Stack[top]) == priority(infix[i])))   //checking the same operator priority
            {
                if(Stack[top] == '^' && infix[i] == '^')
                {
                    char ch = pop();
                    top_prefix = top_prefix + 1;    //pushing the operators in the prefix stack because of R-L associativity
                    prefix[top_prefix] = ch;
                }
                else
                {
                    break;      
                }
                
            }
            while(top != -1 && (priority(Stack[top]) > priority(infix[i])))
            {
                char ch = pop();
                top_prefix = top_prefix + 1;        //pushing the operators in the prefix stack till it find the lower priority operator
                prefix[top_prefix] = ch;
            }
            push(infix[i]);         //pushing the operators
        }
        else
        {
            top_prefix = top_prefix + 1;
            prefix[top_prefix] = infix[i];          //pushing the operands
        }
    }

    while (top!=-1)
    {
        char ch = pop();
        top_prefix = top_prefix + 1;        //pushing the remaining operators in the prefix stack
        prefix[top_prefix] = ch;
    }

    while (top_prefix!=-1)
    {
        char ch = prefix[top_prefix];
        top_prefix = top_prefix - 1;        //printing the prefix expression
        printf("%c",ch);
    }
    
}

int main()
{
    int choice;
    do{
        
        char infix[100];

        printf("\n1. Infix to Postfix\n2. Infix to Prefix\n3. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

    
        switch(choice)
        {
            case 1:
                printf("\nEnter the infix expression(MAX_SIZE=100) : ");
                scanf("%s",infix);
                printf("\nPostfix Expression : ");
                infix_to_postfix(infix);
                printf("\n");
                break;
            case 2:
                printf("\nEnter the infix expression(MAX_SIZE=100) : ");
                scanf("%s",infix);
                printf("\nPrefix Expression : ");
                infix_to_prefix(infix);
                printf("\n");
                break;
            case 3:
                printf("\nExiting...\n");
                break;
        }
    }while(choice!=3);

}