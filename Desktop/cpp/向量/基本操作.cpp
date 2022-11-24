/*
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> a(10);
	vector<int> b(10, 1);
	vector<int> c(b);
	vector<int> d(b.begin(), b.begin() + 3);
	vector<char>e(3, 'a');
	vector<string> f(3, "hello");
	
	int arr[7] = { 1,2,3,4,5,6,7 };
	vector<int> varr(arr, arr + 7);

	//����
	//--------------------��һ�ַ�ʽ���±����
	cout << "��һ�ֱ�����ʽ" << endl;
	for (int i = 0; i < varr.size(); i++)
		cout << varr[i] << " ";

	cout << endl;
	for (int i = 0; i < f.size(); i++)
		cout << f[i] << " ";
	//--------------------�ڶ��ַ�ʽ��������
	cout << endl;
	cout << "�ڶ��ֱ�����ʽ" << endl;
	for (vector<int>::iterator it = varr.begin(); it != varr.end(); it++) //vector<int>::iterator it Ϊ����Ԫ��λ�õ�����
		cout << *it << " ";

	cout << endl;
	for (vector<char>::iterator it = e.begin(); it != e.end(); it++)
		cout << *it << " ";
	//--------------------�����ַ�ʽ��auto�ؼ���
	cout << endl;
	cout << "�����ֱ�����ʽ" << endl;
	for (auto iter = varr.begin(); iter != varr.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	//--------------------�������ò���
	//-----------------------------a.assign()
	vector<int> g(8, 1);
	vector<int> h;
	cout << "h.assign:��g��0~2��Ԫ�ظ���h" << endl;
	h.assign(g.begin(), g.begin() + 3);
	for (auto iter = h.begin(); iter != h.end(); iter++)
		cout << *iter << " ";

	cout << endl << "h.assign:ֱ�Ӹ�ֵ" << endl;
	h.assign(4, 3);
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	//------------------------------a.back()��a.front()
	cout << "g.back():���һ��Ԫ��ֵ;x=g.back();��g�����һ��Ԫ�ظ���x" << endl;
	int x = g.back();
	cout << "x = " << x << endl;
	cout << "g.back() = " << g.back() << endl;
	//------------------------------a.clear()��a.empty()
	cout << "h.clear():���h������Ԫ��;  a.empty():�ж�a�Ƿ�Ϊ�գ����򷵻�1�����򷵻�0" << endl << "h.clear()ǰ��";
	for (int i = 0; i < h.size(); i++)
		cout << h[i] << " ";
	cout << endl << "h.clear()��";
	h.clear();
	if (h.empty()) cout << "empty" << endl;
	//------------------------------a.resize()
	cout << "h.resize(m):������Ԫ�ظ�������m��������ɾ����������������ֵ�����\nh.resize(m,n):������Ԫ�ص���m��������ɾ�����򲹣�ֵΪn"<<endl;
	h.resize(10, 7);
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	//------------------------------a.pop_back()��a.push_back()
	cout << "a.pop_back():ɾ�����һ��Ԫ��;\na.push_back():��������һ��Ԫ��;" << endl;
	cout << "a.pop_back()ǰ��h��Ԫ�أ�";
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "a.pop_back()��h��Ԫ�أ�";
	h.pop_back();
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "a.push_back()��h��Ԫ�أ�";
	h.push_back(6);
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	//------------------------------�����ıȽ�
	if (h == g) cout << "equal";
	else cout << "not equal";
	cout << endl;
	if (h >= g) cout << "h>=g";
	else cout << "h<g";
	cout << endl;
	return 0;
}
*/