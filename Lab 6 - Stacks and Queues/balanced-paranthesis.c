/*
	Check for balanced paranthesis in an expression
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char stack[100];
int top=-1;

void push(char character)
{
    top++;
    stack[top]=character;
}

int pop()
{
    top--;
}

int top1()
{
	return stack[top];
}

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}

int isParanthesis(char character)
{
	if(character=='(' || character==')' || character=='[' || character==']' || character=='{' || character=='}')
		return 1;
	else
		return 0;
}

int main()
{
	int check=1,i;
	char str[100];
	printf("Enter an expression: ");
	scanf("%s",str);
	int l=strlen(str);
	for(i=0;i<l;i++)
	{
		if(isParanthesis(str[i]))
		{
			if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			{	
				push(str[i]);
				continue;
			}

			if(isEmpty())
				check=0;

			if(str[i]==')' && top1()=='(')
				pop();
			else if(str[i]==']' && top1()=='[')
				pop();
			else if(str[i]=='}' && top1()=='{')
				pop();
			else
			{
				check=0;
				break;
			}
		}
	}
	if(check && isEmpty())
		printf("\nBalanced Expression\n");
	else
		printf("\nNon-Balanced Expression\n");

}