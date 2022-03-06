#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    int roll_no;
    char name[50];              //Node
    float marks;
    struct Node *next;
};

void Insert(struct Node** head, int roll_no, char name[], float marks)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->roll_no = roll_no;
    strcpy(new_node->name,name);
    new_node->marks = marks;
    new_node->next = NULL;
    
    struct Node* temp = *head;
    if(temp==NULL)                                                  //Adding the student record into the list
    {
        *head = new_node;
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->roll_no == roll_no)
            {
                printf("\nRoll No %d is already present.",roll_no);
                return;
            }
            temp=temp->next;
        }
        temp = *head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

void delete(struct Node** head, int roll_no)
{
    struct Node* prev = *head;
    struct Node* last = *head;
    while(last->roll_no != roll_no)
    {
        prev = last;
        last = last->next;
    }                                               //Delete a student record
    if(prev==last)
    {
        last = last->next;
        *head = last;
        free(prev);
        prev = *head;
        return;
    }
    prev->next = last->next;
    free(last);
}

void display(struct Node* temp)
{
    int choice, roll_no;
    
    printf("\n1. Want to display particular Roll No?\n2. Want to display all?\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    
    switch(choice)
    {                                                               //Display student record
        case 1:
            printf("\nEnter the roll no to display: ");
            scanf("%d",&roll_no);
            while(temp->roll_no != roll_no)
            {
                temp=temp->next;
            }
            printf("Roll NO\tNAME\tMARKS\n");
            printf("%d\t%s\t%f\n",temp->roll_no, temp->name, temp->marks);
            break;
            
        case 2:
            printf("Roll NO\tNAME\tMARKS\n");
            while(temp!=NULL)
            {
                printf("%d\t%s\t%f\n",temp->roll_no, temp->name, temp->marks);
                temp=temp->next;
            }
            break;
            
    }
}

void update(struct Node** head, int roll_no)
{
    int choice;
    char name[50];
    float marks;
    
    
    printf("\n1. Want to update name?\n2. Want to update marks?\n");
    printf("\n\nEnter Your Choice: ");
    scanf("%d",&choice);
                                                            //Update a student record
    struct Node* last = *head;
    
    switch(choice)
    {
        case 1:
            printf("Enter the new name: ");
            scanf("%s",name);
            while(last->roll_no != roll_no)
            {
                last = last->next;
            }
            
            strcpy(last->name,name);
            break;
            
        case 2:
            printf("Enter new marks: ");
            scanf("%f",&marks);
            while(last->roll_no != roll_no)
            {
                last = last->next;
            }
            
            last->marks=marks;
            break;
    }
}


//Main Function
int main()
{
    int n, roll_no;
    char name[50];
    float marks;
    
    struct Node* head = NULL;
    
    do{
        printf("\n1. Insert a student record\n2. Delete a student record\n3. Update a student record\n4. Display record\n5. Exit");  
        
        printf("\n\nEnter Your Choice: ");
        scanf("%d",&n);
        
        switch(n)
        {
            case 1:
                printf("Enter the Roll No: ");
                scanf("%d",&roll_no);
                printf("Enter the name: ");
                scanf("%s",name);
                printf("Enter the Marks: ");
                scanf("%f",&marks);
                Insert(&head,roll_no,name,marks);
                break;
            case 2:
                printf("Enter the Roll No to Delete: ");
                scanf("%d",&roll_no);
                delete(&head,roll_no);
                break;
            case 3:
                printf("Enter the Roll No to Update: ");
                scanf("%d",&roll_no);
                update(&head, roll_no);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("\nHappy Hacking!");
                break;
        }
    }while(n!=5);
    
    
}
