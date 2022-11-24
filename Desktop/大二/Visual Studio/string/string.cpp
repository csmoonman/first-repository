#include<iostream>
#include<cstring>
#include<string>
/*
	#include<cstring>
	#include<string>
	区别：
	2 string是方便的，可以从几乎所有的字符串构造而来，包括CString和char*；
　　2 CString次之，可以从基本的一些字符串变量构造而来，包括char*等；
　　2 char*没有构造函数，仅可以赋值；

	//笔记：string包含cstring

*/
using namespace std;

int main()
{
	string str1 = "I";
	string str2 = "love";
	string str3 = "you";
	string str4 = str1 + ' ' + str2 + ' ' + str3;

	cout << str4<<endl;

	char s1[10] = "You";
	char s2[10] = "love";
	char s3[10] = "me";
	char s4[10];
	char s5[10];

	strcat_s(s1, s2);
	strcat_s(s1, s3);

	strcpy_s(s4, s1);
	cout << "strcpy(s4,s1): " << s4 << endl;
	cout << "strcat(s1,s2)、strcat(s1.s3): " << s1 << endl;

	//string访问指定下标的字符和c风格相同
	//对string进行输入操作时，会以空格为结束，解决方法：用getline(cin,str5);
	/*
		getline包含在两个头文件中
		第一个是在include<string>中，输入时以空车键为结束；
		第二个是在include<istream>中，输入格式略为不同：cin.getline(name,delim),delim为结束标识符;
	*/

	cout << "输入一串字符串" << endl;
	string str5;
	getline(cin, str5);
	//cin >> str5;
	
	int len = str5.length();
	cout << "您的输入： " << str5 << "\n" << "length: " << len << endl;
	cout << "访问第几个字符？" << endl;
	int n;
	cin >> n;

	while (1)
	{
		if (n >= 0 && n <= 9)
		{
			cout << "第" << n << "个字符为：" << str5[n - 1] << endl;
			break;
		}
		else
		{
			char ch1;
			while ((ch1 = getchar()) != '\n');
			cout << "输入有误" << "，请重新输入" << endl;
			cin >> n;
		}
	}

	//string的删除操作用 erase(起始下标，删除长度) 完成
	//若没有给出删除长度，则会从起始下标处全部删除
	string str6 = "This is my first time to use VS";
	string str7, str8;
	str7 = str8 = str6;
	str7.erase(10);
	str8.erase(10, 3);

	cout << str6 << endl;
	cout << str7 << endl;
	cout << str8 << endl;

	return 0;
}
/*
	c++中较c特有的sting类型可以用+号来进行连接运算，盲猜string不是指针类型
	+不能连接两个指针
	而char s[]是指针,可以看作char* s;
*/