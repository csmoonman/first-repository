#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
/*
1、字符串的赋值用strcpy
2、计算len时应该用strlen，用sizeof得到的是数组空间大小 
*/
typedef struct string
{
	char ch[10];
	int len;
}string;

int Index_BF(string L,string K);

int main()
{
	string L;
	string K;
	strcpy(L.ch,"iloveyoubb");
	L.len=strlen(L.ch);
	
	scanf("%s",K.ch);
	K.len=strlen(K.ch);
	int i=Index_BF(L,K);
	if(i>=0)
		printf("%s\n", &L.ch[i]);
	else
		printf("未匹配\n"); 
	return 0;
}
int Index_BF(string L,string K)
{
	int i,j;
	i=0;
	j=0;
	while(i<L.len&&j<K.len)
	{
		if(L.ch[i]==K.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i=i-j+1;
			j=0;
		}
	}
	if(j>=K.len-1)	return i-K.len;
	else return -1;	
}
