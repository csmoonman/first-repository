#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
using namespace std;

int main()
{	
	ifstream in("stringstream.txt");
	string s;
	getline(in,s);
	istringstream sin(s);
	string str;
	sin>>str;
	cout<<str<<endl;
	
	return 0;
 } 
