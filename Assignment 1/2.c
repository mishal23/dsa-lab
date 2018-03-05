/*
    Problem Statement:- Given the set of 'n' distinct numbers. Find the length of the longest monotone increasing subsequence.
*/
#include<stdio.h>
int main()
{
    int n,i,j,max;
    scanf("%d",&n);
    int a[n],count=0,list[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        list[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i]>a[j] && list[i]<list[j]+1)
            {
                list[i]=list[j]+1;
            }
        }
    }
    max=list[0];
    for(i=0;i<n;i++)
    {
        if(list[i]>max)
        {
            max=list[i];
        }
    }
    printf("%d",max);
}

