/*
	Sort a linked list
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	int data;
	struct node *next;
};

void insert(struct node **head)
{
	int value;
	printf("Enter data: ");
	scanf("%d",&value);

	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	struct node *last = *head;
	//printf("Allocated new node\n");
	newnode->data=value;
	//printf("Allocated value\n");
	newnode->next=NULL;
	//printf("Allocated null to newnode\n");
	if(*head == NULL)
	{
		*head=newnode;
		return;
	}
	while(last->next !=NULL)
	{
	 	last=last->next;
	}
	last->next=newnode;
	return;
	//printf("new node pointed to head\n");
}

void sort(struct node **head)
{
	int val,swapped;
	//printf("Sorting\n");
	
	struct node *temp2=NULL;
	do
	{
		struct node *temp1=*head;
		swapped=0;
		while(temp1->next!=temp2)
		{
			if(temp1->data > temp1->next->data)
			{
				val = temp1->data;
				temp1->data = temp1->next->data;
				temp1->next->data = val;
				swapped=1;
			}
			temp1=temp1->next;
		}
		temp2=temp1;
	}while(swapped);
	//printf("Sorted\n");
}

void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int choice;
	struct node *head=NULL;
	printf("Enter 1 to insert\nEnter 2 to sort\nEnter 3 to display\nEnter 4 to exit\n");
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
				sort(&head);
				break;
			case 3:
				display(head);
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Enter proper\n");
				break;
		}
	}
}
