#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
    char name[50];
    int roll_no;            //Student Structure
    float marks;
};

struct student* stack;     //pointer of student structure to allocate memory dynamically

int c_operation=0;  //counter for copy operations
int operation = 0;  //counter for total operations
int size = 1;    //size of stack
int top = -1;   //top of stack


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
        scanf("%d",&stack[top].roll_no);        //push a student record
        printf("Enter the Marks: ");
        scanf("%f",&stack[top].marks);

        operation = operation + 1;

        printf("\nElement pushed\n");
        printf("\nTotal number of steps to complete a program till now (Copy Operations + Memory allocation + Pushing a element): %d\n",operation);
        printf("Copy Operations till now: %d\n",c_operation);
        printf("Number of elements in the stack: %d\n",top+1);
    }
    else
    {
        printf("\nStack size upgraded\n");

        struct student* temp = (struct student*)calloc(size,sizeof(struct student));    //updating the stack size by using a temporary array 
        for(int i=0;i<size;i++)
        {
            strcpy(temp[i].name,stack[i].name);
            temp[i].roll_no = stack[i].roll_no;         //copying original array to temp array
            temp[i].marks = stack[i].marks;
        }
        free(stack);
        stack = NULL;

        stack = (struct student*)calloc(size+1,sizeof(struct student));     //updating the size of the array by 1
        for(int i=0;i<size;i++)
        {
            strcpy(stack[i].name,temp[i].name);
            stack[i].roll_no = temp[i].roll_no;                 //copying the temp array to updated array
            stack[i].marks = temp[i].marks;
        }
        free(temp);
        temp = NULL;

        top = top + 1;
        size = size + 1;

        printf("\nEnter the name: ");
        scanf("%s", stack[top].name);
        printf("Enter the roll no: ");    
        scanf("%d",&stack[top].roll_no);        //push a student record
        printf("Enter the Marks: ");
        scanf("%f",&stack[top].marks);
        
        operation = operation + 5;
        c_operation = c_operation + 2;

        printf("\nElement pushed\n");
        printf("\nTotal number of steps to complete a program till now (Copy Operations + Memory allocation + Pushing a element): %d\n",operation);
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
            free(stack);                            //free the memory allocated to stack
            stack = NULL;
            stack = (struct student*)calloc(size,sizeof(struct student));      
            top = -1;
            operation = operation + 2;
            printf("\nTotal number of steps to complete a program till now (Copy Operations + Memory allocation + Poping a element): %d\n",operation);
            printf("Total number of copy operations performed till now: %d\n",c_operation);
            printf("Number of elements in the stack: %d\n",top+1);
        }
        else                                                                    
        {
            struct student* temp = (struct student*)calloc(size-1,sizeof(struct student));    //updating the stack size by using a temporary array 
            for(int i=0;i<size-1;i++)
            {
                strcpy(temp[i].name,stack[i].name);
                temp[i].roll_no = stack[i].roll_no;         //copying original array to temp array
                temp[i].marks = stack[i].marks;
            }
            free(stack);
            stack = NULL;

            stack = (struct student*)calloc(size-1,sizeof(struct student));     //updating the size of the array by 1
            for(int i=0;i<size-1;i++)
            {
                strcpy(stack[i].name,temp[i].name);
                stack[i].roll_no = temp[i].roll_no;                 //copying the temp array to updated array
                stack[i].marks = temp[i].marks;
            }
            free(temp);
            temp = NULL;

            size = size - 1;
            top = top - 1;                                          //pop a student record
            operation = operation + 5;
            c_operation = c_operation + 2;
            printf("\nTotal number of steps to complete a program till now (Copy Operations + Memory allocation + Poping a element): %d\n",operation);
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
    printf("\nName\tRoll No\tMarks\n");           
    while(temp>=0)
    {
        printf("%s\t%d\t%f\n",stack[temp].name,stack[temp].roll_no,stack[temp].marks);      //display all the student records
        temp--;
    }
    if(top==-1)
    {
        printf("\nStack is empty\n");
        return;
    }
        
    printf("\nTotal number of steps to complete a program till now (Copy Operations + Memory allocation + Pushing a element + Poping a element): %d\n",operation);
    printf("Total number of copy operations performed till now: %d\n",c_operation);
    printf("Number of elements in the stack: %d\n",top+1);
}

int main()
{
    stack = (struct student*)calloc(size,sizeof(struct student));  

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
                printf("\nTotal number of steps to complete a program till now (Copy Operations + Memory allocation + Pushing a element + Poping a element): %d\n",operation);
                break;
            case 5:
                printf("\nTotal number of copy operations performed till now: %d\n",c_operation);
                break;
            case 6:
                printf("\nTotal number of elements present in the stack: %d\n",top+1);
                break;
            case 7:
                printf("\nThank you for using the program\n\n"); 
                break;
        }
    }while(choice!=7);
}