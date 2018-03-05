/*
	XOR linked list
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	int data;
	struct node *next;
};

struct node *XOR(struct node *a, struct node *b)
{
	return (struct node *)((unsigned int)(a) ^ (unsigned int)(b));
}

void insert(struct node **head)
{
	int value;
	printf("Enter data: ");
	scanf("%d",&value);

	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=XOR(*head,NULL);
	if(*head != NULL)
	{
		struct node *temp=XOR((*head)->next, NULL);
		(*head)->next = XOR(newnode,temp);
	}
	*head=newnode;
}

void display(struct node *head)
{
	struct node *curr=head;
	struct node *prev=NULL;
	struct node *temp;
	while(curr!=NULL)
	{
		printf("%d ", curr->data);
		temp=XOR(prev,curr->next);

		prev=curr;
		curr=temp;
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
