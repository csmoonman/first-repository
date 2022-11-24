
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define MAX_QSIZE 30
typedef int Status;
typedef int QElemType;
typedef struct Qnode
{
    QElemType data;
    struct Qnode * next;
}QNode, *QueuePtr;//创建节点类型

typedef  struct Queue{
  QueuePtr   front ; //队首指针
  QueuePtr   rear ; //队尾指针
  }LinkQueue;
  
Status InitLinkQueue(LinkQueue &Q);//对链队列进行初始化
Status EnLinkQueue(LinkQueue &Q,QElemType e);//入队
Status DeLinkQueue(LinkQueue &Q,QElemType &e);//出队
Status QueueEmpty(LinkQueue Q);//判断队空

int main()
{
    QElemType no=1;
    QElemType callno;
    int select,flag=1;
    LinkQueue qu;
    InitLinkQueue(qu);
    while(flag==1)
    {
        //printf("1:排队2:叫号0:退出 请选择:");
        scanf("%d",&select);
        switch(select)
        {
        case 1: printf("您的序号为:%d\n",no);
                EnLinkQueue(qu,no);  //no入队
                no++;
                break;
        case 2: if(DeLinkQueue(qu,callno)==ERROR)
                    printf(">>没有排队的客户!\n");
            else//队不空
                printf(">>请%d号办理业务\n",callno);
                break;
        case 0:flag=0;
        }
    }
    return 0;
}

/* 请在这里填写答案 */
Status InitLinkQueue(LinkQueue &Q)
{
	Q.front=(QueuePtr)malloc(sizeof(QNode));
	if(Q.front==NULL)
		return ERROR;
		
	Q.rear=Q.front;
	Q.rear->next=NULL;
	return OK;
}

Status EnLinkQueue(LinkQueue &Q,QElemType e)
{
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(s==NULL)
		return ERROR;
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	
	return OK;
}

Status DeLinkQueue(LinkQueue &Q,QElemType &e)
{
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	s=Q.front->next;
	
	if(Q.front==Q.rear)
		return ERROR;
	else if(s==Q.rear)
	{
		e=s->data;
		Q.rear=Q.front;
		Q.front->next=NULL;
		
		free(s);
	}
	else
	{
		e=s->data;
		Q.front->next=s->next;
		free(s);
	}

	return OK;
}

Status QueueEmpty(LinkQueue Q)
{
	if(Q.front==Q.rear)
		return ERROR;
	
	return OK;
}
