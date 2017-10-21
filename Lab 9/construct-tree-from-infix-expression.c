/*
	Build a tree from infix expression
*/

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

char postfix[50],s[100];
int top=-1,toppp=-1;

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *stack[100];

void push(char a)
{
	top++;
	s[top]=a;
}
int empty()
{
	if(top==-1)
		return 1;
	return 0;
}
void pop()
{
	top--;
}
char topp()
{
	return s[top];
}
int pre(char x)
{
	switch(x)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}
void convert_to_postfix(char str[])
{
	int i=0,k=0;
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			postfix[k]=str[i];
			k++;
		}
		else if(str[i]==')')
		{
			while(topp()!='(' && !empty())
			{
				postfix[k]=topp();
				k++;
				pop();
			}
			pop();
		}
		else if(str[i]=='(')
		{
			push(str[i]);
		}
		else
		{
			if(pre(str[i])>pre(topp()))
			{
				push(str[i]);
			}
			else
			{
				while(!empty() && pre(str[i])<=pre(topp()))
				{
					postfix[k]=topp();
					k++;
					pop();
				}
				push(str[i]);
			}
		}
	}
	while(!empty())
	{
		postfix[k]=topp();
		k++;
		pop();
	}
	postfix[k]='\0';
	printf("Postfix expression: %s",postfix);
}

struct node *newNode(char x)
{
	struct node *ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=x;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

struct node *popp()
{
	return stack[toppp--];
}

void pushp(struct node *temp)
{
	stack[++toppp]=temp;
}

void inorder(struct node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		printf("%c ", temp->data);
		inorder(temp->right);
	}
}

void postorder(struct node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->left);
		postorder(temp->right);
		printf("%c ",temp->data);
	}
}

void preorder(struct node *temp)
{
	if(temp!=NULL)
	{
		printf("%c ",temp->data);
		preorder(temp->left);
		preorder(temp->right);
	}	
}
void construct_tree()
{
	int i=0;
	struct node *temp=NULL;
	for(i=0;postfix[i];i++)
	{
		if(postfix[i]=='*' || postfix[i]=='+' || postfix[i]=='-' || postfix[i]=='/')
		{
			temp=newNode(postfix[i]);
			temp->right=popp();
			temp->left=popp();
			pushp(temp);
		}
		else
		{
			temp=newNode(postfix[i]);
			pushp(temp);
		}
	}
	printf("\nInorder: ");
	inorder(temp);
	printf("\nPreorder: ");
	preorder(temp);
	printf("\nPostorder: ");
	postorder(temp);
	printf("\n");
}

int main()
{
	char str[50];
	printf("Enter infix expression: ");
	scanf("%s",str);
	convert_to_postfix(str);
	construct_tree();
}