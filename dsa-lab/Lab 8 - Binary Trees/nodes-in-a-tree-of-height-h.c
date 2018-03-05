/*
	Program:- To calculate number of nodes in a tree of height h
*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int main()
{
	int height;
	printf("Enter the height of the tree:- ");
	scanf("%d",&height);
	printf("The minimum number of nodes are:- %d\n",2*height + 1 );
	printf("The maximum number of nodes are:- %d\n", (int)pow(2,height)-1);
}