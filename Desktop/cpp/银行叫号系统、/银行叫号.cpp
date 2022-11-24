#include"stack.h"
#include<iostream>

int main()
{
	using namespace std;
	stack A;
	char ch;
	unsigned s;
	while (cin >> ch && (ch != 'Q'))
	{
		while (cin.get() != '\n')
			continue;
		switch (ch)
		{
		case 'A':
		case 'a': A.pop();
			break;
		case 'P':
		case 'p':if(A.push(s))
					cout << s << endl;
			break;
		case'Q':
			cout << "bye ! " << endl;
			break;
		default:cout <<'\a' << "Error input ! " << endl;
			break;
		}
	}
}