#include"Cd.h"
#include<iostream>
#pragma warning(disable:4996)

using namespace std;
Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	performers = new char[strlen(s1)+1];
	label = new char[strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char[5];
	label = new char[5];
	strcpy(performers, "NULL");
	strcpy(label, "NULL");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd() 
{
	delete[] performers;
	delete[] label;
}

void Cd::Report() const
{
	cout << "this Cd->Report\n";
}

Cd& Cd::operator=(const Cd& d)
{
	if (&d == this)
		return *this;

	delete[] performers;
	delete[] label;
	performers = new char[strlen(d.performers) + 1];
	label = new char[strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;

	return *this;
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x):Cd(s1,s2,n,x)
{
	mainp = new char[strlen(s3) + 1];

	strcpy(mainp, s3);
}

Classic::Classic(const Classic& c): Cd(c)
{
	mainp = new char[strlen(c.mainp) + 1];

	strcpy(mainp, c.mainp);
}

Classic::Classic() :Cd()
{
	mainp = new char[5];
	strcpy(mainp, "NULL");
}

Classic::~Classic() 
{
	delete[] mainp;
}

void Classic::Report() const
{
	cout << "this Classic->Report\n";
}

Classic& Classic::operator=(const Classic& c)
{
	if (&c == this)
		return *this;
	Cd::operator=(c);
	delete[] mainp;
	mainp = new char[strlen(c.mainp) + 1];
	strcpy(mainp, c.mainp);

	return *this;
}