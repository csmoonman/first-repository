#include<iostream>
using namespace std;
typedef unsigned long  item;

class stack
{
	private:
		static const int Max=10;
		item items[Max];
		int top;
	public:
		bool isempty();
		bool isfull();
		bool pop(const item& i);
		bool push(item& i);
};
bool stack::isempty()
{
	return top==0;
}

bool stack::isfull()
{
	return top==Max;
}

bool stack::pop(const item& i)
{
	if(!isfull())
	{
		items[top++]=i;
	}
	else return false;
	
	return true;
}

bool stack::push(item& i)
{
	if(!isempty())
	{
		i=items[--top];
	}
	else return false;
	
	return true;
}

int main()
{
	stack a;
	a.pop(3);
	a.pop(4);
	
	item b;
	a.push(b);
	cout<<b<<endl;
	a.push(b);
	cout<<b<<endl;
}
