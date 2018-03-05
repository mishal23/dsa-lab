#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int tree[1000];

void insert(int element,int root)
{
	char choice;
	if(tree[root]==0)
	{
		tree[root]=element;
		return;
	}
	
	printf("To insert on left node, press l\nTo insert on right node, press r\n");
	printf("Enter: ");
	getchar();
	scanf("%c",&choice);
	if(choice=='l')
		insert(element,2*root);
	else
		insert(element,2*root+1);
}

void delete_element(int root)
{
	int temp;
	if(tree[2*root]==0 && tree[2*root+1]==0)
	{
		tree[root]=0;
		return ;
	}
	if(tree[2*root] || tree[2*root+1]==0)
	{
		temp = tree[root];
		tree[root]=tree[2*root];
		tree[2*root]=temp;
		delete_element(2*root);
	}
	if(tree[2*root+1])
	{
		temp=tree[root];
		tree[root]=tree[2*root+1];
		tree[2*root+1]=temp;
		delete_element(2*root+1);
	}
}


void delete(int root)
{
	if(tree[root]==0)
	{
		printf("Tree empty\n");
		return;
	}
	int choice;
	char c;
	printf("Are you sure you want to delete %d\n",tree[root]);
	printf("Press y to confirm else press n to delete the next element\n");
	scanf("%d",&choice);
	if(choice=='y')
	{
		delete_element(root);
	}
	else
	{
		printf("To delete element at right press r,to delete element at left press l\n");
		printf("Enter choice: ");
		scanf("%c",&c);
		if(c=='l')
			return delete(2*root);
		else
			return delete(2*root + 1);
	}
}


bool search(int x,int root)
{
	if(tree[root]==0)
		return false;
	if(tree[root]==x)
		return true;
	return search(x,2*root) || search(x,2*root+1);
}

int main()
{
	int choice,element,searching;
	printf("Enter 1 to insert an element\nEnter 2 to delete an element\nEnter 3 to search an element\nEnter 4 to exit\n");
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
				delete(1);
				break;
			case 3:
				printf("Enter element to search: ");
				scanf("%d",&searching);
				if(search(searching,1))
					printf("Element %d found\n",searching);
				else
					printf("Element %d not found\n",searching);

				break;
			case 4:
				exit(0);
			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}