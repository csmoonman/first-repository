#include<iostream>
using namespace std;

int main()
{
	for(int n=1;n<10;n++)
	{
		int i=1; 
		cout<<string(n,char('A'+n-1)) + '\n';
	}
}
