/*
    Reverse Stack using Recursion
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void generate(struct node **);
void display(struct node *);
void stack_reverse(struct node **,struct node **);

int main()
{
    struct node *stack=NULL;
    generate(&stack);
    printf("The elements in the stack are: ");
    display(stack);
    printf("\nThe reversed stack is: ");
    if(stack!=NULL)
        stack_reverse(&stack,&(stack->next));

    display(stack);
}

void stack_reverse(struct node **stack,struct node **stack_next)
{
    struct node *temp;

    if (*stack_next != NULL)
    {
         temp = (*stack_next)->next;
        (*stack_next)->next = (*stack);
        *stack = *stack_next;
        *stack_next = temp;
        stack_reverse(stack, stack_next);
    }
}

void generate(struct node **stack)
{
    int i,n,value;
    struct node *temp;
    printf("Enter the number of elements in stack: ");
    scanf("%d",&n);
    while(n--)
    {
        printf("Enter data: ");
        scanf("%d",&value);
        temp= (struct node *)malloc(sizeof(struct node));
        temp->data=value;

        if(*stack==NULL)
        {
            *stack=temp;
            (*stack)->next=NULL;
        }
        else
        {
            temp->next= *stack;
            *stack=temp;
        }
    }
}

void display(struct node *stack)
{
    while(stack!=NULL)
    {
        printf("%d ",stack->data);
        stack=stack->next;
    }
}
