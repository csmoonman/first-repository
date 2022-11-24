#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	int weight;//权重 
	int parent,lchild,rchild;;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

Status CreateHuffmanTree(HuffmanTree &HT,int n);//构造HuffmanTree
void Select(HuffmanTree HT,int n,int &s1,int &s2);
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n);//构造HuffmanTreeCode 
void printWeight(HuffmanTree HT,int n);
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	int i;
	
	printf("请输入不同元素的个数：");
	scanf("%d", &n);
	printf("测试点1\n");
	CreateHuffmanTree(HT,n);
	CreateHuffmanCode(HT,HC,n);
	
	printWeight(HT,2*n-1);

    for(i=1;i<=n;i++)
    	printf("编码是：%s\n",HC[i]);
	return 0;
}

Status CreateHuffmanTree(HuffmanTree &HT,int n)//构造HuffmanTree, 这个n是树叶结点的个数 
{
	//循环变量 
	int i;
	// 函数时void类型 ，返回空值
	//printf("测试点2\n");
	if(n<=1)
		return OK;
	//m是HuffmanTree结点总数
	int m=2*n-1;
	//分配内存，我这里第0号单元没存东西，申请n+1个单元
	//printf("测试点3\n");
	HT=new HTNode[m+1];
		if(!HT)
			return ERROR; 
	//初始化HuffmanTree的所有结点 
	//printf("测试点4\n");
	for(i=1;i<=m;i++)
	{
		HT[i].parent=0;
		HT[i].rchild=0;
		HT[i].lchild=0; 
	}
	//将叶节点赋值 
	//printf("测试点5\n");
	for(i=1;i<=n;i++)
	{
		printf("请输入第%d个元素的权重：",i);
		scanf("%d", &HT[i].weight); 
	}
	//逐步构造树结构 
	//printf("测试点6\n");
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		//从各个树中，包括新生成的，找出权重最小的两个数，并且其父值为0 
		//注意s1、s2为下标值 
		//printf("测试点7\n");
		Select(HT,i-1,s1,s2);
		//printf("测试点9\n");
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//printf("测试点10\n");
	return OK;
}
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
	printf("测试点8\n");
	int min1=10000,min2=10000;
	for(int i=1;i<=n;i++)
	{
		if(HT[i].parent==0&&HT[i].weight<min1)
		{
			s1=i;
			min1=HT[s1].weight;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(HT[i].parent==0&&HT[i].weight<min2&&i!=s1)
		{
			s2=i;
			min2=HT[s2].weight;
		}
	}
	printf("s1=%d,s2=%d\n",s1,s2);
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)//构造HuffmanTreeCode 
{ 
	HC=new char*[n+1];//第零号不用
	int start;
	int c,f;
	char cd[n] ;//临时存放每一个叶结点的HuffmanCode 
	cd[n-1]='\0'; 
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		f=HT[i].parent;
		//从叶结点开始一直到根结点 
		while(f!=0)//当不是根结点时 
		{
			start--; 
			if(HT[f].lchild==c)
				cd[start]='0';
			else 
				cd[start]='1';
			c=f;
			f=HT[f].parent;
		}
		HC[i]=new char[n-start];
		strcpy(HC[i],&cd[start]);//注意要从cd[start]开始传 
	}
}

void printWeight(HuffmanTree HT,int n)
{
	for(int i=1;i<=n;i++)
		printf("第%d个元素权重:%d\n", i, HT[i].weight);
}
