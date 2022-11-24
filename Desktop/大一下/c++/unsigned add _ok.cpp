#include<iostream>

int uadd_ok(unsigned x,unsigned y);

int main()
{
	using namespace std;
	unsigned x,y;
	cin>>x>>y;
	int sum_ok=uadd_ok(x,y);
	cout<<sum_ok<<endl;
}

int uadd_ok(unsigned x,unsigned y)
{
	unsigned sum=x+y;
	return sum>=x;
}
