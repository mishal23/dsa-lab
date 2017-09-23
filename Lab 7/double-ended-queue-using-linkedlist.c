/*
	Double Ended Queue using Linkedlist
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct node{
	struct node *previous;
	int data;
	struct node *next;
};

struct node *head=NULL, *tail=NULL;

struct node *createNode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = newnode->previous = NULL;
	return(newnode);
}

void createS()
{
	head = createNode(0);
	tail = createNode(0);
	head->next = tail;
	tail->previous = head;
}

void insertAtFront(int data)
{
	struct node *newnode, *temp;
	newnode = createNode(data);
	temp = head->next;
	head->next = newnode;
	newnode->next = head;
	newnode->next = temp;
	temp->previous = newnode;
}

void insertAtRear(int data)
{	
	struct node *newnode, *temp;
	newnode = createNode(data);
	temp = tail->previous;
	tail->previous = newnode;
	newnode->next = tail;
	newnode->previous = temp;
	temp->next = newnode;
}

int deleteFromFront()
{
	struct node *temp;
	if(head->next == tail)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp=head->next;
		head->next = temp->next;
		temp->next->previous = head;
		free(temp);
	}
	return 0;
}

int deleteFromRear()
{
	struct node *temp;
	if(tail->previous == head)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp = tail->previous;
		tail->previous = temp->previous;
		temp->previous->next = tail;
		free(temp);
	}
	return 0;
}

void display()
{
	struct node *temp;
	if(head->next == tail)
	{
		printf("Queue is empty\n");
		return;
	}
	temp = head->next;
	while(temp!=tail)
	{
		printf("%-3d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	int value,choice;
	createS();
	printf("Enter 1 to insert at beginning\nEnter 2 to insert at rear\nEnter 3 to delete from front\nEnter 4 to delete from rear\nEnter 5 to display\nEnter 6 to exit");
	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data to insert: ");
				scanf("%d",&value);
				insertAtFront(value);
				break;

			case 2:
				printf("Enter data to insert: ");
				scanf("%d",&value);
				insertAtRear(value);
				break;

			case 3:
				deleteFromFront();
				break;

			case 4:
				deleteFromRear();
				break;

			case 5:
				display();
				break;

			case 6:
				exit(0);
				break;
		}
	}
}