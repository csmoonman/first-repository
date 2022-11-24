#include<iostream>

int divpow(int x,int y);
int myIntMult(int x,int y);
int cntLast(int x);

int main()
{
	using namespace std;
	int x,y;
	cin>>x>>y;
	cout<<divpow(x,y);
}

int divpow(int x,int y)
{
	int cnt=0;
	int cy=y;
	while(cy!=1)
	{
		cy/=2;
		cnt++;
	}
	return (x<0 ? x+(1<<cnt)-1 : x)>>cnt;
}



