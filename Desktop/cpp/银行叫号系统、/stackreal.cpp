#include"stack.h"
#include<iostream>
bool stack::isempty()
{
	return top == 0;
}

bool stack::isfull()
{
	return top == MAX;
}

bool stack::pop()
{
	using namespace std;
	if (!isfull())
	{
		items[top++] = top;
		cout << "已取号 ：" << top << endl;
	}
	else
	{
		cout << "当前排队人数已达上限！ " << endl;
		return false;
	}
	return true;
}

bool stack::push(item& i)
{
	using namespace std;
	if (!isempty())
	{
		i = top--;
		return true;
	}
	else cout << "空" << endl;
	return false;
}

stack::stack()
{
	top = 0;
}