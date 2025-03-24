#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL, *temp, *tail;

void createCLL1();
void displayCLL1();
void createCLL2();
void displayCLL2();
void createCLL3();
void displayCLL3();
void insertBeg();
void menu();

int main() 
{
    printf("DEDICATED TO HONB'LE HF - 1010110\n");
    printf("CODED BY MOHAMMAD AFFAN SIDDIQI\n");
    menu();
    return 0;
}

void createCLL1() 
{
    temp = head;
    int choice = 1;
    while(choice) 
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        printf("Enter the value to be stored in the node: \n");
        scanf("%d", &newnode->data);
        if(head == NULL) 
        {
            head = temp = newnode;
            newnode->next = temp;
        } 
        else 
        {
            temp->next = newnode;
            newnode->next = head;
            temp = newnode;
        }
        printf("Do you want to create another node? (1. Yes & 0. No) ");
        scanf("%d", &choice);
    }
}

void displayCLL1() 
{
    if(head == NULL) 
    {
        printf("ERROR: EMPTY CIRCULAR LINKED LIST!\n");
        return;
    } 
    else 
    {
        temp = head;
        printf("{ ");
        while(temp->next != head) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> %d }\n", temp->data, head->data);
    }
}

void createCLL2() 
{
    int choice = 1;
    head = tail = NULL;
    while(choice) 
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        printf("Enter the value to be stored in the node: \n");
        scanf("%d", &newnode->data);
        if(head == NULL) 
        {
            head = tail = newnode;
            newnode->next = newnode;  // Point to itself, circularity.
        } 
        else 
        {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        printf("Do you want to create another node? (1. Yes & 0. No) ");
        scanf("%d", &choice);
    }
}

void displayCLL2() 
{
    temp = head;
    if(temp == NULL) 
    {
        printf("ERROR: EMPTY CIRCULAR LINKED LIST!\n");
        return;
    } 
    else 
    {
        printf("The Circular linked list is:\n{ ");
        while(temp->next != head) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> %d }\n", temp->data, head->data);
    }
}

void createCLL3() 
{
    int choice = 1;
    tail = NULL;  // Ensure tail is initialized to NULL at the start.
    while(choice) 
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        printf("Enter the value to be stored in the node: \n");
        scanf("%d", &newnode->data);

        if(tail == NULL) 
        {
            // When the list is empty, the new node points to itself.
            tail = newnode;
            newnode->next = tail;  // Circularity: points to itself.
        } 
        else 
        {
            // Add the new node after tail and update the tail pointer.
            newnode->next = tail->next; // Points to the first node.
            tail->next = newnode;       // Make the current tail point to new node.
            tail = newnode;             // Move tail to the new node.
        }

        printf("Do you want to create another node? (1. Yes & 0. No) ");
        scanf("%d", &choice);
    }
}

void displayCLL3() 
{
    if(tail == NULL) 
    {
        printf("ERROR: EMPTY CIRCULAR LINKED LIST!\n");
        return;
    } 

    temp = tail->next;  // Start from the node after the tail, which is the head of the circular list.
    printf("The circular linked list is:\n{ ");
    do 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } 
    while(temp != tail->next);  // Loop until we come back to the head.
    
    printf("%d }\n", tail->next->data);  // Print the last node, which is pointed to by tail.
}


void menu() {
    printf("CIRCULAR LINKED LIST CREATION & TRAVERSAL\n");
    printf("1. Create using only head pointer\n");
    printf("2. Create using both head and tail pointers\n");
    printf("3. Create using only tail pointer\n");
    printf("4. Display using only head pointer\n");
    printf("5. Display using both head and tail pointers\n");
    printf("6. Display using only tail pointer\n");
    printf("7. Insert a node at beginning of the Circular Linked List\n");
    printf("8. Exit\n");

    int choice;
    printf("Enter your choice from the menu: ");
    scanf("%d", &choice);
    
    while(choice != 8) 
    {
        switch(choice) 
        {
        case 1:
            createCLL1();
            break;
        case 2:
            createCLL2();
            break;
        case 3:
            createCLL3();
            break;
        case 4:
            displayCLL1();
            break;
        case 5:
            displayCLL2();
            break;
        case 6:
            displayCLL3();
            break;
        case 7:
            insertBeg();
            break;
        default:
            printf("Invalid choice!\n");
        }
        printf("Enter your choice from the menu: ");
        scanf("%d", &choice);
    }
}
