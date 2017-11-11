/*
	AVL Tree Implementation 
	Implements: (i)  Insertion
				(ii) Deletion
				(iii)Searching
				(iv) Inorder print
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct node{
	int data;
	struct node *left;
	struct node *right;
	int height;
};

struct node *newnode(int key)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=key;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}

int getHeight(struct node *node)
{
	if(node==NULL)
		return 0;
	return node->height;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int getBalance(struct node *root)
{
	if(root==NULL)
		return 0;
	return getHeight(root->left)-getHeight(root->right);
}

struct node *rightRotate(struct node *root)
{
	struct node *x=root->left;
	struct node *temp2=x->right;

	x->right=root;
	root->left=temp2;

	root->height=max(getHeight(root->left),getHeight(root->right))+1;
	x->height=max(getHeight(x->left),getHeight(x->right))+1;
	
	return x;	
}

struct node *leftRotate(struct node *root)
{
	struct node *y=root->right;
	struct node *temp2=y->left;

	y->left=root;
	root->right=temp2;

	root->height=max(getHeight(root->left),getHeight(root->right))+1;
	y->height=max(getHeight(y->left),getHeight(y->right))+1;
	
	return y;	
}

struct node* minValueNode(struct node* node)
{
	struct node *current=node;
	while(current->left!=NULL)
		current=current->left;

	return current;
}

struct node *insert(struct node *node,int key)
{
	if(node==NULL)
		return newnode(key);
	if(key<node->data)
		node->left=insert(node->left,key);
	else if(key>node->data)
		node->right=insert(node->right,key);
	else
		return node;

	node->height = 1 + max(getHeight(node->left),getHeight(node->right));

	int balance = getBalance(node);

	if(balance>1 && key<node->left->data)
		return rightRotate(node);
	if(balance<-1 && key>node->right->data)
		return leftRotate(node);
	if(balance>1 && key>node->left->data)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && key<node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
	
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

struct node *deleteNode(struct node *root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->data)
		root->left=deleteNode(root->left,key);
	else if(key>root->data)
		root->right=deleteNode(root->right,key);
	else
	{
		if(root->left==NULL || root->right==NULL)
		{
			struct node *temp=root->left?root->left:root->right;

			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
			{
				*root= *temp;
			}
			free(temp);
		}
		else
		{
			struct node *temp=minValueNode(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
	}
	if(root==NULL)
		return root;

	root->height = 1 + max(getHeight(root->left),getHeight(root->right));

	int balance = getBalance(root);

	if(balance>1 && key<root->left->data)
		return rightRotate(root);
	if(balance<-1 && key>root->right->data)
		return leftRotate(root);
	if(balance>1 && key>root->left->data)
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && key<root->right->data)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

int search(struct node *root,int element)
{
	while(root!=NULL)
	{
		if(element<root->data)
			return search(root->left,element);
		else if(element>root->data)
			return search(root->right,element);
		else
			return 1;
	}
	return 0;
}

int main()
{
	struct node *root=NULL;
	int choice,data,element,ans;
	printf("Enter 1 to insert\nEnter 2 for preorder traversal\nEnter 3 to delete an element\nEnter 4 to search an element\nEnter 5 to exit\n");
	while(1)
	{
		printf("****\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the value to insert: ");
				scanf("%d",&data);
				root = insert(root,data);
				break;
			case 2:
				printf("Inorder traversal\n");
				inorder(root);
				printf("\n");
				break;
			case 3:
				printf("Enter element to delete: ");
				scanf("%d",&element);
				root = deleteNode(root,element);
				break;
			case 4:
				printf("Enter element to search: ");
				scanf("%d",&element);
				ans=search(root,element);
				if(ans==1)
					printf("element found\n");
				else
					printf("element not found\n");
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Wrong choice\n");
				break;
		}
	}
    printf("\n");
}
