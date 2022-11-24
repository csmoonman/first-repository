#include<stdio.h>
#include<string.h>

typedef struct
{
	char ch[20];
	int length;
}SString;

int BF(SString S,SString T,int &index)
{
	int i=0,j=0;
	while(i<S.length&&j<T.length)
	{
		if(S.ch[i]==T.ch[j])
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
	if(j>=T.length)
		index=i-T.length;
	else index=-1;	
	return 0;
}

void Input(SString &S)
{
	scanf("%s",S.ch);
	getchar();
	S.length=strlen(S.ch);
}

int main()
{
	SString S,T;
	printf("输入母串：\n");
	Input(S);
	printf("输入字串:\n");
	Input(T);
	
	int index;
	BF(S,T,index);
	if(index>=0)
		printf("在母串中首下表为%d\n", index);
	else 
		printf("未匹配！\n");
	return 0;
}
