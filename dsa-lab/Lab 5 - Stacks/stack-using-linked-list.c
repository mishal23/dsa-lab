/*
	Problem:- Implement Stack using Linked List
*/
#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

void push();
void pop();
void top();
void empty();

struct node{
	int data;
	struct node *next;
};

struct node *stack;
int main()
{
	int choice;
	printf("Enter\n");
	printf("1-Push element to Stack\n2-Pop element from Stack\n3-Top element of Stack\n4-Check if Stack is empty\n5-Exit\n");
	while(1)
	{
		printf("Your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				top();
				break;
			case 4:
				empty();
				break;
			case 5:
				exit(0);
				break;
		}
	}
	return 0;
}

void push()
{
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	int element;
	printf("Enter element to insert: ");
	scanf("%d",&element);
	ptr->data = element;
	ptr->next = stack;
	stack = ptr;
	printf("Element inserted\n");
}

void pop()
{

	struct node *temp;
	if(stack==NULL)
	{
		printf("Stack empty, Cannot pop element\n");
	}
	else
	{
		temp=stack;
		stack = temp->next;
		free(temp);
		printf("Top Element popped\n");
	}

}

void top()
{
	if(stack==NULL)
	{
		printf("Stack empty, no top element\n");
	}
	else
	{
		printf("Top Element: %d\n", stack->data);
	}
}

void empty()
{
	if(stack==NULL)
	{
		printf("Stack Empty\n");
	}
	else
		printf("Stack not empty\n");
}
