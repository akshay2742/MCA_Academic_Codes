#include<stdio.h>
#include<stdlib.h>

struct Student{
    int roll_no;
    char name[50];
    float marks;
    struct Student *next;
};

struct Student* top = NULL;

int count = -1; 

int isfull(int size)
{
    if(count == size-1)
    {
        return 1;
    }
    else
        return 0;
        
}

int isempty()
{
    if(top == NULL)
    {
        return 1;
    }
    else
        return 0;
}

void push(int size)
{
    struct Student* new_node = (struct Student*)malloc(sizeof(struct Student));
    
    if(isfull(size))
    {
        printf("\nStack is full\n");
        return;
    }

    printf("\nEnter the Roll No: ");
    scanf("%d",&new_node->roll_no);
    printf("Enter the name: ");
    scanf("%s",new_node->name);
    printf("Enter the Marks: ");
    scanf("%f",&new_node->marks);

    if(top == NULL)
    {
        new_node->next = NULL;
        top = new_node;
        count++;
    }
    else
    {
        struct Student* temp = top;
        new_node->next = top;
        top = new_node;
        count++;
    }
}

void pop()
{
    if(top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        struct Student* temp = top;
        top = top->next;
        printf("%s\t%d\t%f  is popped\n",temp->name,temp->roll_no,temp->marks);
        free(temp);
        count--;
    }
}

void display_stack()
{
    struct Student* temp = top;
    if(temp == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nName\tRoll No\tMarks\n");
        while(temp != NULL)
        {
            printf("%s\t%d\t%f\n",temp->name,temp->roll_no,temp->marks);
            temp = temp->next;
        }
    }
}

int main()
{
     int choice, size;
     printf("Enter the size of the stack: ");
     scanf("%d",&size);
     
     do{
        printf("\n1. Perform Push Operation\n2. Perform Pop Operation\n3. Display Stack\n4. Exit\n\n");
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
                break;
        }
    }while(choice!=4);
     
}
