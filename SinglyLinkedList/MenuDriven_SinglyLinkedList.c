#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

void insertN(int val, int pos);
void display();
void displayRec(struct node *local_head);
void dispRecReverse(struct node *local_head);
void deleteNode(int pos);
void reverseRec(struct node *p);
void reverseItr();
void messageSuccess();

int main() {
    printf("Dedicated to Honourable HF 1010110\n");
    printf("Coded by Mohammad Affan Siddiqi\n");
    head = NULL;
    int choice = 0, n = 0, pos = 0, val = 0;

    do {
        printf("\nMenu - LINKED LIST OPERATIONS:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Regular Display\n");
        printf("4. Recursive Display\n");
        printf("5. Recursive Reverse Display\n");
        printf("6. Reversal of Linked List (Iteratively)\n");
        printf("7. Reversal of Linked List (Recursively)\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Insertion at the END of linked list\n");
                printf("How many nodes do you want to be created? - ");
                scanf("%d", &n);
                for (int f = 1; f <= n; f++) {
                    printf("Enter the %dth node's value: ", f);
                    scanf("%d", &val);
                    printf("Enter the position where you want to insert this new node: ");
                    scanf("%d", &pos);
                    insertN(val, pos);
                }
                break;
            case 2:
                printf("Enter the position to delete the node: ");
                scanf("%d", &pos);
                deleteNode(pos);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Recursive Display:\n");
                displayRec(head);
                printf("\n");
                break;
            case 5:
                printf("Recursive Reverse Display:\n");
                dispRecReverse(head);
                printf("\n");
                break;
            case 6:
                reverseItr();
                printf("Linked list reversed iteratively.\n");
                display();
                break;
            case 7:
                reverseRec(head);
                printf("Linked list reversed recursively.\n");
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}

void insertN(int val, int pos) 
{
    struct node *temp1 = head, *temp2 = (struct node*)malloc(sizeof(struct node));
    temp2->data = val;

    // Handle insertion at the beginning (position 1)
    if (pos == 1) {
        temp2->next = head;
        head = temp2;
        display();
        return;
    }

    // Traverse to the position just before the insertion point
    for (int f = 1; f < pos - 1 && temp1 != NULL; f++) {
        temp1 = temp1->next;
    }

    // Insert at position if the previous node exists
    if (temp1 != NULL) {
        temp2->next = temp1->next;
        temp1->next = temp2;
    } else {
        printf("INVALID POSITION FOR INSERTION!\n");
        return;
    }

    display();
}

void display()
{
    struct node *temp = head;
    printf("The linked list is: \n{ ");
    
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL }\n");
}

void displayRec(struct node *local_head)
{
    if(local_head==NULL)
    {
        return;
    }
    printf("%d ",local_head->data);
    displayRec(local_head->next);
}

void dispRecReverse(struct node *local_head)
{
    if(local_head==NULL)
    {
        return;
    }
    dispRecReverse(local_head->next);
    printf("%d ", local_head->data);
}

void deleteNode(int pos)
{
    if(head==NULL)
    {
        printf("Nothing to delete exists - EMPTY LINKED LIST!\n");
        return;
    }
    if(pos==1)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        messageSuccess();
        display();
    }
    else
    {
        printf("Before Deletion: \n");
        display();
        struct node *temp1 = head, *temp2 = head;
        for(int f = 1; f < pos - 1; f++) // Points to pos-1
        {
            temp1 = temp1->next;
        }
        for(int f = 1; f < pos; f++) // points to pos exactly
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        free(temp2);
        messageSuccess();
        printf("After Deletion: \n");
        display();
    }
}

void reverseRec(struct node *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverseRec(p->next);
    struct node *q=p->next;
    q->next=p;
    p->next=NULL;
}

void reverseItr()
{
    struct node *curr=head,*prev=NULL,*nxt;
    while(curr!=NULL)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    head=prev;
}

void messageSuccess()
{
    printf("OPERATION WAS SUCCESSFUL!\n");
}
