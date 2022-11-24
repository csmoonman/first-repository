#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//string操作

	string a, s1 = "Hello";
	string s2 = "cpp";
	a = s1;//复制
	cout << (a == s1 ? "" : "not") << "equal" << endl;//比较
	cout << a + ' ' + s2 << endl;//连接
	reverse(a.begin(), a.end());
	cout << a << endl;//倒置串
	cout << a.replace(2, 2, 7, 'G') << endl;//设置
	//在string字符串中的某一个位置开始长度为m的字符被替换为k个相同的字符
	//replace(size_t n, size_t m, size_t k, char c);
	cout << (s1.find("ell") ? "" : "not ") << "found" << endl;//查找串
	cout << (s1.find('c') ? "" : "not ") << "found" << endl;//查找字符

	//C-串操作
	const char* s3 = "Hello";
	const char* s4 = "cpp";
	char b[20];
	strcpy(b, s3);//复制
	cout << (strcmp(b, s3) == 0 ? "" : "not ") << "equal" << endl;//比较
	cout << strcat(b, s4) << endl;//连接
	cout << strrev(b) << endl;//倒置
	cout << strset(b, 'G') << endl;//设置
	cout << (strstr(s3, "ell") ? "" : "not ") << "found" << endl;//查找串
	cout << (strchr(s3, 'c') ? "" : "not ") << "found" << endl;//查找字符


	return 0;
}
