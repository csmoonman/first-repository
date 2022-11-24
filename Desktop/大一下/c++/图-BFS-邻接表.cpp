
#include"stdio.h"
#include"stdlib.h"
#define MAX_VERTEX_NUM 10      /*������󶥵���*/
typedef int Vertex;
typedef struct  ArcNode{       /*����*/
    int adjvex;               /*�ڽӵ���*/
    struct  ArcNode *nextarc; /*ָ����һ������*/
}ArcNode;
typedef struct VNode{           /*ͷ���*/
    Vertex data;                  /*������*/
    ArcNode *firstarc;          /*ָ���һ������*/
}VNode,AdjList[MAX_VERTEX_NUM]; /*AdjList����������*/
typedef struct { 
    AdjList vertices;           /*�ڽӱ������鶨��*/
    int vexnum,arcnum;          /*ͼ�е�ǰ�������ͱ���*/
} ALGraph;                 /*ͼ����*/
typedef enum{FALSE,TRUE} Boolean;
Boolean visited[MAX_VERTEX_NUM];/*�����־������Ϊȫ�ֱ���*/
void CreatALGraph(ALGraph *G);/* ����ͼ���ҽ�Visited��ʼ��Ϊfalse������ʵ�֣�ϸ�ڲ��� */
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
/* ��Ĵ��뽫��Ƕ������ */
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
