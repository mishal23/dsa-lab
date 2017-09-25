/*
	Doubly linked list
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	struct node *prev;
	int data;
	struct node *next;
};


void insert(struct node **head)
{
	int value;
	printf("Enter data: ");
	scanf("%d",&value);

	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	struct node *last=*head;
	newnode->data=value;
	newnode->next=NULL;

	if(*head == NULL)
	{
		newnode->prev=NULL;
		*head=newnode;
		return;
	}
	while(last->next !=NULL)
	{
		last=last->next;
	}
	last->next=newnode;
	newnode->prev=last;
	return;
}

void display(struct node *head)
{
	struct node *last;
	printf("Forward direction\n");
	while(head!=NULL)
	{
		printf("%d ", head->data);
		last=head;
		head=head->next;
	}
	printf("\n\n");	
	printf("Reverse diretion\n");
	while(last!=NULL)
	{
		printf("%d ",last->data);
		last=last->prev;
	}
	printf("\n");
}

int main()
{
	int choice;
	struct node *head=NULL;
	printf("Enter 1 to insert\nEnter 2 to display\nEnter 3 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert(&head);
				break;
			case 2:
				display(head);
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
