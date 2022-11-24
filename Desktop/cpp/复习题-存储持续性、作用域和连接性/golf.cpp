#include"golf.h"
#include<iostream>
#pragma warning (disable:4996)
void setgolf(golf& g, const char* name, int hc)
{
	strncpy(g.fullname, name, len);
	g.handicap = hc;
}

void setgolf(golf& g)
{
	std::cout << "please enter the name : ";
	std::cin.get(g.fullname, len);
	std::cin.get();
	std::cout << "please enter the hc : ";
	(std::cin >> g.handicap).get();
}

void handicap(golf& g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf& g)
{
	std::cout << g.fullname << " " << g.handicap << std::endl;
}
