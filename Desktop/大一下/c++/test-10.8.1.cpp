#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename T1,typename T2>
auto mult(T1 x, T2 y)->decltype(x* y);

int main()
{
	cout << mult(1.2, 3);
}
template<typename T1, typename T2>
auto mult(T1 x, T2 y)->decltype(x* y)
{
	return x * y;
}
