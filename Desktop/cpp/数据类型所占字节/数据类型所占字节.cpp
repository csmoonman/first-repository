#include<iostream>
//#pragma warning(disable:4996)
using namespace std;

int main()
{
	cout << "char :" << sizeof(char) << endl;
	cout << "unsigned char :" << sizeof(unsigned char) << endl;
	cout << "short int :" << sizeof(short int) << endl;
	cout << "unsigned short int :" << sizeof(unsigned short int) << endl;
	cout << "int :" << sizeof(int) << endl;
	cout << "unsigned int :" << sizeof(unsigned int) << endl;
	cout << "long int : " << sizeof(long int) << endl;
	cout << "unsigned long int :" << sizeof(unsigned long int) << endl;


	string a, s1 = "Hello";
	string s2 = "cpp";
	a = s1;//复制
	cout << (a == s1 ? "" : "not" )<< "equal" << endl;//比较
	cout << a + ' ' + s2 << endl;//连接
	reverse(a.begin(), a.end());
	cout << a << endl;//倒置串
	cout << a.replace(2, 2, 7, 'G') << endl;//设置
	//在string字符串中的某一个位置开始长度为m的字符被替换为k个相同的字符
	//replace(size_t n, size_t m, size_t k, char c);
	cout << (s1.find("ell") ? "" : "not ") << "found" << endl;//查找串
	cout << (s1.find('c') ? "" : "not ") << "found" << endl;//查找字符

	return 0;
}
