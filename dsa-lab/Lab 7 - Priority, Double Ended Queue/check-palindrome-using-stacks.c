
/*
	Check if string is palindrome or not using stacks
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
char stack[50];
int top1=-1;

int push(char value)
{
	stack[++top1]=value;
}

char pop()
{
	top1--;
}

char top()
{
	return stack[top1];
}

int isEmpty()
{
	if(top1==-1)
		return 1;
	else
		return 0;
}

int main()
{
	char s[50];
	int i;
	printf("Enter a string: ");
	scanf("%s",s);
	for(i=0;i<strlen(s);i++)
	{
		push(s[i]);
	}	
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=top())
		{
			printf("Not a palindrome\n");
			return 0;
		}
		else
			pop();
	}
	printf("Palindrome\n");
}
