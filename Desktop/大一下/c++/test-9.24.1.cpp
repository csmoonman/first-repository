#include<iostream>
#include<ctime>

int sp(int n); 

int main()
{
	using namespace std;
	/*
	float secs;
	cin>>secs;
	clock_t delay=secs*CLOCKS_PER_SEC; 
	clock_t start=clock(); //clock()返回现在的系统时间 
	while(clock()-start<delay);
	cout<<'\a';
	*/
	
	int x;
	cin>>x;
	cout<<sp(x);
}

int sp(int n)
{
	if(n==1) return 1;
	if(n%2!=0) return sp(n-1);
	else return (sp(n-1)+sp(n/2));
}
