/*
	Priority queue using linkedlists
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct node{
	int value,pr;
	struct node *next;
}*start;

void push(int, int);
void pop();

void display()
{
	struct node *temp;
	temp=start;
	printf("Priority Queue: \n");
	while(temp!=NULL)
	{
		printf("%d %d\n",temp->value,temp->pr);
		temp=temp->next;
	}
	printf("\n");
}

void push(int element, int priority)
{
	struct node *temp,*t;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->value=element;
	temp->pr=priority;
	temp->next=NULL;

	if(start==NULL)
		start=temp;
	else if(start->pr > priority)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		t=start;
		while(t->next!=NULL && (t->next)->pr <= priority)
			t=t->next;
		temp->next=t->next;
		t->next=temp;
	}
	display();
}

void delete()
{
	if(start!=NULL)
	{
		printf("\nRemoved: %d\n",start->value);
		start=start->next;
		display();
	}
	else
	{
		printf("List empty\n");
	}
}

int main()
{
	int element,priority,choice;
	printf("Enter 1 to insert\nEnter 2 to remove\nEnter 3 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element and its priority: ");
				scanf("%d %d",&element,&priority);
				push(element,priority);
				break;
			case 2:
				delete();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Enter proper choice\n");
				break;
		}
	}
}
