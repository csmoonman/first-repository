
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
}QNode, *QueuePtr;//�����ڵ�����

typedef  struct Queue{
  QueuePtr   front ; //����ָ��
  QueuePtr   rear ; //��βָ��
  }LinkQueue;
  
Status InitLinkQueue(LinkQueue &Q);//�������н��г�ʼ��
Status EnLinkQueue(LinkQueue &Q,QElemType e);//���
Status DeLinkQueue(LinkQueue &Q,QElemType &e);//����
Status QueueEmpty(LinkQueue Q);//�ж϶ӿ�

int main()
{
    QElemType no=1;
    QElemType callno;
    int select,flag=1;
    LinkQueue qu;
    InitLinkQueue(qu);
    while(flag==1)
    {
        //printf("1:�Ŷ�2:�к�0:�˳� ��ѡ��:");
        scanf("%d",&select);
        switch(select)
        {
        case 1: printf("�������Ϊ:%d\n",no);
                EnLinkQueue(qu,no);  //no���
                no++;
                break;
        case 2: if(DeLinkQueue(qu,callno)==ERROR)
                    printf(">>û���ŶӵĿͻ�!\n");
            else//�Ӳ���
                printf(">>��%d�Ű���ҵ��\n",callno);
                break;
        case 0:flag=0;
        }
    }
    return 0;
}

/* ����������д�� */
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
