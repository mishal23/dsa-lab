#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int n,temp,j,i;
	clock_t begin,end;
	printf("Enter value of n:- ");
	scanf("%d",&n);
	int *ptr = malloc(n * sizeof(int));
	for (i = 0; i < n; ++i)
	{
		/*printf("Enter %d value of array:- ",i+1);
		scanf("%d",(ptr+i));*/
		*(ptr + i) = rand() % 100;
	}
	begin = clock();
	for (i = 0; i < n-1; i++)
	{
		for(j=i; j<n; j++)
		{
			if (*(ptr + i)> *(ptr + j))
			{
				temp = *(ptr + i);
				*(ptr + i) = *(ptr + j);
				*(ptr + j) = temp;
			}
		}
	}
	end = clock();
	float time = ((double)end - (double)begin)/CLOCKS_PER_SEC ;
	printf("Sorted Array\n");
	for (i = 0; i < n; ++i)
	{
		printf("%d ", *(ptr + i));
	}
	printf("\nTime Taken: %f\n", time);
	printf("\n");
	return 0;
}