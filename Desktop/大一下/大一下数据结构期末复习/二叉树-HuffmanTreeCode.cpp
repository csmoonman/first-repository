#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct HuffmanNode
{
	char data;
	int weight;
	int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char** HuffmanTreeCode;

void createHuffmanTree(HuffmanTree &T,int n);
void select(HuffmanTree T,int n,int &s1,int &s2);
void printWeight(HuffmanTree T,int n);
void createHuffmanTreeCode(HuffmanTree T,HuffmanTreeCode &HC,int n);
void printHuffmanTreeCode(char *TreeElem,HuffmanTreeCode HC,int n);

int main()
{
	HuffmanTree T;
	HuffmanTreeCode HC;
	int n;
	printf("共有多少个结点？\n");
	scanf("%d", &n);
	getchar();

	createHuffmanTree(T,n);//
	
	createHuffmanTreeCode(T,HC,n);
	
	//打印权值 
	printWeight(T,n);

	for(int i=1;i<=n;i++)
	{
		printf("%c:", T[i].data);
		printf("%s\n", HC[i]);//HuffmanTreeCode 输出时要注意格式 
	}
	return 0;
}

void createHuffmanTree(HuffmanTree &T,int n)
{
	int m=2*n-1;
	int s1,s2;
	int i;
	
	T=(HuffmanTree)malloc(sizeof(HTNode)*(m+1));
	
	for(i=1;i<=n;i++)
	{
		printf("输入第%d个元素:\n" , i);
		scanf("%c" ,&T[i].data);
		getchar();
	}
	
	for(int i=1;i<=m;i++)
	{
		T[i].parent=0;
		T[i].lchild=0;
		T[i].rchild=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("请输入第%d个元素的权值：", i);
		scanf("%d",&T[i].weight);
		getchar();
	}
	for(int i=n+1;i<=m;i++)
	{
		select(T,i-1,s1,s2);
		T[s1].parent=i;
		T[s2].parent=i;
		T[i].lchild=s1;
		T[i].rchild=s2;
		T[i].weight=T[s1].weight+T[s2].weight;
	}
}

void select(HuffmanTree T,int n,int &s1,int &s2)
{
	int min1=32767,min2=32767;
	int i,j;
	for(i=1;i<=n;i++)
		if(T[i].weight<min1&&T[i].parent==0)
		{
			min1=T[i].weight;
			s1=i;
		}
	for(i=1;i<=n;i++)
		if(T[i].weight<min2&&s1!=i&&T[i].parent==0)
		{
			min2=T[i].weight;
			s2=i;
		}
}

void printWeight(HuffmanTree T,int n)
{
	for(int i=1;i<=2*n-1;i++)
		printf("第%d个：%d\n",i,T[i].weight);
}

void createHuffmanTreeCode(HuffmanTree T,HuffmanTreeCode &HC,int n)
{
	int start,c,f;
	HC=(char**)malloc(sizeof(char)*n);

	char temp[n];
	temp[n-1]='\0';
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		f=T[i].parent;
		
		while(f!=0)//不是根节点 
		{
			start--;
			if(T[f].lchild==c) temp[start]='0';
			else temp[start]='1';
			c=f;
			f=T[f].parent;
		}
		HC[i]=(char*)malloc(sizeof(char)*(n-start));
		strcpy(HC[i], &temp[start]);
	}
}

