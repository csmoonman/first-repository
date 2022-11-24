#include<stdio.h>

int main()
{
	char ch='A';
	printf("转换前：%c\n", ch);
	ch=32+ch;
	printf("转换后：%c\n", ch);
	return 0;
}
