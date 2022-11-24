#include<stdio.h>
#include<iostream>
#include<windows.h>
using namespace std;

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;


BiTree mytree;
//���򴴽� 
void createTree(BiTree &T);//Ҫ������ 
void BeOrder(BiTree T);//���� 
void InOrder(BiTree T);//����
void LaOrder(BiTree T);//���� 
void copy(BiTree &NewT,BiTree T);//�������ĸ���
int count1(BiTree T);//ͳ�ƶ�Ϊһ�Ľ�� 
int Depth(BiTree T);

int main()
{
	int n=1;
	while(n)
	{
		printf("What do you want to do?\n");
		printf("1-������һ��������\n");
		printf("2-��ӡ���������\n");
		printf("3-�����Ϊһ�Ľ�����\n");
		printf("4-�������ĳ���\n");
		printf("0-�˳�\n");
		scanf("%d", &n);
		if(n==1)
		{
			printf("�����룺");
			createTree(mytree);
			printf("�ѽ�������������Ϊ��mytree\n");
		}
		if(n==2)
		{
			system("cls");
			int x=1;
			while(x)
			{
				printf("1-�����ӡ���������\n");
				printf("2-�����ӡ���������\n");
				printf("3-�����ӡ���������\n");
				printf("0-�����ϲ�˵�\n");
				scanf("%d", &x);
				if(n==1)
				{
					BeOrder(mytree);
					printf("\n");
					Sleep(1000);
				} 
				if(n==2)
				{
					InOrder(mytree);
					printf("\n");
					Sleep(1000);
				}
				if(n==3)
				{
					LaOrder(mytree);
					printf("\n");
					Sleep(1000);
				}
			} 
		} 
		if(n==3)
		{
			printf("��Ϊ1�Ľ�����Ϊ��%d\n", count1(mytree));
		}
		if(n==4)
		{
			printf("���ĳ���Ϊ��%d\n", Depth(mytree));
		}
		if(n==0)
			return 0;
	} 
	return 0;
}

void createTree(BiTree &T)//Ҫ������ 
{
	char ch;
	cin>>ch;
	if(ch!='#')
	{
		T=new BiTNode;//һ��Ҫ����ռ� 
		T->data=ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
	else
		T=NULL;
}

void BeOrder(BiTree T)//���� 
{
	if(T==NULL)
		return;
	else
	{
		cout<<T->data;
		BeOrder(T->lchild);
		BeOrder(T->rchild);
	}
} 

void InOrder(BiTree T)
{
	if(T==NULL)
		return;
	else
	{
		InOrder(T->lchild);
		cout<<T->data;
		InOrder(T->rchild);
	}
}

void LaOrder(BiTree T)//���� 
{
	if(T==NULL)
		return;
	else
	{
		LaOrder(T->lchild);
		LaOrder(T->rchild);
		cout<<T->data;
	}
} 

void copy(BiTree &NewT,BiTree T)//�������ĸ���
{
	//NewT=new BiTree;
	if(T)
		NewT=NULL;
	else
	{
		NewT->data=T->data;
		copy(NewT->lchild,T->lchild);
		copy(NewT->rchild,T->rchild);
	}
}

int count1(BiTree T)
{
	if(T==NULL)
		return 0;
	if(T->lchild==NULL&&T->rchild!=NULL)
		return count1(T->rchild)+1;
	if(T->lchild!=NULL&&T->rchild==NULL)
		return count1(T->lchild)+1;

	return count1(T->lchild)+ count1(T->rchild);
}

int Depth(BiTree T)
{
	int m,n;
	if(T==NULL)
		return 0;
	else
	{
		m=Depth(T->lchild);
		n=Depth(T->rchild);
		if(m>n)
			return m+1;
		else 
			return n+1;
	}
}
