/*
	Check Binary Search Tree or not
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INT_MIN -100
#define INT_MAX 10000
struct node {
	int data;
	struct node *left;
	struct node *right;
};

int checkBST(struct node *node,int min,int max)
{
	if(node==NULL)
		return 1;
	if(node->data < min || node->data>max)
	{
		return 0;
	}

	return checkBST(node->left,min,node->data-1) && checkBST(node->right,node->data+1,max);
}

int isBST(struct node* node)
{
	return(checkBST(node,INT_MIN,INT_MAX));
}

struct node* newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}
int main()
{
	struct node *root = newNode(4);
	root->left = newNode(2);
	root->right=newNode(5);
	root->left->left = newNode(1);
	//root->left->right = newNode(5);


	if(isBST(root))
		printf("The given tree is BST\n");
	else
		printf("The given tree is not BST\n");
}