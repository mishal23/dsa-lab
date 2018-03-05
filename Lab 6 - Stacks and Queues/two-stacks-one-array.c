/*
	Implement two stacks in an array
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int arr[100];
int top1=-1,top2=49;

void push(int stackno,int value)
{
	if(stackno==1)
	{
		if(top1<49)
		{	
			top1++;
			arr[top1]=value;
		}
		else
			printf("Stack1 is full\n");
	}
	else if(stackno==2)
	{
		if(top2<99)
		{	
			top2++;
			arr[top2]=value;
		}
		else
			printf("Stack2 is full\n");
	}
}

int pop(int stackno)
{
	if(stackno==1)
	{
		if(top1==-1)
		printf("Stack1 is empty\n");

    	else
    	{
    		top1--;
    	}	
	}
	else if(stackno==2)
	{
		if(top2==49)
		printf("Stack1 is empty\n");

    	else
    	{
    		top2--;
    	}	
	}
}

int top(int stackno)
{
	if(stackno==1)
	{
		if(top1==-1)
			printf("Stack1 is empty\n");
		else
			printf("Top of Stack1: %d\n",arr[top1]);
	}
	else if(stackno==2)
	{
		if(top2==49)
			printf("Stack2 is empty\n");
		else
			printf("Top of Stack2: %d\n",arr[top2]);
	}
}

int isEmpty(int stackno)
{
	if(stackno==1)
	{
		if(top1==-1)
			printf("Stack1 is empty\n");
		else
			printf("Stack1 is not empty\n");
	}
	else if(stackno==2)
	{
		if(top2==49)
			printf("Stack2 is empty\n");
		else
			printf("Stack2 is not empty\n");
	}
}

int main()
{
	int stackno,choice,element;
	while(1)
	{
		printf("Choose Stack[1/2]: ");
		scanf("%d",&stackno);
		if(stackno==1 || stackno==2)
		{
			printf("1 to push to Stack%d\n2 to pop from Stack%d\n3 to show the top element of stack%d\n4 to check is stack%d is empty or not\n10 to exit\n",stackno,stackno,stackno,stackno);
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("Enter the element to insert in Stack%d: ",stackno);
					scanf("%d",&element);
					push(stackno,element);
					break;
				case 2:
					pop(stackno);
					break;
				case 3:
					top(stackno);
					break;
				case 4:
					isEmpty(stackno);
					break;
				case 10:
					exit(0);
					break;
				default:
					printf("Incorrect choice\n");
					break;
			}
		}
		else
			printf("Choose only 1/2\n");
	}	
}
