/*
	Reverse a string using stack
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
    printf("%c", stack[top]);
    top--;
}

int main()
{
	int i,l;
	char str[50];
	printf("Enter the string: ");
	scanf("%s",str);
	l=strlen(str);
	for(i=0;i<l;i++)
	{
		push(str[i]);
	}
	printf("Reversed String: ");
	for(i=0;i<l;i++)
	{
		pop();
	}
	printf("\n");

}