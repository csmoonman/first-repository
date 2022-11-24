#include<iostream>

using namespace std;

int main()
{
	int a[3]={1,2,3};
	int b[3]={4,5,6};
	int c[3]={7,8,9};
	
	int * pA[3]={a,b,c};
	
	for(int x: *a)
	{
		cout<<x;
	}
	
}
