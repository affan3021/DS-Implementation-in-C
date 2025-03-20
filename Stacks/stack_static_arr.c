#include<stdio.h>
#define MAX_SIZE 100
//Static Array Approach to STACKS
int stack[MAX_SIZE];
int top=-1;
void push(int val);
int pop();
int peek();
void menu();
int main() {
    printf("DEDICATED TO HONOURABLE - HF 1010110\n");
    printf("CODED BY MOHAMMAD AFFAN SIDDIQI\n");
    menu();
    return 0;
}

void push(int val)
{
    if(top>MAX_SIZE-1)
    {
        printf("ERROR: STACK OVERFLOW!\n");
        return;
    }
    else
    {
        stack[++top]=val;
    }
    
}

int pop()
{
    if(top==-1)
    {
        printf("ERROR: STACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        int pop_val=stack[top];
        top--;
        return pop_val;
    }
    
}
int peek()
{
    return stack[top];
}
void menu()
{
    int choice=0,val=0;
    printf("STACK OPERATIONS IMPLEMENTATION - STATIC ARRAY APPROACH\n");
    printf("1. Push a value to the top\n");
    printf("2. Pop a value from the top\n");
    printf("3. View the value of top\n");
    printf("4. Exit\n");
    printf("Enter your choice from the menu: ");
    scanf("%d",&choice);
    while(choice!=4)
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
        }
        printf("Enter your choice from the menu: ");
        scanf("%d",&choice);
    }
}