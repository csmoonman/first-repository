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

	//遍历
	//--------------------第一种方式：下标访问
	cout << "第一种遍历方式" << endl;
	for (int i = 0; i < varr.size(); i++)
		cout << varr[i] << " ";

	cout << endl;
	for (int i = 0; i < f.size(); i++)
		cout << f[i] << " ";
	//--------------------第二种方式：迭代器
	cout << endl;
	cout << "第二种遍历方式" << endl;
	for (vector<int>::iterator it = varr.begin(); it != varr.end(); it++) //vector<int>::iterator it 为向量元素位置的类型
		cout << *it << " ";

	cout << endl;
	for (vector<char>::iterator it = e.begin(); it != e.end(); it++)
		cout << *it << " ";
	//--------------------第三种方式：auto关键字
	cout << endl;
	cout << "第三种遍历方式" << endl;
	for (auto iter = varr.begin(); iter != varr.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	//--------------------其他常用操作
	//-----------------------------a.assign()
	vector<int> g(8, 1);
	vector<int> h;
	cout << "h.assign:将g中0~2个元素赋给h" << endl;
	h.assign(g.begin(), g.begin() + 3);
	for (auto iter = h.begin(); iter != h.end(); iter++)
		cout << *iter << " ";

	cout << endl << "h.assign:直接赋值" << endl;
	h.assign(4, 3);
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	//------------------------------a.back()、a.front()
	cout << "g.back():最后一个元素值;x=g.back();将g的最后一个元素赋给x" << endl;
	int x = g.back();
	cout << "x = " << x << endl;
	cout << "g.back() = " << g.back() << endl;
	//------------------------------a.clear()、a.empty()
	cout << "h.clear():清除h中所有元素;  a.empty():判断a是否为空，空则返回1，否则返回0" << endl << "h.clear()前：";
	for (int i = 0; i < h.size(); i++)
		cout << h[i] << " ";
	cout << endl << "h.clear()后：";
	h.clear();
	if (h.empty()) cout << "empty" << endl;
	//------------------------------a.resize()
	cout << "h.resize(m):将向量元素个数调至m个，多则删除，少则增补，其值随机；\nh.resize(m,n):将向量元素调至m个，多则删，少则补，值为n"<<endl;
	h.resize(10, 7);
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	//------------------------------a.pop_back()、a.push_back()
	cout << "a.pop_back():删除最后一个元素;\na.push_back():在最后加入一个元素;" << endl;
	cout << "a.pop_back()前，h中元素：";
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "a.pop_back()后，h中元素：";
	h.pop_back();
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout << "a.push_back()后，h中元素：";
	h.push_back(6);
	for (vector<int>::iterator it = h.begin(); it != h.end(); it++)
		cout << *it << " ";
	cout << endl;
	//------------------------------向量的比较
	if (h == g) cout << "equal";
	else cout << "not equal";
	cout << endl;
	if (h >= g) cout << "h>=g";
	else cout << "h<g";
	cout << endl;
	return 0;
}
*/