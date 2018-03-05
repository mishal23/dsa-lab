/*
	Merge two Sorted linked lists
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

struct node *sort(struct node **headA, struct node **headB)
{
	struct node *result=NULL;
	struct node *tempA = *headA;
	struct node *tempB = *headB;
	if(tempA == NULL)
	{
		return tempB;
	}
	if(tempB ==NULL)
		return tempA;

	if(tempA->data <= tempB->data)
	{
		result=tempA;
		result->next = sort(&tempA->next,&tempB);
	}
	else
	{
		result=tempB;
		result->next = sort(&tempA,&tempB->next);
	}
	return result;
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
	struct node *headA=NULL;
	struct node *headB=NULL;
	struct node *result;
	printf("Enter 1 to insert A\nEnter 2 to insert in B\nEnter 3 to sort\nEnter 4 to display A\nEnter 5 to display B\nEnter 6 to display merged list\nEnter 7 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert(&headA);
				break;
			case 2:
				insert(&headB);
				break;
			case 3:
				result = sort(&headA,&headB);
				break;
			case 4:
				display(headA);
				break;
			case 5:
				display(headB);
				break;
			case 6:
				display(result);
			case 7:
				exit(0);
				break;
			default:
				printf("Enter proper\n");
				break;
		}
	}
}
