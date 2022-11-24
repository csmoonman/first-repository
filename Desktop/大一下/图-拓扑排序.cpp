#include <stdio.h>
//#include "conio.h"
#include <stdlib.h>
#include <string.h>
#define  TRUE   1
#define  FALSE  0
#define  OK     1
#define  ERROR 0
#define  OVERFLOW  -1
#define MAXSIZE 30
#define VERTEX_MAX 30   /*��󶥵���*/
#define VEX_NUM 10
typedef int Status;
typedef char Vextype[20];  /*��������*/
typedef int ElemType;
typedef struct
{ ElemType elem[MAXSIZE];
  int top;
  }SeqStack;                                      /*����˳��ջ�ṹ*/
typedef struct node       /*�߽�㶨��*/
 {
    int  adjvex;          /*�ڽӵ���*/
    struct node  *next; /*ָ����һ���߽���ָ����*/
  }EdgeNode;
typedef struct vnode   /*��ͷ��㶨��*/
 { int Indegree;        /*���������*/
   Vextype  vertex;     /*������Ϣ*/
   EdgeNode   *firstedge;
  }VertexNode;
typedef struct                        /*ͼ���ڽӱ�洢*/
 { VertexNode adjlist[VERTEX_MAX];
   int n,e;                            /*�������ͱ���*/
 } ALGraph;


void InitStack_Sq(SeqStack &s)                     /*��ʼ��ջ����*/
  {s.top=-1;
  }/*InitStack_sq*/
int Empty_Sq(SeqStack s)                       /*��ջ�Ƿ�Ϊ��*/
  {if(s.top==-1)
    return 1;
   else
       return 0;
  }/*Empty_sq*/
Status Push_SeqStack(SeqStack &s, ElemType x)
 {if (s.top==MAXSIZE-1)  return OVERFLOW ;        /* ջ��������ջ */
  else { s.top++;
         s.elem[s.top]=x ;
        return OK;
   }
 }

Status  Pop_SeqStack(SeqStack &s, ElemType &y)
   {  if  (Empty_Sq(s))  return OVERFLOW;           /* ջ�ղ��ܳ�ջ */
       else  {  y=s.elem[s.top];
   s.top--;  return OK;
              }                                         /* ջ��Ԫ�ش���*y������ */
   }
   void CreateALGraph(ALGraph &G) /*��������ͼ���ڽӱ�*/
{ int i,v,w;
  int Indegree[VERTEX_MAX]={0};
  EdgeNode *s;
  scanf("%d,%d",&(G.n),&(G.e)); /*���붥����n�ͻ���m*/
  for (i=0;i<G.n;i++)
     { scanf("%s",G.adjlist[i].vertex);
       G.adjlist[i].firstedge=NULL;
     }
  for (w=0;w<G.e;w++) /*�����߱�*/
     { scanf("%d,%d",&i,&v);
       s=(EdgeNode*)malloc(sizeof(EdgeNode));
       s->adjvex=v;
       Indegree[v]++;  /*ͳ�Ƹ���������*/
       s->next=G.adjlist[i].firstedge;    /*ǰ�巽��*/
       G.adjlist[i].firstedge=s;
     }
   for(i=0;i<G.n;i++)
     G.adjlist[i].Indegree=Indegree[i];
  }/*CreateALGraph*/
void topsort( ALGraph &G);

int main()
{
    ALGraph g;
    CreateALGraph(g);
    printf("��������Ϊ��");
    topsort(g);
    return 0;
}
/* ����������д�� */
void topsort( ALGraph &G)
{ 
	SeqStack Sq;
	InitStack_Sq(Sq);
	int i;
	for(i=0;i<G.n;i++)
	{
		if(G.adjlist[i].Indegree==0)	Push_SeqStack(Sq,i);
	}
	int cnt=0;
	while(!Empty_Sq(Sq))
	{
		EdgeNode *p;
		Pop_SeqStack(Sq,i);
		cnt++;
		printf("%s ",G.adjlist[i].vertex);
		p=G.adjlist[i].firstedge;
		while(p!=NULL)
		{
			int t=p->adjvex;
			G.adjlist[t].Indegree--;
			if(G.adjlist[t].Indegree==0)	Push_SeqStack(Sq,t);
			p=p->next;
		}
	}
	if(cnt<G.e)
	printf("�����޷������"); 
}
