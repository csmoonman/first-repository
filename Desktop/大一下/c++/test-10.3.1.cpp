#include<iostream> 
int &suma(int x,int y);

int main()
{
	using namespace std;
	int x=9,y=9;
	int sum=x;
	sum=suma(x,y);
	cout<<sum;
}
int &suma(int x,int y)
{
	int sum=x+y;
	return sum;
}
