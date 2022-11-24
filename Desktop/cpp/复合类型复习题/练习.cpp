/*
#include<iostream>
#include<array>
#include<string>
#include<vector>

using namespace std;

struct fishes
{
	char kind[30];
	int weight;
	double length;
};

int main()
{
	array<char, 30> actor = { '1' };
	array<short, 100> betsie = {};
	array<float, 13> chuck={};
	array<long double, 64> dipsea={};
	array<int, 5> odd = { 1,3,5,7,9 };

	int even = odd.at(1) + odd.at(4);
	cout << chuck.at(2)<<endl;

	char c_str[20] = "cheeseburger";
	string str = "Waldorf Salad";

	fishes liyu = { "liyu",13,3.1 };

	enum Response  { Yes=1,No=0,Maybe=2 };

	double ted=3.1415;
	double* pted = &ted;
	cout << "ted = " << *pted << endl;

	float treacle[10]={};
	float* ptreacle = treacle;
	cout << "The first:" << *ptreacle << " ,The last:" << *(ptreacle + 9) << endl;

	int n;
	cout << "数组多大？  ";
	cin >> n;
	int* p13 = new int[n];
	vector<int> v1(n);
	delete[] p13;

	cout << (int*)"Home of the jolly bytes" << endl;

	fishes *pfish2 = new struct fishes;
	*pfish2 = {"BigDick",3,13.11};
	cout << "fish2: " << (*pfish2).kind << " " << pfish2->length << " " << pfish2->weight << endl;
	delete pfish2;

	const int n3 = 10;
	vector<string> v2(const int n2 = 10);
	array<string, n3>;
}
*/