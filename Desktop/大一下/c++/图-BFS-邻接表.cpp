
#include"stdio.h"
#include"stdlib.h"
#define MAX_VERTEX_NUM 10      /*定义最大顶点数*/
typedef int Vertex;
typedef struct  ArcNode{       /*表结点*/
    int adjvex;               /*邻接点域*/
    struct  ArcNode *nextarc; /*指向下一个表结点*/
}ArcNode;
typedef struct VNode{           /*头结点*/
    Vertex data;                  /*顶点域*/
    ArcNode *firstarc;          /*指向第一个表结点*/
}VNode,AdjList[MAX_VERTEX_NUM]; /*AdjList是数组类型*/
typedef struct { 
    AdjList vertices;           /*邻接表中数组定义*/
    int vexnum,arcnum;          /*图中当前顶点数和边数*/
} ALGraph;                 /*图类型*/
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MAX_VERTEX_NUM];/*定义标志向量，为全局变量*/
void CreatALGraph(ALGraph *G);/* 创建图并且将Visited初始化为false；裁判实现，细节不表 */
void BFS(ALGraph *G,int v);
int main()
{
    Vertex v;
    ALGraph G;
    CreatALGraph(&G);
    scanf("%d", &v);
    printf("BFS from %d:",v);
    BFS(&G,v);     
    return 0;
}
/* 你的代码将被嵌在这里 */
typedef struct QNode
{
	int data;
	struct QNode* next;
}QNode,*Qptr;
typedef struct QLink
{
	Qptr head;
	Qptr rear;
}QLink;



	
void EnQueue(QLink &Q,int e)
{
	Qptr p;
	p=(Qptr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p; 
}

int DeQueue(QLink Q)
{
	Qptr p;
	p=(Qptr)malloc(sizeof(QNode));
	if(Q.head==Q.rear)
		return -1;
	else if(Q.head->next=Q.rear)
	{
		p=Q.head->next;
		Q.rear=Q.head;
	}
	else
	{
		p=Q.head->next;
		Q.head->next=p->next;
	}
	return p->data;
}

int firstadjvex(ALGraph *G,int i)
{
	ArcNode* p;
	if(G->vertices[i].firstarc==NULL)
	{
		return -1;
	}
	else
	{
		p=G->vertices[i].firstarc;
		return p->adjvex;
	}
}

int nextadjvex(ALGraph *G,int i,int w)
{
	ArcNode* p;
	p=G->vertices[i].firstarc;
	while(p->adjvex!=w)
		p=p->nextarc;
	p=p->nextarc;
	if(p)
		return p->adjvex;
	else 
		return -1;
}

void BFS(ALGraph *G,int i)
{
	printf(" %d", i);
	visited[i]=TRUE;
	int w;
	QLink Q;
	Q.head=(Qptr)malloc(sizeof(QNode));
	Q.head->next=NULL;
	Q.rear=Q.head;

	EnQueue(Q,i);
	while(Q.head!=Q.rear)
	{
		i=DeQueue(Q);
		for(w=firstadjvex(G,i);w>=0;w=nextadjvex(G,i,w))
		{
			if(visited[w]==0)
			{
				printf(" %d", w);
				visited[w]=TRUE;
				EnQueue(Q,w);
			}
		}
	}
}
