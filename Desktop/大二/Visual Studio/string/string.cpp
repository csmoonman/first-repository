#include<iostream>
#include<cstring>
#include<string>
/*
	#include<cstring>
	#include<string>
	����
	2 string�Ƿ���ģ����ԴӼ������е��ַ����������������CString��char*��
����2 CString��֮�����Դӻ�����һЩ�ַ��������������������char*�ȣ�
����2 char*û�й��캯���������Ը�ֵ��

	//�ʼǣ�string����cstring

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
	cout << "strcat(s1,s2)��strcat(s1.s3): " << s1 << endl;

	//string����ָ���±���ַ���c�����ͬ
	//��string�����������ʱ�����Կո�Ϊ�����������������getline(cin,str5);
	/*
		getline����������ͷ�ļ���
		��һ������include<string>�У�����ʱ�Կճ���Ϊ������
		�ڶ�������include<istream>�У������ʽ��Ϊ��ͬ��cin.getline(name,delim),delimΪ������ʶ��;
	*/

	cout << "����һ���ַ���" << endl;
	string str5;
	getline(cin, str5);
	//cin >> str5;
	
	int len = str5.length();
	cout << "�������룺 " << str5 << "\n" << "length: " << len << endl;
	cout << "���ʵڼ����ַ���" << endl;
	int n;
	cin >> n;

	while (1)
	{
		if (n >= 0 && n <= 9)
		{
			cout << "��" << n << "���ַ�Ϊ��" << str5[n - 1] << endl;
			break;
		}
		else
		{
			char ch1;
			while ((ch1 = getchar()) != '\n');
			cout << "��������" << "������������" << endl;
			cin >> n;
		}
	}

	//string��ɾ�������� erase(��ʼ�±꣬ɾ������) ���
	//��û�и���ɾ�����ȣ�������ʼ�±괦ȫ��ɾ��
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
	c++�н�c���е�sting���Ϳ�����+���������������㣬ä��string����ָ������
	+������������ָ��
	��char s[]��ָ��,���Կ���char* s;
*/