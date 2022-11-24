#include<string.h>
#include<stdio.h>
#include<malloc.h>
#define MAXSIZE 30
#define  TRUE   1
#define  FALSE  0
#define  OK     1
#define  ERROR 0
#define  OVERFLOW  -1
typedef int Status;
typedef  struct   {
          char name[20];
          char symptom[20];
}ElemType;
typedef struct LNode  /* 定义链式存储结构 */
{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

Status Creat_LinkList(LinkList &head)               /* 创建链表，预存4个密接者信息 */
{
     LinkList r,s;
     head=(LinkList)malloc(sizeof(LNode));
     head->next=NULL;
     r=head;
     s=(LNode *)malloc(sizeof(LNode));
     strcpy(s->data.name,"陈晨");
     strcpy(s->data.symptom,"无症状");
     r->next=s;
     r=s;
     s=(LNode *)malloc(sizeof(LNode));
     strcpy(s->data.name,"李俐");
     strcpy(s->data.symptom,"轻微咳嗽");
     r->next=s;
     r=s;
     s=(LNode *)malloc(sizeof(LNode));
     strcpy(s->data.name,"李林");
     strcpy(s->data.symptom,"无症状");
     r->next=s;
     r=s;
     s=(LNode *)malloc(sizeof(LNode));
     strcpy(s->data.name,"张伟");
     strcpy(s->data.symptom,"乏力");
     r->next=s;
     r=s;
     r->next=NULL;
     return OK;
}/* Creat_LinkList */
void Print_LinkList( LinkList H)     /* 输出链式表 */
{
    LinkList p;
    p=H->next;
    while(p!=NULL)
    {
        printf("接触者：%s,症状为：%s\n",p->data.name,p->data.symptom);
        p=p->next;
   }
  }/* Print_LinkList */
  
LinkList  locate_LinkList(LinkList H, char key[])
{
	LinkList p=H->next;
	int cnt=0;
	while(p)
	{
		cnt++;
		if(strcmp(p->data.name,key)==0)
			break;
		
		p=p->next;
	}
	if(p==NULL)
		return NULL;  //未找到 
	else
		return p;  //找到 
    /* 请在这里填写答案 */
}/*Get_LinkList*/
Status ListInsert(LinkList &H,int i,ElemType e)
{
	LinkList p=(LinkList)malloc(sizeof(LNode));
	LinkList tail=H;
	int cnt=0;//计数
	p->next=NULL;
	p->data=e;
	
	while(cnt<i-1)
	{
		tail=tail->next;
		cnt++;
	}
    if(tail!=NULL)
    {
        p->next=tail->next;
	    tail->next=p;
    }
 /* 请在这里填写答案 */
}

int  main()
  {
    char  kname[20];
    ElemType person;
    int location;
    LinkList L,loc;
    Creat_LinkList(L);  //创建单链表
  scanf("%s",person.name); //输入新增密接者的新名
    scanf("%s",person.symptom);//输入新增密接者的症状
    scanf("%d",&location);//输入插入位置
    ListInsert(L,location,person);//执行插入
    Print_LinkList(L);//打印插入后的密接者名单
    scanf("%s",kname);//输入待查询的密接者的姓名
    loc=locate_LinkList(L,kname);//按姓名查询密接者
    if(loc!=NULL)  //查找成功则打印该密接者的症状
        printf("接触者%s的症状为：%s\n",loc->data.name,loc->data.symptom);
    else
        printf("查无此人！");
    return OK;
}

