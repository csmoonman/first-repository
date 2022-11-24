#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0

typedef char **HuffmanTreeCode;
typedef struct HuffmanTreeNode
{
	char data;
	int weight;
	int lchild,rchild,parent;
}HuffmanTreeNode,*HuffmanTree;

char key[1000];

//对哈夫曼树的初始化 
void InitHuffmanTree(HuffmanTree &T);
void CntWeight(HuffmanTree &T);
void select(HuffmanTree T,int n,int &s1,int &s2);
void InitHuffmanCode(HuffmanTreeCode &HC);
//哈夫曼编码
void HuffmanCode(HuffmanTree T,HuffmanTreeCode &HC);
//打印
void printCode(HuffmanTree T,HuffmanTreeCode HC);
 
int main()
{
	HuffmanTree T;
	HuffmanTreeCode HC;
	
	InitHuffmanTree(T);
	InitHuffmanCode(HC);
	
	HuffmanCode(T,HC); 

	printCode(T,HC);
	return 0;
}

void InitHuffmanCode(HuffmanTreeCode &HC)
{
	HC=(char**)malloc(sizeof(char)*58);
}

void InitHuffmanTree(HuffmanTree &T)
{
	T=(HuffmanTree)malloc(sizeof(HuffmanTreeNode)*121);//一串字符可能出现的不同字符为52种
	
	char ch;
	int i;
	int s1,s2;
	for(i=1;i<=120;i++)
	{
		T[i].data='#';
		T[i].weight=0;
		T[i].parent=0;
		T[i].lchild=0;
		T[i].rchild=0;
	}
	
	printf("请输入一则报文,以回车键结束:"); 
	
	char temp[1000];
	
	scanf("%s",temp);
	
	//////
	int len=strlen(temp);
	
	i=0;
	int index;
	for(i;i<len;i++)
	{
		index=int(temp[i]);
		index=index-64;
		
		if(T[index].data=='#')
		{
			T[index].data=temp[i];
			T[index].weight=1;
			T[120].weight++;//第60位置存放不同元素个数 
		}
		else
			T[index].weight++;
	}
	///// 
	 
	int n=T[120].weight;
	for(i=59;(i-58)<=(n-1);i++)
	{
		select(T,i-1,s1,s2);
		T[s1].parent=i;
		T[s2].parent=i;
		T[i].data='1';
		T[i].lchild=s1;
		T[i].rchild=s2;
		T[i].weight=T[s1].weight+T[s2].weight; 
		printf("s1:%d s2:%d\n",s1,s2);
	}
}

void CntWeight(HuffmanTree &T)
{
	int len=strlen(key);

	int i=1,index;
	for(i;i<=len;i++)
	{
		index=key[i]-'0';
		index=index-64;
		printf("%d ",index);
		if(T[index].data=='#')
		{
			T[index].data=key[i];
			T[index].weight=1;
			T[120].weight++;//第60位置存放不同元素个数 
		}
		else
			T[index].weight++;
	}
}

void select(HuffmanTree T,int n,int &s1,int &s2)
{
	int min1=32767,min2=32767;
	int i,j;
	for(i=1;i<=n;i++)
		if(T[i].data!='#'&&T[i].weight<min1&&T[i].parent==0)
		{
			min1=T[i].weight;
			s1=i;
		}
		
	for(i=1;i<=n;i++)
		if(T[i].weight!='#'&&T[i].weight<min2&&s1!=i&&T[i].parent==0)
		{
			min2=T[i].weight;
			s2=i;
		}
}

void HuffmanCode(HuffmanTree T,HuffmanTreeCode &HC)
{
	int c,f,start;
	int i;
	int n=T[120].weight;
	char temp[n];
	temp[n-1]='\0';
	for(i=1;i<=58;i++)
	{
		if(T[i].data!='#')
		{
			start=n-1;
			c=i;
			f=T[i].parent;
			while(f!=0)
			{
				start--;
				if(T[f].lchild==c)	temp[start]='0';
				else temp[start]='1';
				c=f;
				f=T[f].parent;
			}
			
			HC[i]=(char*)malloc(sizeof(char)*(n-start));
			strcpy(HC[i],&temp[start]);
			printf("%s\n",HC[i]);
		}
	}
}

void printCode(HuffmanTree T,HuffmanTreeCode HC)
{
	int i=1;
	for(i;i<=120;i++)
	{
		printf("%c:%d",T[i].data,T[i].weight);
		if(T[i].data!='#'&&T[i].data!='1')
		{
			printf("%c:%s\n",T[i].data,HC[i]);
		}
	}
}
