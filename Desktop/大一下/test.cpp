#include<stdio.h>
#define N 5
int main()
{
	char str[N];
	fgets(str,N,stdin);//只会录入N-1位字符，剩下一个存放'\0'
	char str2[10];
	gets(str2); 
	puts(str);
	puts(str2);
	return 0;
}
