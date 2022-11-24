#include<iostream>
#include<cmath>

using namespace std;

int is_prime(int n);

int main()
{
	int n;
	int i=0;
	int cnt=0;
	int doublecnt=0;
	(cin>>n).get();
	int* p=new int[n];

	while(i<=n)
	{
		if(is_prime(i))
		{
			p[cnt++] =i;
		}
		i++;
	}

	for(i=0;i<=cnt-1;i++)
		for(int j=i+1;(j<=(j+1))&&j<=cnt-1;j++)
		{
			if((p[i]-p[j])==-2) doublecnt++;
		}
	
	delete [] p;
	cout<<doublecnt;
} 

int is_prime(int n)
{

	if(n<=0||n==1) return 0;
	if(n==2) return 1;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return 0;
	}
	
	return 1;
}

