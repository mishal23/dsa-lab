/*
	Implement Queue using Array
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int queue[50];
int front=-1;
int rear=-1;

int enQueue(int value)
{
	if(front==-1 && rear==-1)
	{	
		front++;
		rear++;
		queue[rear]=value;
		printf("Element %d enQueued to Queue\n",queue[rear] );
	}
	else if(front>rear)
		printf("Queue overflow\n");
	else
	{
		rear++;
		queue[rear]=value;
		printf("Element %d enQueued to Queue\n",queue[rear] );
	}
}
 
void deQueue()
{
	if(front==-1 && rear==-1)
		printf("Queue empty\n");
	else if(front>rear)
		printf("Queue overflow\n");
	else
	{
		printf("Element %d deQueued from Queue\n", queue[front]);
		front++;
	}
}

void top()
{
	if(front==-1 && rear==-1 || front>rear)
		printf("Queue empty\n");
	else
		printf("Top element in Queue: %d\n", queue[front]);
}

int main()
{
	int choice,element;
	printf("Queue Implementation\n");
	printf("Enter 1 for enQueue\nEnter 2 for deQueue\nEnter 3 to display the front element\nEnter 10 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to insert:- ");
				scanf("%d",&element);
				enQueue(element);
				break;

			case 2:
				deQueue();
				break;

			case 3:
				top();
				break;

			case 10:
				exit(0);
				break;

			default:
				printf("Incorrect choice\n");
				break;
		}
	}
	return 0;
}