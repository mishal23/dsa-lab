/*
	Find height, given the maximum number of nodes
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
int main()
{	
	int nodes,height;
	printf("Enter maximum number of nodes: ");
	scanf("%d",&nodes);
	height = ceil((float)(log(nodes+1)/log(2)));
	if(height==0)
	{
		printf("Did you just enter a stupid input?\n");
	}
	else
		printf("Height: %d\n",height-1);
}