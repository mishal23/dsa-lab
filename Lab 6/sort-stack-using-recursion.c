/*
    Sort Stack using recursion
*/
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};

void initStack(struct stack **s)
{
    *s=NULL;
}

int isEmpty(struct stack *s)
{
    if(s==NULL)
        return 1;
    return 0;
}

void push(struct stack **s,int x)
{
    struct stack *temp=(struct stack *)malloc(sizeof(*temp));
    if(temp==NULL)
    {
        printf("\nMemory overflow\n");
        return ;
    }
    temp->data=x;
    temp->next=*s;
    *s=temp;
}

int pop(struct stack **s)
{
    int x;
    struct stack *temp;

    x=(*s)->data;
    temp=*s;
    (*s)=(*s)->next;
    free(temp);

    return x;
}

int top(struct stack *s)
{
    return (s->data);
}

void Insertionsort(struct stack **s,int x)
{
    if(isEmpty(*s) || x > top(*s))
    {
        push(s,x);
        return;
    }
    int temp=pop(s);
    Insertionsort(s,x);

    push(s,temp);
}

void sortStack(struct stack **s)
{
    if(!isEmpty(*s))
    {
        int x=pop(s);
        sortStack(s);
        Insertionsort(s,x);
    }
}

void printStack(struct stack *s)
{
    while(s)
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}

int main()
{
    int n,value;
    struct stack *top;
    initStack(&top);
    printf("Enter number of elements to enter: ");
    scanf("%d",&n);
    while(n--)
    {
        printf("Enter data: ");
        scanf("%d",&value);
        push(&top,value);
    }
    printf("Elements before sorting: ");
    printStack(top);
    sortStack(&top);
    printf("\n\n");

    printf("Elements after sorting: ");
    printStack(top);
}
