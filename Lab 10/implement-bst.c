/*
	Implementing BST, 
	Operations done:-(i) insert
					 (ii)delete
					 (iv)maximum and minimum
*/	
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
struct node {
	int data;
	struct node *right;
	struct node *left;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

struct node *insert(struct node *node,int data)
{
	if(node==NULL)
		return newNode(data);
	if(data < node->data)
	{
		node->left = insert(node->left,data);
	}
	else if(data > node->data)
	{
		node->right = insert(node->right,data);
	}
	return node;
}

struct node* minValueNode(struct node* node)
{
	struct node *current=node;
	while(current->left!=NULL)
		current=current->left;

	return current;
}


int minValue(struct node* node)
{
	struct node *current=node;
	while(current->left!=NULL)
		current=current->left;

	return current->data;
}

int maxValue(struct node *node)
{
	struct node *current=node;
	while(current->right!=NULL)
		current=current->right;

	return current->data;
}

struct node* deleteNode(struct node *root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->data)
		root->left=deleteNode(root->left,key);
	else if(key > root->data)
		root->right=deleteNode(root->right,key);

	else
	{
		if(root->left ==NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		struct node* temp=minValueNode(root->right);
		root->data=temp->data;
		root->right=deleteNode(root->right,temp->data);
	}
}

int main()
{
	struct node *root = NULL;
	int data,choice,count=0;
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 0:
			if(count==0)
			{
				printf("Enter value of head: ");
				scanf("%d",&data);
				root = insert(root,data);
				count++;
			}
				break;
			case 1:
				printf("Enter data to insert: ");
				scanf("%d",&data);
				root = insert(root,data);
				printf("\n");
				break;
			case 2:
				printf("\nMinimum value in the tree: %d\n", minValue(root));
				printf("Maximum value in the tree: %d\n", maxValue(root));
				printf("\n");
				break;

			case 3:
				printf("Enter element to delete: ");
				scanf("%d",&data);
				root = deleteNode(root,data);
				printf("\n");
				break;
			case 4:
				printf("Inorder traversal\n");
				inorder(root);
				printf("\n");
				break;
			default:
				printf("Wrong choice\n");
		}
	
	}
	printf("\n");
}
