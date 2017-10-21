/*
	Inorder,Preorder,Postorder traversal of tree
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
int tree[1000];

void insert(int element,int root)
{
	if(tree[root]==0)
	{
		tree[root]=element;
		return;
	}
	char choice;
	printf("Enter l to insert at left\nEnter 2 to insert at right\n");
	printf("Enter choice: ");
	getchar();
	scanf("%c",&choice);
	if(choice=='l')
	{
		insert(element,2*root);
	}
	else
	{
		insert(element,2*root+1);
	}
}

void preorder(int root)
{
	if(tree[root]!=0)
	{
		printf("%d ",tree[root]);
		preorder(2*root);
		preorder(2*root+1);
	}
}

void inorder(int root)
{
	if(tree[root]!=0)
	{
		inorder(2*root);
		printf("%d ",tree[root]);
		inorder(2*root+1);
	}
}

void postorder(int root)
{
	if(tree[root]!=0)
	{
		postorder(2*root);
		postorder(2*root+1);
		printf(" %d",tree[root]);
	}
}
int main()
{
	int choice,element;
	printf("Enter 1 to insert\nEnter 2 to display the traversal\nEnter 3 to exit\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element to insert: ");
				scanf("%d",&element);
				insert(element,1);
				break;
			case 2:
				printf("Preorder traversal:\n");
				preorder(1);
				printf("Inorder traversal:\n");
				inorder(1);
				printf("Postorder traversal:\n");
				postorder(1);
				break;
			case 3:
				exit(1);

			default:
				printf("Wrong Choice\n");
				break;
		}
	}
}