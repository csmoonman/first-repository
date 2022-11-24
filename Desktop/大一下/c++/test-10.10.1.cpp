#include<iostream>

struct box
{
	mutable int x;
 } ;
 
 int main()
 {
 	const struct box x = {3};
 	x.x=1;
 	std::cout<<x.x;
 }
