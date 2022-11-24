#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;

typedef  struct List
{
    ElemType   *elem; //存储空间基址，体现动态性
    int   length;     //当前表的长度
    int   listsize;   //当前分配的存储容量
}SqList;

void InitList_Sq(SqList &L);
void Listinput(SqList &L);
void steMUl(SqList &Lc,SqList &La,SqList &Lb);
void print_List(SqList &L);

int main()
{
  SqList La,Lb,Lc;
  InitList_Sq(La);  //初始化3个线性表
  InitList_Sq(Lb);
  InitList_Sq(Lc);
  Listinput(La); //输入La的值
  Listinput(Lb);//输入Lb的值
  steMUl(Lc,La,Lb);//求出La和Lb的交集，放在Lc中
  print_List(Lc);//打印交集
  return 0;
}

void InitList_Sq(SqList &L)
{
	L.elem=new ElemType[MAXSIZE];
	if(!L.elem)
		exit(OVERFLOW);
	L.length=0;
	L.listsize=MAXSIZE;
}

void Listinput(SqList &L)
{
	int temp;
	int i=0;
	scanf("%d", &temp);
	while(temp>0)
	{
		L.elem[i]=temp;
		scanf("%d", &temp);
		i++;
	}
	L.length=i;
	L.elem[i]='\0';
}

void steMUl(SqList &Lc,SqList &La,SqList &Lb)
{
	int i,j,k=0;
	for(i=0;i<Lb.length;i++)
	{
		for(j=0;j<La.length;j++)
		{
			if(Lb.elem[i]==La.elem[j])
			{
				Lc.elem[k]=Lb.elem[i];
				k++;
			}
		}
	}
	Lc.elem[k]='\0';
	Lc.length=k;
}

void print_List(SqList &L)
{
	int i=0;
	for(i;i<L.length;i++)
	{
		if(i==0)
		{
			printf("%d", L.elem[i]);
		}
		else
		{
			printf(" %d", L.elem[i]);
		}
	}
	if(L.length==0)
	{
		printf("empty class");
	}
}
