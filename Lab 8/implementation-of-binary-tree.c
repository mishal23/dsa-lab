#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	int data;
	struct node *left;
	struct node *right;
};

void generate(struct node **,int);
int search(struct node *,int);
void delete(struct node **);
int main()
{
	struct node *head=NULL;
	printf("Enter 1 to insert in binary tree\nEnter 2 to search in binary tree\nEnter 3 to delete the binary tree\nEnter 4 to exit\n");
	while(1)
	{
		int choice,number,flag=0,key;
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to insert: ");
				scanf("%d",&number);
				generate(&head,number);
			break;

			case 2:
				printf("Enter element to search: ");
				scanf("%d",&key);
				flag = search(head,key);
				if(flag)
				{
					printf("Element found in tree\n");
				}
				else
				{
					printf("Element not found\n");
				}
			break;

			case 3:
				delete(&head);
				printf("Tree deleted\n");
				return 0;
			break;

			case 4:
				exit(0);
			break;

			default:
				printf("Wrong Choice\n");
		}
	}
}

void generate(struct node **head,int number)
{
	struct node *temp = *head, *prev=*head;
	if(*head == NULL)
	{
		*head = (struct node *)malloc(sizeof(struct node));
		(*head)->data = number;
		(*head)->left = (*head)->right = NULL;
	}
	else
	{
		while(temp!=NULL)
		{
			if(number > temp->data)
			{
				prev = temp;
				temp = temp->right;
			}
			else
			{
				prev = temp;
				temp = temp->left;
			}
		}
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = number;
		if(number >= prev->data)
		{
			prev->right = temp;
		}
		else
		{
			prev->left = temp;
		}
	}
}

int search(struct node *head, int key)
{
	while(head!=NULL)
	{
		if(key > head->data)
		{
			return search(head->right,key);
		}
		else if(key < head->data)
		{
			return search(head->left, key);
		}
		else
			return 1;
	}
	return 0;
}

void delete(struct node **head)
{
	if(*head !=NULL)
	{
		if((*head)->left)
		{
			delete(&(*head)->left);
		}
		if((*head)->right)
		{
			delete(&(*head)->right);
		}
		free(*head);
	}
}
