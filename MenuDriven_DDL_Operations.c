#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *temp, *newNode;

void createNode();
void insertBeg(int val);
void insertPos(int val, int pos);
void insertAfPos(int val, int pos);
void insertEnd(int val);
void deleteNode(int pos);
void display();
void reverseLL();
void menu();

int main()
{
    printf("Dedicated to Honourable - HF 1010110\n");
    printf("CODED BY MOHAMMAD AFFAN SIDDIQI\n");
    menu();
    return 0;
}

void createNode()
{
    int cont_ch=1;
    while(cont_ch==1)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the value to be stored in this node: ");
        scanf("%d",&newNode->data);
        newNode->prev = newNode->next = NULL;
        
        if(head==NULL) //Empty linked list
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        printf("Do you want to create another node? (1.Yes - Continue, 0. No - Exit): ");
        scanf("%d",&cont_ch);
    }  
}

void insertBeg(int val)
{
    printf("Before insertion at beginning, ");
    display();
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->prev=NULL;
    if(head==NULL)
    {
        newNode->next=NULL;
        head=tail=newNode;
    }
    else
    {
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    printf("After insertion at beginning, ");
    display();
}

void insertPos(int val, int pos)
{
    printf("Before insertion, ");
    display();
    if (pos == 1) // Corrected condition to insert at beginning
    {
        insertBeg(val);
        return;
    }
    temp=head;
    for(int f=1; f<pos-1 && temp!=NULL; f++)
    {
        temp=temp->next;
    }
    if(temp==NULL) // Invalid position
    {
        printf("ERROR: INVALID POSITION FOR INSERTION\n");
        return;
    }
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=temp->next;
    newNode->prev=temp;
    
    if(temp->next!=NULL)
    {
        temp->next->prev=newNode;
    }
    else
    {
        tail=newNode; // Insertion at end
    }
    temp->next=newNode;
    printf("After insertion, ");
    display();
}

void insertAfPos(int val, int pos)
{
    printf("Before insertion, ");
    display();
    temp=head;
    for(int f=1; f<pos && temp!=NULL; f++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("ERROR: INVALID POSITION FOR INSERTION!\n");
        return;
    }
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->prev=temp;
    newNode->next=temp->next;
    
    if(temp->next!=NULL)
    {
        temp->next->prev=newNode;
    }
    else
    {
        tail=newNode;
    }
    temp->next=newNode;
    printf("After insertion, ");
    display();
}

void insertEnd(int val)
{
    printf("Before inserting at the end, ");
    display();
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL)
    {
        newNode->prev=NULL;
        head=tail=newNode;
    }
    else
    {
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
    printf("After inserting at the end, ");
    display();
}

void deleteNode(int pos)
{
    printf("Before deleting the node, ");
    display();
    
    if(head==NULL) // Empty list check
    {
        printf("EMPTY LIST ERROR: NO NODE WAS FOUND TO BE DELETED!\n");
        return;
    }
    
    temp=head;
    for(int f=1; f<pos && temp!=NULL; f++)
    {
        temp=temp->next;
    }
    
    if(temp==NULL) // Invalid position
    {
        printf("ERROR: INVALID POSITION\n");
        return;
    }

    if(head==tail) // Single node in the list
    {
        head=tail=NULL;
    }
    else if(temp==head) // Deleting head node
    {
        head=temp->next;
        head->prev=NULL;
    }
    else if(temp==tail) // Deleting tail node
    {
        tail=temp->prev;
        tail->next=NULL;
    }
    else
    {
        temp->prev->next=temp->next;
        if(temp->next!=NULL)
        {
            temp->next->prev=temp->prev;
        }
    }
    free(temp);
    printf("After deleting the node, ");
    display();
}

void display()
{
    printf("The doubly linked list is: { NULL <-> ");
    temp=head;
    if(head==NULL)
    {
        printf("Empty Doubly Linked List, Nothing to display!\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL }\n");
}

void reverseLL()
{
    printf("Before reversing, ");
    display();
    
    if(head==NULL) // Empty list
    {
        printf("ERROR: EMPTY LIST, NOTHING TO REVERSE!\n");
        return;
    }
    if(head==tail) // Single node -> No change
    {
        return;
    }
    
    struct node *curr=head, *tempNode;
    while(curr!=NULL)
    {
        tempNode=curr->next;
        curr->next=curr->prev;
        curr->prev=tempNode;
        curr=tempNode;
    }
    
    // Correctly swap head and tail
    temp=head;
    head=tail;
    tail=temp;
    
    printf("After reversing, ");
    display();
}

void menu()
{
    int choice=0, val=0, pos=0;
    printf("--------Doubly Linked List Operations--------\n");
    printf("1. Create a new Node\n");
    printf("2. Insert a new Node at the beginning of the Doubly Linked List\n");
    printf("3. Insert a new Node at a specified position in the Doubly Linked List\n");
    printf("4. Insert a new Node after a specified position in the Doubly Linked List\n");
    printf("5. Insert a new Node at the end of the Doubly Linked List\n");
    printf("6. Delete a node from a specific position\n");
    printf("7. Traverse/Display the Doubly Linked List\n");
    printf("8. Reverse the Doubly Linked List\n");
    printf("9. Exit\n");
    printf("Enter your choice corresponding to the menu: ");
    scanf("%d",&choice);
    
    while(choice!=9)
    {
        switch(choice)
        {
        case 1:
            createNode();
            break;
        
        case 2:
            printf("Enter the value to be inserted at the beginning: ");
            scanf("%d",&val);
            insertBeg(val);
            break;
        
        case 3:
            printf("Enter the value to be inserted at a position: ");
            scanf("%d",&val);
            printf("Enter the position of insertion: ");
            scanf("%d",&pos);
            insertPos(val,pos);
            break;

        case 4:
            printf("Enter the value to be inserted after a position: ");
            scanf("%d",&val);
            printf("Enter the position after which you want to insert node: ");
            scanf("%d",&pos);
            insertAfPos(val,pos);
            break;

        case 5:
            printf("Enter the value to be inserted at the end: ");
            scanf("%d",&val);
            insertEnd(val);
            break;

        case 6:
            printf("Enter the position of the node to be deleted: ");
            scanf("%d",&pos);
            deleteNode(pos);
            break;
        
        case 7:
            display();
            break;
        
        case 8:
            reverseLL();
            break;

        case 9:
            printf("Exiting the code....\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
        printf("Enter your choice corresponding to the menu: ");
        scanf("%d",&choice);
    }
}