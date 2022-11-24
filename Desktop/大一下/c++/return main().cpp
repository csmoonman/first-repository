#include<iostream>

void returnv(void);

int main()
{
	int *i=(new int);
	std::cout<<i<<std::endl;
	delete i;
	return main();
}


