#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int main()
{
	ifstream in("stingaaa.txt");
	//ifstream in ����ı�Ҫ��slin��һ���ļ���
	//istringstream������string������sstreamͷ�ļ���˵����

	//��һ��ѭ���ǽ��ı��е�ÿһ�е������뵽string���У�
	//�ڶ���ѭ���ǽ�string��ÿһ�������������ֿ�
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
	if (flag) cout << "��֤ͨ��" << endl;
	else cout << "�˺Ż��������" << endl;

}
*/