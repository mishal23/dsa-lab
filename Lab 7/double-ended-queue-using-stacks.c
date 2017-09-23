/*
	Double Ended Queue using Stacks

	NOTE: This implementation isn't memory efficient
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int stack1[100],stack2[100];
int top1=-1,top2=-1;
int count=0;

void enQueueFront();
void enQueueRear();
void deQueueFront();
void deQueueRear();
void push1(int );
void push2(int );
int pop1();
int pop2();
void display();

int main()
{
	int choice;
	printf("Enter 1 to enqueue at front\nEnter 2 to enqueue at rear\nEnter 3 to dequeue from front\nEnter 4 to dequeue from rear\nEnter 5 to display\nEnter 6 to exit\n");
	while(1)
	{
		printf("Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enQueueFront();
				break;
			case 2:
				enQueueRear();
				break;
			case 3:
				deQueueFront();
				break;
			case 4:
				deQueueRear();
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Enter proper choice\n");
				break;
		}
	}
	return 0;
}

void enQueueRear()
{
	if(top1>=100)
	{
		printf("Double Ended Queue is full\n");
	}
	else
	{
		count++;
		int value;
		printf("Enter value to be added: ");
		scanf("%d",&value);
		push1(value);
	//printf("Count value: %d\n",count);
	}
}

void deQueueRear()
{
	if(top1<0)
	{
		printf("Double Ended Queue empty\n");
	}
	else
	{
		int removedValue=pop1();
		count--;
		printf("Removed value: %d\n",removedValue);
	}
}

void enQueueFront()
{
	if(top1>=100)
	{
		printf("Double Ended Queue is full\n");
	}
	else
	{
		int i,value;
		for(i=0;i<count;i++)
		{
			push2(pop1());
		}
		int tempcount=count;
		printf("Enter value to be added: ");
		scanf("%d",&value);
		push1(value);
		count++;
		for(i=0;i<tempcount;i++)
		{
			push1(pop2());
		}
	}
}

void deQueueFront()
{
	if(top1<0)
	{
		printf("Double Ended Queue empty\n");
	}
	else
	{
		int i;
		for(i=0;i<count-1;i++)
		{
			push2(pop1());
		}
		int tempcount=count-1;
		int removedValue=pop1();
		count--;
		for(i=0;i<tempcount;i++)
		{
			push1(pop2());
		}
		printf("Removed Value: %d\n",removedValue);
	}
}
void push1(int value)
{
	//printf("Pushed in 1: %d\n",value);
	stack1[++top1]=value;
}

void push2(int value)
{
	stack2[++top2]=value;
}

int pop1()
{
	return stack1[top1--];
}

int pop2()
{
	return stack2[top2--];
}

void display()
{
	//printf("Count value: %d\n",count);
	int i;
	if(count==0)
		printf("Double Ended Queue empty\n");
	else
	{
		for(i=0;i<count;i++)
		{
			printf("%d ",stack1[i]);
		}
		printf("\n");
	}
}