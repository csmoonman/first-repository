#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char** HuffmanCode;
typedef struct HuffmanNode
{
	char data;
	int parent;
	int lchild,rchild;
	int weight;
}HuffmanNode,*HuffmanTree;

void select(HuffmanTree T,int n,int &s1,int &s2)
{
	int i;
	int min1=32767,min2=32767;
	printf("%d\n",n);
	for(i=1;i<=n;i++)
	{
		if(T[i].parent==0&&T[i].weight<min1)
		{
			min1=T[i].weight;
			s1=i;
		}
	}
	
	for(i=1;i<=n;i++)
	{
		if(s1!=i&&T[i].parent==0&&T[i].weight<min2)
		{
			min2=T[i].weight;
			s2=i;
		}
	}
	
}

void createHuffmanTree(HuffmanTree &T,int n)
{
	int m=2*n-1;
	T=(HuffmanTree)malloc(sizeof(HuffmanNode)*(m+1));
	int i;
	for(i=1;i<=n;i++)
	{
		printf("请输入第%d个元素\n",i);
		scanf("%c",&T[i].data);
		getchar();
		printf("请输入第%d个元素的权重\n",i);
		scanf("%d",&T[i].weight);
		
		getchar();
	}
	//初始化 
	for(i=1;i<=m;i++)
	{
		T[i].lchild=0;
		T[i].rchild=0;
		T[i].parent=0;
	}
	
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		
		select(T,i-1,s1,s2);
		T[s1].parent=i;
		T[s2].parent=i;
		
		T[i].lchild=s1;
		T[i].rchild=s2;
		
		T[i].weight=T[s1].weight+T[s2].weight;
	}
}


void createHuffmanCode(HuffmanTree T,HuffmanCode &HC,int n)
{
	int c,f,start,i;
	char temp[n];
	
	
	//HC=new char*[n+1];
	HC=(char**)malloc(sizeof(char*)*(n+1));
	
	temp[n-1]='\0';
	for(i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		f=T[i].parent;
		while(f!=0)
		{
			start--;
			if(T[f].lchild==c) temp[start]='0';
			else temp[start]='1';
			c=f;
			f=T[c].parent;
		}
		
		HC[i]=new char[n-start];
		strcpy(HC[i],&temp[start]);
	}
	
}

int main()
{
	HuffmanTree T;
	HuffmanCode HC;
	int n,i;
	printf("有多少个元素？");
	scanf("%d",&n);
	getchar();
	createHuffmanTree(T,n);
	createHuffmanCode(T,HC,n);
	
	for(i=1;i<=n;i++)
	{
		printf("%c:",T[i].data);
		printf("%s\n",HC[i]);
	}
	return 0;
}
