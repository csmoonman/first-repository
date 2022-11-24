#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct ArcNode
{
	int adjvex;
	ArcNode* nextarc;
}ArcNode; 
typedef struct 
{
	char data;
	ArcNode* firstarc;
}VNode,AdjList[MAXSIZE];
typedef struct 
{
	AdjList vertices;
	int vexnum,arcsnum;
}ALGragh;

//标记 
int visited[MAXSIZE]={0};
//借助队列来进行广度优先搜索遍历
typedef struct QNode
{
	int data;
	QNode* next;
}QNode,*QueuePtr;

typedef struct 
{
	QueuePtr Head;
	QueuePtr Rear;
}QLink;


int LocateVex(ALGragh G,char v)
{
	int index,i;
	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.vertices[i].data)
			return i;
	}
	
	return -1;//未找到返回-1 
}

void createUDG(ALGragh &G)
{
	char v,w;//存储每条边连接的顶点 
	int vi,wi,i;
	printf("请输入顶点数、边数(顶点 边数)：\n");
	scanf("%d %d",&G.vexnum,&G.arcsnum);
	getchar();
	printf("请输入所有顶点，之间没有间隔，以回车键结束：\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vertices[i].data);
		//G.vertices[i].firstarc=(ArcNode*)malloc(sizeof(ArcNode));
		G.vertices[i].firstarc=NULL;
	}
	getchar();
	for(i=0;i<G.arcsnum;i++)
	{
		printf("请输入第%d条边：v w\n",i+1);
		scanf("%c %c",&v,&w); 
		getchar(); 
		
		vi=LocateVex(G,v);
		wi=LocateVex(G,w);
		
		ArcNode* p,*q;//
		p=(ArcNode*)malloc(sizeof(ArcNode));
		q=(ArcNode*)malloc(sizeof(ArcNode));
		p->nextarc=NULL;
		q->nextarc=NULL; 
		p->adjvex=wi;
		q->adjvex=vi;
		p->nextarc=G.vertices[vi].firstarc;
		G.vertices[vi].firstarc=p;
		q->nextarc=G.vertices[wi].firstarc;
		G.vertices[wi].firstarc=q;
	} 
} 

void InitQueue(QLink &Q)
{
	Q.Head=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.Head)
		return;
	Q.Head->next=NULL;
	Q.Rear=Q.Head;
}

void EnQueue(QLink &Q,int e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return;
	p->next=NULL;
	p->data=e;
	Q.Rear->next=p;
	Q.Rear=p;
}

void DeQueue(QLink &Q,int &e)
{
	QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
	if(!p)
		return;
	if(Q.Head==Q.Rear)
		return;
	if(Q.Head->next==Q.Rear)
	{
		p=Q.Rear;
		Q.Rear=Q.Head;
	}
	else
	{
		p=Q.Head->next;
		Q.Head->next=p->next;
	}
	
	e=p->data;
}

void BFS_AL(ALGragh G,int v)//从第v个顶点开始广度优先搜索遍历
{
	visited[v]=1;
	printf("%c ",G.vertices[v].data);
	QLink Q;
	InitQueue(Q);
	
	EnQueue(Q,v);
	while(Q.Head!=Q.Rear)
	{
		int u;
		DeQueue(Q,u);
		ArcNode* p=G.vertices[u].firstarc;
		while(p!=NULL)
		{
			if(visited[p->adjvex]==0)
			{ 
				printf("%c ",G.vertices[p->adjvex].data);
				visited[p->adjvex]=1;
				EnQueue(Q,p->adjvex);
			}
			p=p->nextarc;
		}
	}
} 

void BFSTraverse(ALGragh G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(visited[i]==0)
			BFS_AL(G,i);
	}
}

int main()
{
	ALGragh G;
	createUDG(G);
	
	BFSTraverse(G);
	return 0;
}
