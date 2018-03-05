/*
	Program to generate random arrays
*/
#include "bits/stdc++.h"
using namespace std;
int main()
{
	int i,j,n;
	int test=rand()%100;
	cout<<test<<endl;
	for(i=0;i<test;i++)
	{
		n=rand()%1000000;
		cout<<n<<endl;
		for(j=0;j<n;j++)
		{
			cout<<rand()%10000 + 1<<" ";
		}
		cout<<endl;

		cout<<rand()%n<<endl;
	}
}
