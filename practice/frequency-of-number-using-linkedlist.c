/*
	Program:- Show frequency of a number using linked list
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;
int counting=0;

void insert(int value)
{	
	struct node *temp=NULL,*ptr=head;
	temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Out of memory space\n");
	}
	else
	{
		temp->data=value;
		temp->next=NULL;
	}

	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

int count(int test)
{
	struct node *ptr=NULL;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data==test)
		{
			counting++;
		}
		ptr=ptr->next;
	}
	return counting;
}

void display()
{
	struct node *ptr=NULL;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	printf("\n");
}

int main()
{
	int value,test,answer,choice;
	printf("Press 1 to insert\nEnter 2 to see check frequency\nEnter 3 to exit\n\nEnter 4 to display\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter number to insert: ");
			scanf("%d",&value);
			insert(value);
			break;

			case 2:
			printf("Enter number to see its frequency: ");
			scanf("%d",&test);
			answer=count(test);
			printf("The frequency is: %d\n",answer);
			break;

			case 3:
			exit(0);

			case 4:
				display();
				break;

			default:
			printf("Wrong choice\n");
			break;
		}
		
	}
}