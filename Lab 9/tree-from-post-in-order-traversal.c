/*
	Given postorder and inorder traversal, construct tree
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *newNode(char x)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

int search(char inorder[],int start,int end,int element)
{
	int i;
	for(i=0;i<=end;i++)
	{
		if(inorder[i]==element)
			return i;
	}
}

struct node *buildTree(char postorder[],char inorder[],int start,int end,int *ptr)
{
	if(start>end)
		return NULL;
	
	struct node *tree=newNode(postorder[*ptr]);
	(*ptr)=(*ptr)-1;
	if(start==end)
	{
		return tree;
	}

	int index=search(inorder,start,end,tree->data);

	tree->left=buildTree(postorder,inorder,start,index-1,ptr);
	tree->right=buildTree(postorder,inorder,index+1,end,ptr);
}

void inorder_traversal(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder_traversal(ptr->left);
		printf("%c",ptr->data);
		inorder_traversal(ptr->right);
	}
}

int main()
{
	char postorder[100],inorder[100];
	printf("Enter inorder traversal: ");
	scanf("%s",inorder);
	printf("Enter preorder traversal: ");
	scanf("%s",postorder);
	int ptr=strlen(inorder)-1;
	struct node *root=buildTree(postorder,inorder,0,strlen(inorder)-1,&ptr);

	printf("Inorder Traversal of constructed tree:\n");
	inorder_traversal(root);

	printf("\n");
}