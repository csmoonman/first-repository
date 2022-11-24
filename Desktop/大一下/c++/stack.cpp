#include<iostream>

using namespace std; 

struct stack
{
	int* top;
	int* bottom;
	int stacksize=30;
};

//
bool init(struct stack& s);
bool push(struct stack& s, int num);
int pop(struct stack& s);
bool is_empty(struct stack s);

int main()
{
	struct stack s1;
	init(s1);
	while(1)
	{
		cout<<"push----1"<<endl<<"pop ----2"<<endl<<"exit----0"<<endl;
		int key;
		(cin>>key).get();
		if(key==1) 
		{
			int num;
			cout<<"push:";
			(cin>>num).get();
			cout<<endl;
			push(s1,num);
		}
		else if(key==2)
		{
			if(is_empty(s1))
			{
				cout<<"empty"<<endl;
				continue;
			}
			cout<<pop(s1)<<endl;
		}
		else if(key==0) exit(0);
		else cout<<"input again!"<<endl;
	}
	return 0;
}

bool init(struct stack& s)
{
	s.bottom=new int;
	if(s.bottom==NULL) return false;
	s.top=s.bottom;
	return true;
}
bool push(struct stack& s, int num)
{
	++s.top=new int;
	*s.top = num;
	
	return true;
}
int pop(struct stack& s)
{
	int* p=s.top;
	int temp=*p;
	s.top--;
	delete p;
	return temp;	
}

bool is_empty(struct stack s)
{
	if(s.bottom==s.top) return true;
	
	return false;
}

