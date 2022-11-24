#include<iostream>

namespace n1
{
	int x=1;
 } 
namespace n2
{
	int x=2;
}

int main()
{
	using n1::x;
//	using n2::x;
	std::cout<<x;
}
