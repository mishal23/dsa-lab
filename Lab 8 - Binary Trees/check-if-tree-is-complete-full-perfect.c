/*
	Problem:- Check if tree is  (i)  complete or not
								(ii) full or not
								(iii)perfect or not
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

struct node{
	int data;
	struct node *left,*right;
};

struct node *newNode(char k)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=k;
	temp->right=temp->left=NULL;
	return temp;
}

int countNodes(struct node *root)
{
	if(root==NULL)
		return 0;
	return (1+countNodes(root->left)+countNodes(root->right));
}

bool isComplete(struct node *root,int index,int count)
{
	if(root==NULL)
		return true;

	if(index>=count)
		return false;

	return (isComplete(root->left,2*index+1,count) && isComplete(root->right,2*index+2,count));
}

bool isFull(struct node *root)
{
	if(root==NULL)
		return true;

	if(root->left==NULL && root->right==NULL)
		return true;

	if(root->left && root->right)
		return (isFull(root->left) && isFull(root->right));
}

int Depth(struct node *node)
{
	int depth=0;
	while(node!=NULL)
	{
		depth++;
		node=node->left;
	}
	return depth;
}

bool isPerfect(struct node *root,int depth,int height)
{
	if(root==NULL)
		return true;

	if(root->left==NULL && root->right==NULL)
		return depth=height+1;

	if(root->left==NULL || root->right==NULL)
		return false;

	return (isPerfect(root->left,depth,height+1) && isPerfect(root->right,depth,height+1));
}

bool isP(struct node *root)
{
	int depth= Depth(root);
	return isPerfect(root,depth,0);
}

int main()
{
	struct node *root=NULL;
	root = newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);
	//root->right->right=newNode(6);
	int count=countNodes(root);
	int index=0;

	if(isComplete(root,index,count))
		printf("Complete\n");
	else
		printf("Not Complete\n");

	if(isFull(root))
		printf("Full\n");
	else
		printf("Not Full\n");

	if(isP(root))
		printf("Perfect\n");
	else
		printf("Imperfect\n");

}