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
	printf("���ж��ٸ���㣿\n");
	scanf("%d", &n);
	getchar();

	createHuffmanTree(T,n);//
	
	createHuffmanTreeCode(T,HC,n);
	
	//��ӡȨֵ 
	printWeight(T,n);

	for(int i=1;i<=n;i++)
	{
		printf("%c:", T[i].data);
		printf("%s\n", HC[i]);//HuffmanTreeCode ���ʱҪע���ʽ 
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
		printf("�����%d��Ԫ��:\n" , i);
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
		printf("�������%d��Ԫ�ص�Ȩֵ��", i);
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
		printf("��%d����%d\n",i,T[i].weight);
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
		
		while(f!=0)//���Ǹ��ڵ� 
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

