#include<iostream>
#include<string>
using namespace std;

int main()
{
	//cin输入,读取到空格时结束读取
	cout << "cin:" << endl;
	string s1;
	cin >> s1;
	cout << "输入：" << s1 << "#" << endl;
	char c;
	while ((c = getchar()) != '\n');

	//可以采用循环的方式将内容输送到变量中
	cout << "循环输入string：" << endl;
	for (string s; cin >> s;)
	{
		cout << s << " ";
		if (*s.rbegin() == '#') break;//输入#以结束
	}
	cout << endl;

	while ((c = getchar()) != '\n');

	cout << "循环输入a[10]：" << endl;
	for (char a[10]; cin >> a;)
	{
		int i = 0;
		int flag = 0;
		for (i; i < 10; i++)
		{
			if (a[i] == '#')
			{
				flag = 1;
				break;
			}
		}
		cout << a << " ";
		if (flag == 1) break;
	}
	cout << endl;
	while ((c = getchar()) != '\n');

	//也可以采用getline将其一次性的输入(getline在头文件string中：
	cout << "getline：" << endl;
	string s2;
	getline(cin, s2);
	cout << s2 << endl;
	while ((c = getchar()) != '\n');

	//也可以采用cin.getline将其一次性的输入(getline在头文件string中：
	cout << "cin.getline：" << endl;
	char b[40];
	cin.getline(b, 40);
	cout << b << endl;

	//逐个字符的输入
	cout << "逐个字符输入：";
	for (char ch; (ch = getchar()) != '\n';)
		cout << ch;
	cout << endl;
	while ((c = getchar()) != '\n');

	string s3[3] = { "I","love","you" };
	for (int i = 0; i < 3; i++)
		cout << s3[i] << " ";

	return 0;
}