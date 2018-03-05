/*
	Program:- Reverse Stack using recursion
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	int data;
	struct node *next;
};

void push(struct node **head,int value)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	if(temp==NULL)
	{
		printf("Insufficient memory\n");
		return ;
	}
	temp->data=value;
	temp->next=*head;

	*head = temp;

	return;
	
}

int pop(struct node **head)
{
	int element;
	struct node *temp=*head;
	if (*head == NULL)
	{
		printf("Stack empty\n");
		return;
	}
	else
	{
		element=temp->data;
		*head=temp->next;
		free(temp);
		//printf("Popped element: %d\n",element);
		return element;
	}

}
int isEmpty(struct node *head)
{
	if(head==NULL)
		return 1;
	else
		return 0;
}

void reverse(struct node **head)
{
	if(!isEmpty(*head))
	{
		int temp=pop(head);
		reverse(head);
		insertAtBottom(head,temp);
	}
	//printf("Reversed\n");
}

void insertAtBottom(struct node **head,int value)
{
	if(isEmpty(*head))
	{
		//printf("Empty stack: %d\n",value);
		push(head,value);
	}
	else
	{
		int temp=pop(head);
		insertAtBottom(head,value);
		push(head,temp);
	}
}

void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	printf("\n");

}

int main()
{
	struct node *stack=NULL;
	int value,test,answer,choice;
	printf("Press 1 to push \nEnter 2 to Reverse\nEnter 3 to display\nEnter 4 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter number to insert: ");
				scanf("%d",&value);
				push(&stack, value);
				break;
			case 2:
				reverse(&stack);
				break;
			case 3:
				display(stack);
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