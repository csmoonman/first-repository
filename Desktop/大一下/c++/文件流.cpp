#include<iostream>

using namespace std;

int main()
{
	ifstream in("a.in");
	ofstream out("a.out");
	for(string str; getline(in, str);)
		out<<str<<endl;
}
