#include<iostream>
#include<string>
using namespace std;

int main()
{
	//cin����,��ȡ���ո�ʱ������ȡ
	cout << "cin:" << endl;
	string s1;
	cin >> s1;
	cout << "���룺" << s1 << "#" << endl;
	char c;
	while ((c = getchar()) != '\n');

	//���Բ���ѭ���ķ�ʽ���������͵�������
	cout << "ѭ������string��" << endl;
	for (string s; cin >> s;)
	{
		cout << s << " ";
		if (*s.rbegin() == '#') break;//����#�Խ���
	}
	cout << endl;

	while ((c = getchar()) != '\n');

	cout << "ѭ������a[10]��" << endl;
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

	//Ҳ���Բ���getline����һ���Ե�����(getline��ͷ�ļ�string�У�
	cout << "getline��" << endl;
	string s2;
	getline(cin, s2);
	cout << s2 << endl;
	while ((c = getchar()) != '\n');

	//Ҳ���Բ���cin.getline����һ���Ե�����(getline��ͷ�ļ�string�У�
	cout << "cin.getline��" << endl;
	char b[40];
	cin.getline(b, 40);
	cout << b << endl;

	//����ַ�������
	cout << "����ַ����룺";
	for (char ch; (ch = getchar()) != '\n';)
		cout << ch;
	cout << endl;
	while ((c = getchar()) != '\n');

	string s3[3] = { "I","love","you" };
	for (int i = 0; i < 3; i++)
		cout << s3[i] << " ";

	return 0;
}