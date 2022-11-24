#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct StackQ
{
	char* base;
	char* top;
}StackQ;

void InitStackQ(StackQ &Sq);
void EnSq(StackQ &Sq,char e);
void DeSq(StackQ &Sq,char &e);
void Empty(StackQ Sq);

int main()
{
	StackQ Sq;
	InitStackQ(Sq);
	int len,n,i;
	char e;
	char ch[100];
	scanf("%s", ch);
	
	len=strlen(ch);
	
	ch[len]='\0';
	n=len/2;
	for(i=0;i<n;i++)
		EnSq(Sq,ch[i]);
		
	if(len%2==0)
	{
		while(ch[i]!='\0')
		{
			DeSq(Sq,e);
			if(ch[i]==e) i++;
			else break;
		}
	}
	else
	{
		i++;
		while(ch[i]!='\0')
		{
			DeSq(Sq,e);
			if(ch[i]==e) i++;
			else break;
		}
	}
	if(ch[i]!='\0') printf("NO");
	else printf("Yes");
	return 0;
} 

void InitStackQ(StackQ &Sq)
{
	Sq.base=(char*)malloc(sizeof(char)*100);
	Sq.top=Sq.base;
}

void EnSq(StackQ &Sq,char e)
{
	if(Sq.top-Sq.base==100) return;
	else
	{
		*Sq.top = e;
		Sq.top++;
	}
}
void DeSq(StackQ &Sq,char &e)
{
	if(Sq.base==Sq.top)
		return;
	e = *--Sq.top;
}
void Empty(StackQ Sq);
