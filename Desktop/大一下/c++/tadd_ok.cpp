#include<iostream>
#include<climits>

int tadd_ok(int x,int y);
int tsub_ok(int x,int y);


int main()
{
	using namespace std;
	int x,y;
	cin>>x>>y;
	cout<<tadd_ok(x,y);
	cout<<endl<<tsub_ok(x,y);
}

int tadd_ok(int x,int y)
{
	int sum=x+y;
	int neg_over= x<0 && y<0 &&sum>=0;
	int pos_over= x>0 && y>0 &&sum<0;
	
	return !neg_over && !pos_over;
}

int tsub_ok(int x,int y)
{
	if((x==INT_MIN||y<0)&&(x<0&&y==INT_MIN)) return 1;
	else if((y==INT_MIN&&x>=0)||(x==INT_MIN&&y>=0)) return 0;
	
	return tadd_ok(x,-y);
}
