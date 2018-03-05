/*
    Problem Statement:- An array  A contains (n-1) unique intergers in the range [0,n-1], that is there is one number from this range that is not in A. Design an O(n) time algorithm for finding that number. You are allowed to use only O(1) additional space besides the array A itself.
*/
#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n],sum=0,ans;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ans=(n*(n+1))/2;
    printf("%d",ans-sum);
}
