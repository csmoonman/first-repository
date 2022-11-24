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
//先序创建 
void createTree(BiTree &T);//要传引用 
void BeOrder(BiTree T);//先序 
void InOrder(BiTree T);//中序
void LaOrder(BiTree T);//后序 
void copy(BiTree &NewT,BiTree T);//二叉树的复制
int count1(BiTree T);//统计度为一的结点 
int Depth(BiTree T);

int main()
{
	int n=1;
	while(n)
	{
		printf("What do you want to do?\n");
		printf("1-先序建立一个二叉树\n");
		printf("2-打印这个二叉树\n");
		printf("3-计算度为一的结点个数\n");
		printf("4-计算树的长度\n");
		printf("0-退出\n");
		scanf("%d", &n);
		if(n==1)
		{
			printf("请输入：");
			createTree(mytree);
			printf("已建立，该树名称为：mytree\n");
		}
		if(n==2)
		{
			system("cls");
			int x=1;
			while(x)
			{
				printf("1-先序打印这个二叉树\n");
				printf("2-中序打印这个二叉树\n");
				printf("3-后序打印这个二叉树\n");
				printf("0-返回上层菜单\n");
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
			printf("度为1的结点个数为：%d\n", count1(mytree));
		}
		if(n==4)
		{
			printf("树的长度为：%d\n", Depth(mytree));
		}
		if(n==0)
			return 0;
	} 
	return 0;
}

void createTree(BiTree &T)//要传引用 
{
	char ch;
	cin>>ch;
	if(ch!='#')
	{
		T=new BiTNode;//一定要申请空间 
		T->data=ch;
		createTree(T->lchild);
		createTree(T->rchild);
	}
	else
		T=NULL;
}

void BeOrder(BiTree T)//先序 
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

void LaOrder(BiTree T)//后序 
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

void copy(BiTree &NewT,BiTree T)//二叉树的复制
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
