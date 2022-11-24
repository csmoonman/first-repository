#include<iostream>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	cin.get();
	int a[n];
	int i=0;
	for(i;i<n;i++)
		cin>>a[i];
	cin.get();
	
	for(i=0;i<m;i++)
	{
		int temp=a[i];
		a[i]=a[n-m+i];
		a[n-m+i]=temp;
	}
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			cout<<a[i]<<" ";
		}
		else cout<<a[i];
	}
}
