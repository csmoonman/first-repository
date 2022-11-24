#include<stdio.h>
int main()
{
	//%zd是c99中的用法，表size_t
	printf("int  %zd\n", sizeof(int));
	printf("short int  %zd\n", sizeof(short int));
	printf("long int  %zd\n", sizeof(long int));
	printf("long long int  %zd\n", sizeof(long long));
	printf("char  %zd\n", sizeof(char));
	printf("float  %zd\n", sizeof(float));
	printf("double  %zd\n", sizeof(double));
	printf("long double  %zd\n", sizeof(long double));

	return 0;
}