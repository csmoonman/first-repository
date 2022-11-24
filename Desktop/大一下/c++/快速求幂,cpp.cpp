#include<iostream>
#include<stdint.h>
int pow(int a,int b);

int main()
{
	int a,b;
	std::cout<<"请输入底、指数（以空格相连）：___\b\b\b";
	std::cin>>a;
	std::cin>>b;
	std::cout<<pow(a,b);
}

int pow(int a,int b)
{
	uint64_t r=1;
	uint64_t base = a;
	while(b!=0)
	{
		if(b%2) r*=base;
		base*=base;
		b/=2;
		//r=r%1000;
	}
	return r;
}
