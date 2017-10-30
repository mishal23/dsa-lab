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
	root = insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	printf("\nInorder traversal of the tree:\n");
	inorder(root);

	printf("\nMinimum value in the tree: %d\n", minValue(root));
	printf("Maximum value in the tree: %d\n", maxValue(root));
	printf("\nDeleting 20\n");
	root=deleteNode(root,20);

	printf("\nNew inorder traversal of the tree\n");
	inorder(root);

	printf("\nDeleting 30\n");
	root=deleteNode(root,30);

	printf("\nNew inorder traversal of the tree\n");
	inorder(root);

	printf("\nDeleting 50\n");
	root=deleteNode(root,50);

	printf("\nNew inorder traversal of the tree\n");
	inorder(root);
	printf("\n");
}