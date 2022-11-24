#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct HNode
{
	int wight;
	int parent,lchild,rchild;
}HNode,*HuffmanTree;

typedef char **HuffmanCode;

void createHTree(HuffmanTree &T,int n);
void select(HuffmanTree T,int n,int &s1,int &s2);
void Huffman_Code(HuffmanTree HT,HuffmanCode &HC, int n);

int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int i;
	int n;
	scanf("%d", &n);
	getchar();
	createHTree(HT,n);
	
	for(i=1;i<=n*2-1;i++)
    printf("树是：%d\n",HT[i].wight);
    
	Huffman_Code(HT,HC,n);
  
    for(i=1;i<=n;i++)
    	printf("编码是：%s\n",HC[i]);

    return 0;
}

void createHTree(HuffmanTree &T,int n)//是从无到有建立一个树 ，main里只需要声明一下 
{
	int m=2*n-1;
	int i;
	int s1,s2;
	T=(HuffmanTree)malloc(sizeof(HNode)*(m+1));
	//初始化 
	
	for(i=1;i<=n;i++)
	{
		scanf("%d", &T[i].wight);
		getchar();
	}
	for(i=1;i<=m;i++)
	{
		T[i].parent=0;
		T[i].lchild=0;
		T[i].rchild=0;
	}
	//新建 
	for(i=n+1;i<=m;i++)
	{
		select(T,i-1,s1,s2);
		T[s1].parent=i;
		T[s2].parent=i;
		T[i].lchild=s1;
		T[i].rchild=s2;
		T[i].wight=T[s1].wight+T[s2].wight;
	}
}

void select(HuffmanTree T,int n,int &s1,int &s2)
{
	int i;
	int min=10000;//随机的、尽可能的大的值 
	for(i=1;i<=n;i++)
	{
		if(T[i].parent==0&&T[i].wight<min)
			{
				min=T[i].wight;
				s1=i;	
			}
	}
	min=10000;
	for(i=1;i<=n;i++)
	{
		if(T[i].parent==0&&i!=s1&&T[i].wight<min)
		{
			min=T[i].wight;
			s2=i;
		}
	}
}

void Huffman_Code(HuffmanTree HT,HuffmanCode &HC, int n)
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
		strcpy(HC[i],&cd[start]);
	}
}
