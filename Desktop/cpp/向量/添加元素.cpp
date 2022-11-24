/*
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main()
{
	
	ifstream in("Adding Elements.txt");
	vector<int> s;
	for (int a; in >> a;)
		s.push_back(a);
	int pair = 0;
	for (int i = 0; i < s.size(); i++)
		for (int j = i + 1; j < s.size(); j++)
			if (s[i] == s[j]) pair++;
	cout << pair << endl;
	
	//--------------¼üÈëÔªËØ
	vector<int> s;
	for (int a = 0; a != -1; )
	{
		cin >> a;
		s.push_back(a);
		if (a == -1) s.pop_back();
	}
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << " ";
		
	return 0;
}
*/