#include<iostream>
using namespace std;

int main()
{
	for(int i=1;i<=10;++i)
	{
		for(int j=1;j<=10-i;++j)
			cout<<" ";
		for(int ch='A';ch<'A'+2*i-1;++ch)
			cout<<char(ch);
		
		cout<<"\n";
	}
}
