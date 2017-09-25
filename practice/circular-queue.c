/*
	Program:- Implementing Circular queue 
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 5
int top=-1;
int rear=-1;
int queue[MAX];
void enQueue(int value)
{
	if(rear>=MAX-1)
	{
		rear++;
		rear = (rear%MAX);
		printf("Rear: %d\n",rear);
		if(queue[rear]==-1)
		{
			queue[rear]=value;
		}
		else
		{
			printf("Queue full\n");
			rear--;
		}
	}
	else
	{
		rear++;
		printf("Rear: %d\n",rear);
		if(queue[rear]==-1 || queue[rear]==0)
		{
			queue[rear]=value;
		}
		else
		{	
			printf("Queue full\n");
			rear--;
		}
	}
}

void deQueue()
{
	top++;
	if(top<0)
	{
		printf("Queue empty\n");
	}
	else
	{
		printf("Dequeued element: %d\n",queue[top]);
		queue[top]=-1;
	}
}

void display()
{
	int i;
	for(i=0;i<MAX;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");

}

int main()
{
	int value,test,answer,choice;
	printf("Press 1 to enqueue\nPress 2 to dequeue\nEnter 3 to display\nEnter 4 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter number to insert: ");
				scanf("%d",&value);
				enQueue(value);
				break;
			case 2:
				deQueue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Wrong choice\n");
				break;
		}		
	}
}