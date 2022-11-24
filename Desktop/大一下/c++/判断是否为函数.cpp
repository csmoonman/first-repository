#include<iostream>
#include<cmath>
using namespace std;

int isprime(int n);

int main()
{
	int x;
	cin>>x;
	
	cout<<(isprime(x)? "yes\n" : "no\n");
	
}

int isprime(int n)
{
	if(n==1||n%2==0&&n!=2)
		return 0;
	for(int i=3;i<=sqrt(n);i++)
	{
		if(n%i==0) return 0;
	}
	
	return 1;
}
