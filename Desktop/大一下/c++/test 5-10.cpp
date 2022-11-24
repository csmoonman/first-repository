//12 print odd or even 
#include<iostream>

using namespace std;
int printeven(int m,int n)
{
	if(n<m)
		return 0;
	else
	{
		cout<<m<<" ";
		printeven(m+2,n);
	}
}

int printodd(int m,int n)
{
	if(n<m)
		return 0;
	else
	{
		cout<<m<<" ";
		printodd(m+2,n);
	}
}

int main()
{
	int m,n;
	cout<<"输入上下限"<<endl;
	
	cin>>m>>n;

	if(m%2==0)
	{	
		cout<<"even:";
		printeven(m,n);
		cout<<"\n";
    	cout<<"odd:";
		printodd(m+1,n);
	}
	
	if(m%2!=0)
	{
		cout<<"even:";
		printeven(m+1,n);
		cout<<"\n";
		cout<<"odd:";
		printodd(m,n);
	}
	return 0;
}


