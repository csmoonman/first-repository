#include"Linklist.h"
#include<iostream>
#include<string>
#pragma warning(disable:4996)
using namespace std;
int main()
{
	Linklist L;
	L.Add_Node_by_tail();
	L.Add_Node_by_tail();
	//L.Modify_Node();
	//L.Delete_Node();
	cout << L;
	//Print_message(L);
}