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
#define VERTEX_MAX 30   /*最大顶点数*/
#define VEX_NUM 10
typedef int Status;
typedef char Vextype[20];  /*顶点类型*/
typedef int ElemType;
typedef struct
{ ElemType elem[MAXSIZE];
  int top;
  }SeqStack;                                      /*定义顺序栈结构*/
typedef struct node       /*边结点定义*/
 {
    int  adjvex;          /*邻接点域*/
    struct node  *next; /*指向下一个边结点的指针域*/
  }EdgeNode;
typedef struct vnode   /*表头结点定义*/
 { int Indegree;        /*顶点入度域*/
   Vextype  vertex;     /*顶点信息*/
   EdgeNode   *firstedge;
  }VertexNode;
typedef struct                        /*图的邻接表存储*/
 { VertexNode adjlist[VERTEX_MAX];
   int n,e;                            /*顶点数和边数*/
 } ALGraph;


void InitStack_Sq(SeqStack &s)                     /*初始化栈操作*/
  {s.top=-1;
  }/*InitStack_sq*/
int Empty_Sq(SeqStack s)                       /*判栈是否为空*/
  {if(s.top==-1)
    return 1;
   else
       return 0;
  }/*Empty_sq*/
Status Push_SeqStack(SeqStack &s, ElemType x)
 {if (s.top==MAXSIZE-1)  return OVERFLOW ;        /* 栈满不能入栈 */
  else { s.top++;
         s.elem[s.top]=x ;
        return OK;
   }
 }

Status  Pop_SeqStack(SeqStack &s, ElemType &y)
   {  if  (Empty_Sq(s))  return OVERFLOW;           /* 栈空不能出栈 */
       else  {  y=s.elem[s.top];
   s.top--;  return OK;
              }                                         /* 栈顶元素存入*y，返回 */
   }
   void CreateALGraph(ALGraph &G) /*创建有向图的邻接表*/
{ int i,v,w;
  int Indegree[VERTEX_MAX]={0};
  EdgeNode *s;
  scanf("%d,%d",&(G.n),&(G.e)); /*输入顶点数n和弧数m*/
  for (i=0;i<G.n;i++)
     { scanf("%s",G.adjlist[i].vertex);
       G.adjlist[i].firstedge=NULL;
     }
  for (w=0;w<G.e;w++) /*建立边表*/
     { scanf("%d,%d",&i,&v);
       s=(EdgeNode*)malloc(sizeof(EdgeNode));
       s->adjvex=v;
       Indegree[v]++;  /*统计各顶点的入度*/
       s->next=G.adjlist[i].firstedge;    /*前插方法*/
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
    printf("拓扑序列为：");
    topsort(g);
    return 0;
}
/* 请在这里填写答案 */
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
	printf("后续无法输出！"); 
}
