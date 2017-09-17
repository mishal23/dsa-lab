/*
	Implement Queue using Stacks
*/
#include<stdio.h>
#include<stdlib.h>
void push1(int );
void push2(int );
int pop1();
int pop2();
void enqueue();
void dequeue();
void display();
void create();

int stack1[100],stack2[100];
int top1=-1,top2=-1;
int count=0;

void main()
{
    int choice;
    printf("\n1 - Enqueue element into queue");
    printf("\n2 - Dequeue element from queue");
    printf("\n3 - Display from queue");
    printf("\n4 - Exit\n");
    create();
    while(1)
    {
        printf("Enter your choice:- ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nWrong Choice\n");
        }
    }
}
void create()
{
    top1=top2=-1;
}

void push1(int data)
{
    //printf("\nAdded %d to queue\n",data);
    stack1[++top1]=data;
}
int pop1()
{
    //printf("\nRemoving %d\n",stack1[top1]);
    return stack1[top1--];
}
void push2(int data)
{
    stack2[++top2]=data;
}
int pop2()
{
    return stack2[top2--];
}

void enqueue()
{
    int data,i;
    printf("Enter data to queue: ");
    scanf("%d",&data);
    push1(data);
    count++;
}

void dequeue()
{
    int i;
    for(i=0;i<=count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for(i=0;i<=count;i++)
    {
        push1(pop2());
    }
}
void display()
{
    int i;

    for(i=0;i<=top1;i++)
    {
        printf("%d ",stack1[i]);
    }
    printf("\n");
}
