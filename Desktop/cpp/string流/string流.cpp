#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("stingaaa.txt");
	//ifstream in 这个文本要和slin在一个文件夹
	//istringstream是输入string流，在sstream头文件中说明。

	//第一个循环是将文本中的每一行单独输入到string流中，
	//第二个循环是将string流每一个整数都单独分开
	for (string s; getline(in, s);)
	{
		int a, sum = 0;
		for (istringstream sin(s); sin >> a; sum += a);
		cout << sum << endl;
	}
}

/*
#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("stringstream.txt");
	string pass[2] = { "1243556946","050055" };

	int flag = 0;
	for (string s; getline(in, s);)
	{
		int i = 0;
		cout << s.compare(pass[i])<<endl;
		cout << s << endl;
		if (!s.compare(pass[i++])) flag = 1;
		else flag = 0;
	}
	if (flag) cout << "验证通过" << endl;
	else cout << "账号或密码错误" << endl;

}
*/