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
		cout << "��ȡ�� ��" << top << endl;
	}
	else
	{
		cout << "��ǰ�Ŷ������Ѵ����ޣ� " << endl;
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
	else cout << "��" << endl;
	return false;
}

stack::stack()
{
	top = 0;
}