#include<stdio.h>
#include<stdlib.h>
//STACK IMPLEMENTATION - WITH LINKED LIST
typedef struct node
{
    int data;
    struct node *next;

}Node;
Node *top=NULL; //top=NULL tells that stack is empty
void push(int val);
int pop();
int peek();
int isEmpty();
void menu();
int main() {
    printf("DEDICATED TO HONOURABLE - HF 1010110\n");
    printf("CODED BY MOHAMMAD AFFAN SIDDIQI\n");
    menu();
    return 0;
}

void push(int val)
{
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}
int pop()
{
    Node *temp=top;
    if(temp==NULL)
    {
        printf("ERROR: STACK UNDERFLOW!\n");
        return -1;
    }
    int popped_val=top->data;
    top=temp->next;
    free(temp);
    return popped_val;
}
int peek()
{
    return top->data;
}
int isEmpty()
{
    if(top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void menu()
{
    int choice=0,val=0;
    printf("STACK OPERATIONS IMPLEMENTATION - STATIC ARRAY APPROACH\n");
    printf("1. Push a value to the top\n");
    printf("2. Pop a value from the top\n");
    printf("3. View the value of top\n");
    printf("4. Check whether Stack is Empty or not\n");
    printf("5. Exit\n");
    printf("Enter your choice from the menu: ");
    scanf("%d",&choice);
    while(choice!=5)
    {
        switch(choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            printf("POP OPERATION SUCCESSFUL, The value popped was %d\n",pop());
            break;
        case 3:
            printf("The current value of top is: %d\n",peek());
            break;
        
        case 4:
            if(isEmpty())
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
            break;
        }
        printf("Enter your choice from the menu: ");
        scanf("%d",&choice);

    }
}