#include<iostream>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	//string����

	string a, s1 = "Hello";
	string s2 = "cpp";
	a = s1;//����
	cout << (a == s1 ? "" : "not") << "equal" << endl;//�Ƚ�
	cout << a + ' ' + s2 << endl;//����
	reverse(a.begin(), a.end());
	cout << a << endl;//���ô�
	cout << a.replace(2, 2, 7, 'G') << endl;//����
	//��string�ַ����е�ĳһ��λ�ÿ�ʼ����Ϊm���ַ����滻Ϊk����ͬ���ַ�
	//replace(size_t n, size_t m, size_t k, char c);
	cout << (s1.find("ell") ? "" : "not ") << "found" << endl;//���Ҵ�
	cout << (s1.find('c') ? "" : "not ") << "found" << endl;//�����ַ�

	//C-������
	const char* s3 = "Hello";
	const char* s4 = "cpp";
	char b[20];
	strcpy(b, s3);//����
	cout << (strcmp(b, s3) == 0 ? "" : "not ") << "equal" << endl;//�Ƚ�
	cout << strcat(b, s4) << endl;//����
	cout << strrev(b) << endl;//����
	cout << strset(b, 'G') << endl;//����
	cout << (strstr(s3, "ell") ? "" : "not ") << "found" << endl;//���Ҵ�
	cout << (strchr(s3, 'c') ? "" : "not ") << "found" << endl;//�����ַ�


	return 0;
}
