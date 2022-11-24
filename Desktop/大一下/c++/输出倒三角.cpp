#include<iostream>

using namespace std;

int main()
{
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=i-1;j++)
			cout<<" ";
		for(int k=1;k<=20-2*i+1;k++)
			cout<<"M";
		cout<<"\n";
	}
}
