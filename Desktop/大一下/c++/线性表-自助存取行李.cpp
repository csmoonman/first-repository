#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define ERROR 0
#define OK 1

//采用链表的存储结构
typedef struct LuggageNode 
{
	int num;//行李编号
	char Flight[12];//行李航班 
	char name[10];//姓名 
	char ID[18];//游客身份证 
	char status[15];//行李状态值1代表已取，0代表未取 -1代表未到达 
	LuggageNode* next; 
}LNode,*LNodePtr; 

typedef struct LuggageList
{
	LNodePtr head;
	LNodePtr rear;
}Llist;

typedef int Status;

//对链表的操作 
Status  iniList(Llist &L);
void printList(Llist L);//打印表 

//功能层 
Status deposit(Llist &L,int &num);//存入行李 ，也即存入游客信息 
Status takeOut(Llist L,char ID[18]);//取出行李 

int main()
{
	Llist L;
	int cnt=1;
	int n;
	char ID[18];
	iniList(L);
	while(1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t***欢迎使用自助存取行李系统！***\n");
		printf("\t\t\t***--------------------------***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***       1---存入行李       ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***       2---取出行李       ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***   3---打印目前行李状态   ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***       0---退出系统       ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t        请输入对应序号：       \n");
		scanf("%d", &n);
		printf("\t\t\t正在处理...\n");
		Sleep(500);
		system("cls");
		switch(n)
		{
			case 1:
				deposit(L,cnt);
				break;
			case 2:
				printf("\n\n\n\n");
				printf("\t\t\t请输入您的身份证号码：");
				scanf("%s", ID);
				takeOut(L,ID);
				break;
			case 3:
				printList(L);
				break;
			case 0:
				return OK;
			default:
				printf("\n\n\n\n");
				printf("\t\t\t输入错误！"); 
				system("pause"); 
				break;
		}
	}
	return 0;
} 

//对链表的操作 
Status  iniList(Llist &L)
{
	/*头结点未存储信息*/
	L.head=(LNodePtr)malloc(sizeof(LNode));
	//未成功返回ERROR 
	if(!L.head)
		return ERROR;
	L.head->next=NULL;
	L.rear=L.head;
	
	return OK;//初始完成 
}

void printList(Llist L)//打印表 
{
	system("cls");
	if(L.head->next==NULL)
	{
		printf("\n\n\n\n");
		printf("\t\t\t尚未有行李托运！\n");
		system("pause");
		return;
	}
	LNodePtr p=L.head->next;
	printf("\n\n\n\n");
	printf("\t\t\t行李编号  行李航班  姓名      身份证号      行李状态"); 
	while(p)
	{
		printf("\n");
		printf("\t\t\t%.3d      %s   %s %s    %s\n", p->num, p->Flight, p->name, p->ID, p->status);
		p=p->next;
	}
	system("pause");
}

//功能层 
Status deposit(Llist &L,int &num)//存入行李 
{
	LNodePtr p=(LNodePtr)malloc(sizeof(LNode));
	p->next=NULL; 
	p->num=num;
	num++;
	strcpy(p->status,"Unarrival");
	printf("\n\n\n\n");
	printf("\t\t\t请输入您的航班班次：");
	printf("\n"); 
	printf("\t\t\t");
	scanf("%s" ,p->Flight);
	printf("\t\t\t请输入您的姓名：");
	printf("\n");
	printf("\t\t\t");
	scanf("%s", p->name);
	printf("\t\t\t请输入您的身份证：");
	printf("\n");
	printf("\t\t\t");
	scanf("%s", p->ID);	
	printf("\t\t\t已安排托运！\n");
	system("pause");
	L.rear->next=p;
	L.rear=p;
	L.rear->next=NULL;
	
	return OK;
}

Status takeOut(Llist L,char ID[18])//取出行李 
{
	LNodePtr p;

	p=L.head->next;
	char ch;
	char t;
	//表空 
	if(L.head==L.rear)
	{
		printf("\t\t\t尚未有行李托运!\n");
		system("pause");
		return ERROR;
	}
	//遍历查询 
	while(p)
	{
		if(strcmp(ID,p->ID)==0)
		{
			strcpy(p->status,"NotTakenOut");//已到达，标记为未取 
			printf("\n\n\n\n");
			printf("\t\t\t行李编号:%.3d\n\t\t\t行李航班：%s\n\t\t\t姓名：%s\n\t\t\t身份证号码：%s\n\t\t\t行李状态：%s\n", p->num, p->Flight, p->name, p->ID, p->status);
			system("pause");
			break;
		}
		else
			p=p->next;
	}
	
	if(L.rear->next==p)
	{
		printf("\n\n\n\n");
		printf("未查询到您的行李信息！\n");
		system("pause");
		return ERROR;
	}

	printf("\t\t\t是否取出？Y/N:");
	while ((t = getchar()) != '\n' && t != EOF);//清除缓存！！！很重要 
	scanf("%c",&ch);

	system("pause");
	printf("\n");
	if(ch=='Y'||ch=='y')
	{
		strcpy(p->status,"TakenOut");//标记为已取出 
		printf("\t\t\t已取出！\n");
		printf("\t\t\t行李编号:%.3d\n\t\t\t行李航班：%s\n\t\t\t姓名：%s\n\t\t\t身份证号码：%s\n\t\t\t行李状态：%s\n", p->num, p->Flight, p->name, p->ID, p->status);
		system("pause");	
	}
	return OK;
}

