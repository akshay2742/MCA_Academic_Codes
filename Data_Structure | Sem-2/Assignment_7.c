#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

struct Stack{
    char data[100];             //Structure
};                              

struct Stack Postfix[100];      //Stack of 100 Structures

char Stack[100];              //Stack of 100 characters for Infix to Postfix/Prefix

int top = -1;           //top of the stack

int priority(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')         //checking priority of operators for Infix to Postfix/Prefix
        return 2;
    else if(ch == '^')
        return 3;
    else
        return 0;
}

void push_infix(char ch)
{
    if(top == 99)
    {
        printf("\nStack is full\n");
        return;
    }
    else
    {   
        top = top + 1;                  //push a character for Infix to Postfix/Prefix
        Stack[top] = ch;
    }
}

char pop_infix()
{
    if(top == -1)
    {
        return '\n'; 
    }
    else
    {       
        char temp = Stack[top];                    //pop a character for Infix to Postfix/Prefix
        top = top - 1;
        return temp;
    }
}

void push(char data[])
{
    if(top == 99)
    {
        printf("\nStack is full\n");
        return;
    }
    else
    {   
        top = top + 1;                  //push a character
        strcpy(Postfix[top].data,data);
    }
}

char* pop()
{
    if(top == -1)
    {
        char* temp = malloc(1*sizeof(char));
        temp[0] = '\n';                                 //checking for empty stack
        return temp;
    }
    else
    {       
        char* temp = malloc(100*sizeof(char));
        strcpy(temp,Postfix[top].data);                    //pop a character
        top = top - 1;
        return temp;
    }
}

void infix_to_postfix(char infix[])
{
    for(int i=0 ; infix[i]!='\0'; i++)
    {
        if(infix[i] == ' ')
            continue;

        if(infix[i] == '(')
        {
            push_infix(infix[i]);             //pushing the opening bracket
        }
        else if (infix[i] == ')')
        {
            while(Stack[top] != '(')
            {
                printf("%c",pop_infix());             //printing the operators till it find the opening bracket
            }
            pop_infix();
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
                    char ch = pop_infix();
                    printf("%c",ch);        //printing the operators till it find the lower & equal priority operator
                }
                
            }
            push_infix(infix[i]);     //pushing the operators
        }
        else
        {
            printf("%c",infix[i]);      //printing the operands
        }
    }

    while (top!=-1)
    {
        char ch = pop_infix();
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
            push_infix(infix[i]);         //pushing the closing bracket
        }
        else if (infix[i] == '(')
        {
            while(Stack[top] != ')')
            {
                top_prefix = top_prefix + 1;        //pushing the operators in the prefix stack till it find the opening bracket
                prefix[top_prefix] = pop_infix();
            }
            pop_infix();
        }
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while(top != -1 && (priority(Stack[top]) == priority(infix[i])))   //checking the same operator priority
            {
                if(Stack[top] == '^' && infix[i] == '^')
                {
                    char ch = pop_infix();
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
                char ch = pop_infix();
                top_prefix = top_prefix + 1;        //pushing the operators in the prefix stack till it find the lower priority operator
                prefix[top_prefix] = ch;
            }
            push_infix(infix[i]);         //pushing the operators
        }
        else
        {
            top_prefix = top_prefix + 1;
            prefix[top_prefix] = infix[i];          //pushing the operands
        }
    }

    while (top!=-1)
    {
        char ch = pop_infix();
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



void postfix_to_infix(char postfix[])               //Postfix to Infix Conversion
{
    int i = 0;

    char* a;
    char* b;

    
    while(postfix[i] != '\0')
    {
        char result[100];
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            b = pop();                       //poping the operands
            a = pop();                       //poping the operands
            
            switch(postfix[i])              //converting the expression
            {
                case '+':
                    strcpy(result,a);
                    strcat(result,"+");
                    strcat(result,b);
                    push(result);
                    break;
                case '-':
                    strcpy(result,a);
                    strcat(result,"-");
                    strcat(result,b);
                    push(result);
                    break;
                case '*':
                    strcpy(result,a);
                    strcat(result,"*");
                    strcat(result,b);
                    push(result);
                    break;
                case '/':
                    strcpy(result,a);
                    strcat(result,"/");
                    strcat(result,b);
                    push(result);
                    break;
                case '^':
                    strcpy(result,a);
                    strcat(result,"^");
                    strcat(result,b);
                    push(result);
                    break;
            }
        }
        else
        {
            char temp[2] = {postfix[i]};        //pushing the operands
            push(temp);
        }
        i = i + 1;
    }
    
    char* temp = pop();
    
    printf("%s",temp);              //printing the final expression
    
}

void prefix_to_infix(char postfix[])                    //Prefix to Infix Conversion
{
    int i = strlen(postfix) - 1;

    char* a;
    char* b;

    
    while(i >= 0)
    {
        char result[100];
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            a = pop();              //poping the operands
            b = pop();              //poping the operands
            
            switch(postfix[i])              //converting the expression
            {
                case '+':
                    strcpy(result,a);
                    strcat(result,"+");
                    strcat(result,b);
                    push(result);
                    break;
                case '-':
                    strcpy(result,a);
                    strcat(result,"-");
                    strcat(result,b);
                    push(result);
                    break;
                case '*':
                    strcpy(result,a);
                    strcat(result,"*");
                    strcat(result,b);
                    push(result);
                    break;
                case '/':
                    strcpy(result,a);
                    strcat(result,"/");
                    strcat(result,b);
                    push(result);
                    break;
                case '^':
                    strcpy(result,a);
                    strcat(result,"^");
                    strcat(result,b);
                    push(result);
                    break;
            }
        }
        else
        {
            char temp[2] = {postfix[i]};            //pushing the operands
            push(temp);
        }
        i = i - 1;
    }
    
    char* temp = pop();
    
    printf("%s",temp);          //printing the final expression
    
}

void postfix_to_prefix(char postfix[])                  //Postfix to Prefix Conversion
{
    int i = 0;

    char* a;
    char* b;

    
    while(postfix[i] != '\0')
    {
        char result[100];
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {
            b = pop();                 //poping the operands
            a = pop();                 //poping the operands
            
            switch(postfix[i])
            {
                case '+':
                    strcpy(result,"+");
                    strcat(result,a);
                    strcat(result,b);
                    push(result);
                    break;
                case '-':
                    strcpy(result,"-");
                    strcat(result,a);
                    strcat(result,b);
                    push(result);
                    break;
                case '*':
                    strcpy(result,"*");
                    strcat(result,a);
                    strcat(result,b);
                    push(result);
                    break;
                case '/':
                    strcpy(result,"/");
                    strcat(result,a);
                    strcat(result,b);
                    push(result);
                    break;
                case '^':
                    strcpy(result,"^");
                    strcat(result,a);
                    strcat(result,b);
                    push(result);
                    break;
            }
        }
        else
        {
            char temp[2] = {postfix[i]};
            push(temp);                     //pushing the operands
        }
        i = i + 1;
    }
    
    char* temp = pop();
    
    printf("%s",temp);              //printing the final expression
    
}

void prefix_to_postfix(char postfix[])                      //Prefix to Postfix Conversion
{
    int i = strlen(postfix) - 1;

    char* a;
    char* b;

    
    while(i >= 0)
    {
        char result[100];
        if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
        {   
            a = pop();        //poping the operands
            b = pop();          //poping the operands
            
            switch(postfix[i])          //converting the expression
            {
                case '+':
                    strcpy(result,a);
                    strcat(result,b);
                    strcat(result,"+");
                    push(result);
                    break;
                case '-':
                    strcpy(result,a);
                    strcat(result,b);
                    strcat(result,"-");
                    push(result);
                    break;
                case '*':
                    strcpy(result,a);
                    strcat(result,b);
                    strcat(result,"*");
                    push(result);
                    break;
                case '/':
                    strcpy(result,a);
                    strcat(result,b);
                    strcat(result,"/");
                    push(result);
                    break;
                case '^':
                    strcpy(result,a);
                    strcat(result,b);
                    strcat(result,"^");
                    push(result);
                    break;
            }
        }
        else
        {
            char temp[2] = {postfix[i]};
            push(temp);                     //pushing the operands
        }
        i = i - 1;
    }
    
    char* temp = pop();
    
    printf("%s",temp);          //printing the final expression
    
}

bool validate_infix(char Expression[])          //Validation for Infix
{
    int count = 0;
    if((Expression[strlen(Expression) - 1] >= 'a' && Expression[strlen(Expression)-1] <= 'z') || (Expression[strlen(Expression) - 1] >= 'A' && Expression[strlen(Expression) - 1] <= 'Z'))
    {
        if(Expression[strlen(Expression)-2] == '+' || Expression[strlen(Expression)-2] == '-' || Expression[strlen(Expression)-2] == '*' || Expression[strlen(Expression)-2] == '/' || Expression[strlen(Expression)-2] == '^')
        {
            count++;
        }
        
    }  
    if((Expression[0] >= 'a' && Expression[0] <= 'z') || (Expression[0] >= 'A' && Expression[0] <= 'Z'))
    {
        count++;
    }
    if(count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validate_postfix(char Expression[])  // Validation for Postfix
{
    int count = 0;
    if((Expression[0] >= 'a' && Expression[0] <= 'z') || (Expression[0] >= 'A' && Expression[0] <= 'Z'))
    {
        if((Expression[1] >= 'a' && Expression[1] <= 'z') || (Expression[1] >= 'A' && Expression[1] <= 'Z'))
        {
            count++;
        }
    }

    if(Expression[strlen(Expression)-1] == '+' || Expression[strlen(Expression)-1] == '-' || Expression[strlen(Expression)-1] == '*' || Expression[strlen(Expression)-1] == '/' || Expression[strlen(Expression)-1] == '^')
    {
        count++;
    }    
    
    if(count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool validate_prefix(char Expression[])         //Validation for Prefix
{
    int count = 0;
    if((Expression[strlen(Expression)-1] >= 'a' && Expression[strlen(Expression)-1] <= 'z') || (Expression[strlen(Expression)-1] >= 'A' && Expression[strlen(Expression)-1] <= 'Z'))
    {
        if((Expression[strlen(Expression)-2] >= 'a' && Expression[strlen(Expression)-2] <= 'z') || (Expression[strlen(Expression)-2] >= 'A' && Expression[strlen(Expression)-2] <= 'Z'))
        {
            count++;
        }
    }
    if(Expression[0] == '+' || Expression[0] == '-' || Expression[0] == '*' || Expression[0] == '/' || Expression[0] == '^')
    {
        count++;
    }

    if(count == 2)
    {
        return true;
    }
    else
    {
        return false;
    } 
}


int main()
{
    int choice;
    do{
        char Expression[100];
        printf("\n!------------------------------Program to convert Expressions----------------------------------!\n");
        printf("\n1. Infix to Postfix\n2. Infix to Prefix\n3. Postfix to Infix\n4. Prefix to Infix\n5. Postfix to Prefix\n6. Prefix to Postfix\n7. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

    
        switch(choice)
        {
            case 1:
                printf("\nEnter the Infix expression(MAX_SIZE=100) : ");
                scanf("%s",Expression);
                while(!validate_infix(Expression))
                {
                    printf("\nInvalid Infix Expression\n");
                    printf("\nEnter the Infix expression again(MAX_SIZE=100) : ");
                    scanf("%s",Expression);
                }
                printf("\nInfix Expression Validated\n");
                printf("\nPostfix Expression : ");
                infix_to_postfix(Expression);
                printf("\n");
                break;
            case 2:
                printf("\nEnter the Infix expression(MAX_SIZE=100) : ");
                scanf("%s",Expression);
                while(!validate_infix(Expression))
                {
                    printf("\nInvalid Expression.\n");
                    printf("\nEnter the Infix expression again(MAX_SIZE=100) : ");
                    scanf("%s",Expression);
                }
                printf("\nInfix Expression Validated\n");
                printf("\nPrefix Expression : ");
                infix_to_prefix(Expression);
                printf("\n");
                break;
            case 3:
                printf("\nEnter the Postfix expression(MAX_SIZE=100) : ");
                scanf("%s",Expression);
                while(!validate_postfix(Expression))
                {
                    printf("\nInvalid Postfix Expression.\n");
                    printf("\nEnter the Postfix expression again(MAX_SIZE=100) : ");
                    scanf("%s",Expression);
                }
                printf("\nPostfix Expression Validated\n");
                printf("\nInfix Expression : ");
                postfix_to_infix(Expression);
                printf("\n");
                break;
            case 4:
                printf("\nEnter the Prefix expression(MAX_SIZE=100) : ");
                scanf("%s",Expression);
                while(!validate_prefix(Expression))
                {
                    printf("\nInvalid Prefix Expression\n");
                    printf("\nEnter the Prefix expression again(MAX_SIZE=100) : ");
                    scanf("%s",Expression);
                }
                printf("\nPrefix Expression Validated\n");
                printf("\nInfix Expression : ");
                prefix_to_infix(Expression);
                printf("\n");
                break;
            case 5:
                printf("\nEnter the Postfix expression(MAX_SIZE=100) : ");
                scanf("%s",Expression);
                while(!validate_postfix(Expression))
                {
                    printf("\nInvalid Postfix Expression\n");
                    printf("\nEnter the Postfix expression again(MAX_SIZE=100) : ");
                    scanf("%s",Expression);
                }
                printf("\nPostfix Expression Validated\n");
                printf("\nPrefix Expression : ");
                postfix_to_prefix(Expression);
                printf("\n");
                break;
            case 6:
                printf("\nEnter the Prefix expression(MAX_SIZE=100) : ");
                scanf("%s",Expression);
                while(!validate_prefix(Expression))
                {
                    printf("\nInvalid Prefix Expression\n");
                    printf("\nEnter the Prefix expression again(MAX_SIZE=100) : ");
                    scanf("%s",Expression);
                }
                printf("\nPrefix Expression Validated\n");
                printf("\nPostfix Expression : ");
                prefix_to_postfix(Expression);
                printf("\n");
                break;
            case 7:
                printf("\nExiting...\n");
                break;
        }
    }while(choice!=7);
}