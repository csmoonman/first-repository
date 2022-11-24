#include<stdio.h>
#include<iostream>
#include<string.h>
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
	size_t i;
	for(i=0;i<len;i++)
		printf("%.2x",start[i]);
	printf("\n");
}

void show_int(int x)
{
	show_bytes((byte_pointer) &x,sizeof(int));
}

void show_float(float x)
{
	show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer) &x,sizeof(void *));
}

int main()
{
	int x=0x87654321;
	//std::cin>>x;
	const char*s="abcdef";
	//show_int(x);
	//show_float(x);
	//show_pointer(12345);
	show_bytes((byte_pointer) s,strlen(s));
	int a=3;
	int b=2;
	std::cout<<(1<<2)<<"\n";
	std::cout<<(2<<3)<<"\n";
	std::cout<<(1<<2)+(2<<3);
	
	std::cout<<"\a Enter your pin password:____\b\b\b\b";
	long code;
	std::cin>>code;
	std::cout<<"\a your code: "<<code<<std::endl;
}
