/*
    Program to check if matrix is UpperTriangular or Lower Triangular across both the diagonals

    Part left to be done: Make a new 1D array which saves the elements of 2D matrix only upper or lower and
    then that element is accessed using 1D array rules
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("\nProgram to check whether entered matrix is Lower Triangular or Upper Triangular\n\n");
	int n,i,j;
	printf("Enter value of n:- ");
	scanf("%d",&n);
	int countupper=0,countlower=0,countdiagonal=0;
	int countupper1=0,countlower1=0,countdiagonal1=0,choice,r,c,k=0,ans=0;
	int *newarray = (int *)malloc(n*n*sizeof(int));

	int *a = (int *)malloc(n*n*sizeof(int));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter the value of a[%d][%d]:- ",i+1,j+1);
			scanf("%d",(a+i*n+j));
		}
	}
	printf("Entered Matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",*(a+i*n+j));
		}
		printf("\n");
	}
	printf("\n");
	printf("Enter 1 for main diagonal check\nEnter 2 for secondary diagonal check\n");\
	scanf("%d",&choice);
	switch(choice)
	{
		// Case1 of Main Diagonal (Upper Left to Bottom Right)
		case 1:
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i>j && *(a+i*n+j)==0)
				{
					countupper++;
				}
				if(i<j && *(a+i*n+j)==0)
				{
					countlower++;
				}
				if(i==j && *(a+i*n+j)!=0)
				{
					countdiagonal++;
				}
			}
		}
		if(countdiagonal==n && countlower+countupper==((n*n -n)))
		{
			printf("Diagonal Matrix\n");
		}
		else if(countupper==n)
		{
			printf("Upper Triangular Matrix\n");
			/*for(i=0;i<n;i++)
			{
				for(j=i;j<n;j++)
				{
					*(newarray + k)=*(a+i*n+j);
					k++;
				}
			}
			for(i=0;i<2*n;i++)
				{printf("%d ",*(newarray+i));}
			printf("\n");
			printf("Enter row and column:- ");
			scanf("%d %d",&r,&c);
			ans=(r-1)+2*(c-1);
			printf("ans=%d\n",ans);
			if(ans==2*n)
				printf("%d\n",*(newarray+2*n -1));
			else
				printf("%d\n",*(newarray+ans));*/

		}
		else if(countlower==n)
		{
			printf("Lower Triangular Matrix\n");
			/*for(i=0;i<n;i++)
			{
				for(j=0;j<=i;j++)
				{
					*(newarray+k)=*(a+i*n+j);
					k++;
				}
			}
			printf("Enter row and column:- ");
			scanf("%d %d",&r,&c);
			for(i=0;i<2*n;i++)
				{printf("%d ",*(newarray+i));}
			printf("\n");
			ans=(r-1)*2 + (c-1);
			printf("ans=%d\n",ans);
			if(ans==0)
				printf("%d\n",*(newarray+0));
			else if(ans==2*n)
				printf("%d\n",*(newarray+2*n -1 ));
			else
				printf("%d\n",*(newarray+ans));*/

		}
		else
		{
			printf("Normal Matrix\n");
		}
		break;

		// Case2 of Secondary Diagonal (Upper Right to Bottom left)
		case 2:

		for(i=0;i<n;i++)
		{
			for(j=0;j<=n-i-1;j++)
			{
				if(*(a+i*n+j)==0)
				{
					countupper1++;
				}
				if(i+j==(n-1) && *(a+i*n+j)!=0)
				{
					countdiagonal1++;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>=n-i-1;j--)
			{
				if(*(a+i*n+j)==0)
				{
					countlower1++;
				}
			}
		}
		if(countdiagonal1==n && countlower1+countupper1==((n*n -n)))
		{
			printf("Diagonal Matrix\n");
		}
		else if(countupper1==n)
		{
			printf("Upper Triangular Matrix\n");
		}
		else if(countlower1==n)
		{
			printf("Lower Triangular Matrix\n");
		}
		else
		{
			printf("Normal Matrix\n");
		}
		break;

		default:
		printf("Wrong Choice\n");
		break;
}

}
