#include<stdio.h>
#define N 5
int main()
{
	char str[N];
	fgets(str,N,stdin);//ֻ��¼��N-1λ�ַ���ʣ��һ�����'\0'
	char str2[10];
	gets(str2); 
	puts(str);
	puts(str2);
	return 0;
}
