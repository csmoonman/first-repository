#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct
{
	int weight;//Ȩ�� 
	int parent,lchild,rchild;;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

Status CreateHuffmanTree(HuffmanTree &HT,int n);//����HuffmanTree
void Select(HuffmanTree HT,int n,int &s1,int &s2);
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n);//����HuffmanTreeCode 
void printWeight(HuffmanTree HT,int n);
int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int n;
	int i;
	
	printf("�����벻ͬԪ�صĸ�����");
	scanf("%d", &n);
	printf("���Ե�1\n");
	CreateHuffmanTree(HT,n);
	CreateHuffmanCode(HT,HC,n);
	
	printWeight(HT,2*n-1);

    for(i=1;i<=n;i++)
    	printf("�����ǣ�%s\n",HC[i]);
	return 0;
}

Status CreateHuffmanTree(HuffmanTree &HT,int n)//����HuffmanTree, ���n����Ҷ���ĸ��� 
{
	//ѭ������ 
	int i;
	// ����ʱvoid���� �����ؿ�ֵ
	//printf("���Ե�2\n");
	if(n<=1)
		return OK;
	//m��HuffmanTree�������
	int m=2*n-1;
	//�����ڴ棬�������0�ŵ�Ԫû�涫��������n+1����Ԫ
	//printf("���Ե�3\n");
	HT=new HTNode[m+1];
		if(!HT)
			return ERROR; 
	//��ʼ��HuffmanTree�����н�� 
	//printf("���Ե�4\n");
	for(i=1;i<=m;i++)
	{
		HT[i].parent=0;
		HT[i].rchild=0;
		HT[i].lchild=0; 
	}
	//��Ҷ�ڵ㸳ֵ 
	//printf("���Ե�5\n");
	for(i=1;i<=n;i++)
	{
		printf("�������%d��Ԫ�ص�Ȩ�أ�",i);
		scanf("%d", &HT[i].weight); 
	}
	//�𲽹������ṹ 
	//printf("���Ե�6\n");
	for(i=n+1;i<=m;i++)
	{
		int s1,s2;
		//�Ӹ������У����������ɵģ��ҳ�Ȩ����С���������������丸ֵΪ0 
		//ע��s1��s2Ϊ�±�ֵ 
		//printf("���Ե�7\n");
		Select(HT,i-1,s1,s2);
		//printf("���Ե�9\n");
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[s1].parent=i;
		HT[s2].parent=i;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
	}
	//printf("���Ե�10\n");
	return OK;
}
void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
	printf("���Ե�8\n");
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

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)//����HuffmanTreeCode 
{ 
	HC=new char*[n+1];//����Ų���
	int start;
	int c,f;
	char cd[n] ;//��ʱ���ÿһ��Ҷ����HuffmanCode 
	cd[n-1]='\0'; 
	for(int i=1;i<=n;i++)
	{
		start=n-1;
		c=i;
		f=HT[i].parent;
		//��Ҷ��㿪ʼһֱ������� 
		while(f!=0)//�����Ǹ����ʱ 
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
		strcpy(HC[i],&cd[start]);//ע��Ҫ��cd[start]��ʼ�� 
	}
}

void printWeight(HuffmanTree HT,int n)
{
	for(int i=1;i<=n;i++)
		printf("��%d��Ԫ��Ȩ��:%d\n", i, HT[i].weight);
}
