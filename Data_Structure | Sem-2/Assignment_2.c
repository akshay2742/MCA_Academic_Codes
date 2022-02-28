#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;      //Node
};

void Insert(struct Node** head, int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node* last = *head;
    
    if(*head==NULL)
    {
        node->data=data;
        node->next=NULL;                            //Insertion of the Node According to Ascending order
        *head=node;
    }
    else
    {
        while(last->next!=NULL)
        {
            if(last->next->data < data)
            {
                last=last->next;
            }
            else
            {
                break;
            }
        }
        if(last->data < data)
        {
            node->data=data;
            node->next=last->next;
            last->next=node;
        }
        else
        {
            node->data=data;
            node->next=*head;
            *head=node;
            
        }
        
    }
}

void print(struct Node** temp)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node*)); //Printing the Linked List
    new_node = *temp;
    while(new_node!=NULL)
    {
        printf("%d ",new_node->data);
        new_node = new_node->next;
    }
}

int findRand(struct Node** head, int number){
    
    struct Node* temp = *head;
    while(temp!=NULL)
    {
        if(temp->data==number)                      //Finding Random Number in the List
        {
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

void delete_node(struct Node** head, int number)
{
    struct Node* temp = *head;
    struct Node* prev = *head;
    while(temp!=NULL && temp->data==number)         //Deleting a Node
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != number) 
	{
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
        
    prev->next = temp->next;
    free(temp); 
}


//Main Function

int main()
{
    
    int nodes, number=0, random=0;
    struct Node* head = NULL;
    
    printf("Enter the Number of Nodes you want to create: ");
    scanf("%d",&nodes);
    
    for(int i = 0; i < nodes; i++)
    {
        number = rand()%100;
        printf("%d Element inserted is: %d\n",i+1,number);
        Insert(&head, number);
    }
    
    printf("\nLinked List with Ascending order is: ");
    print(&head);
    
    random = rand()%100;
    printf("\n\nThe Number to find & delete is: %d",random);
    
    
    if(findRand(&head, random))
    {
        printf("\nNumber is Found!");
        delete_node(&head, random);
        printf("\n\nNew Linked List after deleting %d is: ", random);
        print(&head);
        
    }
    else
    {
        printf("Number is not Found!");
        Insert(&head, random);
        printf("\n\nNew Linked List after inserting %d is: ", random);
        print(&head);
        
    }
}
