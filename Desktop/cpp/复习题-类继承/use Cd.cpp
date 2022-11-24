/*
#include"Cd.h"
#include<iostream>

void Bravo(const Cd& disk);

int main()
{
	using namespace std;
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "using objct directlt:\n";
	c1.Report();
	c2.Report();

	cout << "using type cd* pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

}
*/