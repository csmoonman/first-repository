#include<iostream>
#include"queue.h"
using namespace std;
int main()
{
	queue q;
	item i;
	int ch;
	while(cin>>ch&&ch!='Q')
	{
		while(cin.get()!='\n')
			continue;
		switch(ch)
		{
			case 'A':
			case 'a': 
			item x;
			(cin>>x).get();
			if(q.push(x))
			{
				cout<<x<<" succeed!"<<endl;
			}
			break;
			case 'p':
			case 'P':
				if(q.pop(x)) cout<<x<<" pop"<<endl;
				else cout<<"Пе"<<endl;
				break;
			case 'Q':
			case 'q':
				break;
		}
	}
}
