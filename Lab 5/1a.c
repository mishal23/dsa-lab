/*
	Problem:- Postfix Expression using Stack

    Works for single digits

	How to Use:- Enter number of numbers+digits you want to enter initially and
				then the program will ask whether you want to enter number or operator.
				Choose and enjoy :p
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"

int stack[12345];
int top=-1;

void push(int element)
{
	if(top==12344)
	{
		printf("Stack is full\n");
	}
	else
	{
		top++;
		stack[top]=element-48;
	}
}

int top1()
{
	return stack[top];
}

void pop()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
		top--;
}

int answer(int num1, int num2, char sign)
{
	if(sign=='+')
		return num1+num2;
	if(sign=='-')
		return num2-num1;
	if(sign=='*')
		return num1*num2;
	if(sign=='/')
		return num2/num1;
	if(sign=='^')
		return pow(num2,num1);
}

int main()
{

	int i;
	char postfix[12345];
	scanf("%s",postfix);
	for(i=0;i<strlen(postfix);i++)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
		{
			push(postfix[i]);
		}
		else
		{
			int num1=top1();
			pop();
			int num2=top1();
			pop();
			int x=answer(num1,num2,postfix[i]);
			push(x+48);
		}
	}
	printf("%d\n",stack[top]);
	return 0;
	printf("\n\n");
	printf("*****************************\n");
	printf("*****   Answer= %d   ******\n",stack[top]);
	printf("*****************************\n");
	return 0;
}
