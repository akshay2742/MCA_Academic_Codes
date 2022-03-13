#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[50];
    int roll_no;            //Student Structure
    float marks;
};

struct student* stack;     

int c_operation=0, operation = 0, size = 1, top = -1;


int isfull()
{
    if(top == size-1)
        return 1;                   //checking stack is full
    else
        return 0;
}

int isempty()
{
    if(top == -1)
        return 1;               //checking stack is empty
    else
        return 0;
}

void push()
{
    if(!isfull())
    {
        top = top + 1;
        printf("\nEnter the name: ");
        scanf("%s", stack[top].name);
        printf("Enter the roll no: ");    
        scanf("%d",&stack[top].roll_no);
        printf("Enter the Marks: ");
        scanf("%f",&stack[top].marks);

        operation = operation + 1;

        printf("\nElement pushed\n");
        printf("\nTotal number of steps to complete a program till now: %d\n",operation);
        printf("Copy Operations till now: %d\n",c_operation);
        printf("Number of elements in the stack: %d\n",top+1);
    }
    else
    {
        printf("\nStack size upgraded\n");

        stack = realloc(stack,sizeof(struct student)*(size+1));         //push a student record

        top = top + 1;
        size = size + 1;

        printf("\nEnter the name: ");
        scanf("%s", stack[top].name);
        printf("Enter the roll no: ");    
        scanf("%d",&stack[top].roll_no);
        printf("Enter the Marks: ");
        scanf("%f",&stack[top].marks);
        
        operation = operation + 3;
        c_operation = c_operation + 2;

        printf("\nElement pushed\n");
        printf("\nTotal number of steps to complete a program till now: %d\n",operation);
        printf("Total number of copy operations performed till now: %d\n",c_operation);
        printf("Number of elements in the stack: %d\n",top+1);
    }        
}

void pop()
{
    if(!isempty())                      
    {
        printf("\n%s\t%d\t%f  is popped & stack size degraded\n",stack[top].name,stack[top].roll_no,stack[top].marks);
        if(size==1)
        {
            free(stack);
            stack = NULL;
            stack = (struct student*)calloc(1,sizeof(struct student));
            top = -1;
            operation = operation + 1;
            printf("\nTotal number of steps to complete a program till now: %d\n",operation);
            printf("Total number of copy operations performed till now: %d\n",c_operation);
            printf("Number of elements in the stack: %d\n",top+1);
        }
        else                                                                    //pop a student record
        {
            stack = realloc(stack,sizeof(struct student)*(size-1));
            size = size - 1;
            top = top - 1;
            operation = operation + 1;
            printf("\nTotal number of steps to complete a program till now: %d\n",operation);
            printf("Total number of copy operations performed till now: %d\n",c_operation);
            printf("Number of elements in the stack: %d\n",top+1);
        }
        
    }
    else
        printf("\nStack is empty\n");
}

void display_stack()
{
    int temp=top;
    printf("\nName\tRoll No\tMarks\n");           //display all the student records
    while(temp>=0)
    {
        printf("%s\t%d\t%f\n",stack[temp].name,stack[temp].roll_no,stack[temp].marks);
        temp--;
    }
    if(top==-1)
    {
        printf("\nStack is empty\n");
        return;
    }
        
    printf("\nTotal number of steps to complete a program till now: %d\n",operation);
    printf("Total number of copy operations performed till now: %d\n",c_operation);
    printf("Number of elements in the stack: %d\n",top+1);
}

int main()
{
    stack = (struct student*)calloc(1,sizeof(struct student));  

    int choice;
    
    do{
        printf("\n!-----------------Program to implement stack using dynamic array and increasing the size by one-----------------!\n");
        printf("\n1. Perform Push Operation\n2. Perform Pop Operation\n3. Display Stack\n4. Total number of steps to complete a program\n5. Total number of copy operations performed\n6. Total number of elements present in the stack\n7. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                push(&size);
                break;
            case 2:
                pop(&size);
                break;
            case 3:
                display_stack();
                break;
            case 4:
                printf("\nNumber of steps required to complete the program till now: %d\n",operation);
                break;
            case 5:
                printf("\nTotal number of copy operations performed till now: %d\n",c_operation);
                break;
            case 6:
                printf("\nTotal number of elements present in the stack: %d\n",top+1);
                break;
            case 7:
                printf("\nThank you for using the program\n"); 
                break;
        }
    }while(choice!=7);
}