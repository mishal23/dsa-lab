/*
    Problem Statement:- Given a randomly ordered array of ' n' elements. Determine the kth smallest element in the set.
*/
#include<stdio.h>
int main()
{
    int n,i,j,temp,k;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    if(k>n-1){
        printf("Improper\n");
    }
    else{
        printf("%d",a[k-1]);
    }
}
