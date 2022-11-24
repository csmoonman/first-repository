#include<iostream>
#include<cstdint>

int tmult_ok(int x,int y); 
int t64mult_ok(int x,int y); 

int main()
{
	using namespace std;
	int x,y;
	cin>>x>>y;
	cout<<tmult_ok(x,y);
}

int tmult_ok(int x,int y)
{
	int mult=x*y;
	
	return !x||mult/x==y;
}

int t64mult_ok(int x,int y)
{
	int64_t mult = (int64_t) x*y;
	
	return mult==(int)mult;
}
