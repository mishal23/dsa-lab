#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n,i,j,k;
	char temp[20];
	int temp1,temp2;
	printf("Enter number of students:- ");
	scanf("%d",&n);
	struct student
	{
		int rno;
		char name[20];
		int marks[3];
	};
	struct student *ptr;
	ptr =  malloc(n * sizeof(struct student)); 
	for (i = 0; i < n; ++i)
	{
		printf("Enter the name of student%d: ",i+1);
		scanf("%s",&(ptr + i)->name);
		printf("Enter the register No of student%d: ",i+1);
		scanf("%d",&(ptr + i)->rno);
		for (j = 0; j < 3; ++j)
		{
			printf("Enter marks of subject%d :- ",j);
			scanf("%d",&(ptr + i)->marks[j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		for(j = 0; j < n-1; j++)
		{
			if (strcmp((ptr + j)->name,(ptr + j +1)->name)>0)
			{
				// Element wise sorting
				/*
				strcpy(temp,(ptr + j +1)->name);
				strcpy((ptr + j +1)->name,(ptr + j)->name);
				strcpy((ptr + j)->name,temp);

				temp1 = (ptr + j +1)->rno;
				(ptr + j +1)->rno = (ptr + j)->rno;
				(ptr + j)->rno = temp1;

				for(k = 0;k<3; k++)
				{
					temp2 = (ptr + j +1)->marks[k];
				    (ptr + j +1)->marks[k] = (ptr + j)->marks[k];
				    (ptr + j)->marks[k] = temp2;
				}
				*/
				
				// Whole structure sorting
				struct student temp = *(ptr + j + 1);
				*(ptr + j + 1) = *(ptr + j);
				*(ptr + j) = temp;
				
			}
		}
	}
	for (i = 0; i < n; ++i)
	{
		printf("name : %s \n",(ptr + i)->name);
		printf("register No: %d\n",(ptr + i)->rno);
		for (j = 0; j < 3; ++j)
		{
			printf("marks of subject%d %d \n",j,(ptr + i)->marks[j]);
		}
		printf("\n");
	}
	printf("\n");
}