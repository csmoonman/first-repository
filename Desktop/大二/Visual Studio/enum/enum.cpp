#include<iostream>

using namespace std;

int main()
{
	enum color {red=1,blue,black,white} c;
	c = blue;
	cout << c;
	
	return 0;
}
/*
	��c����Ϊcolor
	�������У���δ����ֵ���0��ʼ�ۼ�1
*/