#include<stdio.h>

struct student{
    char name[50];
    int roll_no;            //Student Struct
    float marks;
};

struct student stack[100];      //Stack of 100 students

int top = -1;

int isfull(int size)
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

void push(int size)
{
    if(!isfull(size))
    {
        top = top + 1;
        printf("\nEnter the name: ");
        scanf("%s", stack[top].name);
        printf("\nEnter the roll no: ");    //push a student record
        scanf("%d",&stack[top].roll_no);
        printf("\nEnter the Marks: ");
        scanf("%f",&stack[top].marks);
    }
    else
        printf("\nStack is full\n");
}

void pop()
{
    if(!isempty())                      //pop a student record
    {
        printf("%s\t%d\t%f  is popped\n",stack[top].name,stack[top].roll_no,stack[top].marks);
        top = top - 1;
    }
    else
        printf("\nStack is empty\n");
}


void display_top()
{
    if(!isempty())              //display top of the stack
    {
        printf("%s\t%d\t%f\n",stack[top].name,stack[top].roll_no,stack[top].marks);
    }
    else
        printf("\nStack is empty\n");
}

void display_stack()
{
    int temp=top;
    printf("Name\tRoll No\tMarks\n");           //display all the student records
    while(temp>=0)
    {
        printf("%s\t%d\t%f\n",stack[temp].name,stack[temp].roll_no,stack[temp].marks);
        temp--;
    }
    if(temp==-1)
        printf("\nStack is empty\n");
}


//Main Function
int main()
{
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d",&size);
    
    int choice;
    
    do{
        printf("\n\n1. Perform Push Operation\n2. Perform Pop Operation\n3. Display Stack\n4. Display Top Element\n5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                push(size);
                break;
            case 2:
                pop(size);
                break;
            case 3:
                display_stack(size);
                break;
            case 4:
                display_top();
                break;
            case 5:
                break;
        }
    }while(choice!=5);
    
}