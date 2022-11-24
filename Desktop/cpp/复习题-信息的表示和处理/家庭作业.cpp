#include<iostream>

using namespace std;

//2.62
/*
* 原理：-1的位表示为0xFFFFFFFF 
	算数右移会在前面补最高位1，因此算术右移后仍不变
	逻辑右移会在前面补0，值改变
int int_shifts_are_arithmetic()
{
	int x = -1;
	return x == x >> 3;
}
int main()
{
	cout << int_shifts_are_arithmetic();
}
*/

//2.63 未完
/*
unsigned srl(unsigned x, int k)
{
	unsigned xsra = (int)x >> k;
	int w = sizeof(int) << 3;
	int mask = (int)-1 << (w - k);
	return xsra & (~mask);
}
*/

//2.64
/*
int any_odd_one(unsigned x)
{
	return !!(0x55555555 & x);//为什么要两次‘！’：以便返回1
}
int main()
{
	int a = 0x0111;
	cout << any_odd_one(a);
}
*/

//2.65
/*  https://blog.csdn.net/Aaron_Koyalun/article/details/78001832 
int odd_ones(unsigned x)
{
	x ^= (x >> 16);
	x ^= (x >> 8);
	x ^= (x >> 4);
	x ^= (x >> 2);
	x ^= (x >> 1);

	return x&0x01;
}

int main()
{
	int a = 0x1;
	cout << odd_ones(a);
}
*/

//2.66
/*
int leftmost(unsigned x)
{
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return (x >> 1) + (x & 0x1);
}
int leftmostless(unsigned x)
{
	x |= x << 1;
	x |= x << 2;
	x |= x << 4;
	x |= x << 8;
	x |= x << 16;

	return (x ^ 0xffffffff) + 0x1;
}
int main()
{
	unsigned a;
	a = 0xFF;
	cout << hex << leftmost(a) << endl;
	cout << hex << leftmostless(a);
}
*/
