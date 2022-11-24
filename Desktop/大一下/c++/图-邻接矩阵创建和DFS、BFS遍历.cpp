#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0;
typedef struct 
{
	char vertex[100];
	int arcs[100][100];
	int vexnum,arcnum;
}AMGraph;

typedef struct QNode
{
	char data;
	struct QNode* next;
}QNode;

typedef struct QLink
{
	QNode *Head;
	QNode *Rear;
}QLink;

//建立邻接矩阵图 
int createUDN(AMGraph &G);
int LocateVex(AMGraph G,char v);
//DFS
void DFSTravel(AMGraph G);
void DFS(AMGraph G,int i);
//BFS
void BFSTravel(AMGraph G);
void BFS(AMGraph G,int i);
int FisrtVex(AMGraph G,char u);
int NextVex(AMGraph G,char u,int w);
//BFS用到的队列操作 
void iniQLink(QLink &Q);
void EnQueue(QLink &Q,char e);
void DeQueue(QLink &Q,char &e);
int QueueEmpty(QLink Q);

int main()
{
	AMGraph mygraph;
	createUDN(mygraph);
	int n;	
	printf("1--DFS\n");
	printf("2--BFS\n");
	scanf("%d", &n);
	if(n==1) 
		DFSTravel(mygraph); 
	else
		BFSTravel(mygraph); 
	return 0;
}

int visited[100];

int createUDN(AMGraph &G)
{
	int w,i,j;
	char c1,c2; 
	printf("请输入顶点个数 边的个数\n");
	scanf("%d %d", &G.vexnum, &G.arcnum);
	getchar();
	for(i=0;i<G.vexnum;i++)
	{
		printf("请输入%d个元素\n", i+1);
		G.vertex[i]=getchar(); 
		getchar();
	}

	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.arcnum;j++)
			G.arcs[i][j]=32767;
	}
	
	for(int k=0;k<G.arcnum;k++)
	{
		printf("请输入两顶点以及距离\n");
		scanf("%c %c %d", &c1,&c2,&w);
		getchar();
		i=LocateVex(G,c1);
		j=LocateVex(G,c2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;
	}
	return OK;
}

int LocateVex(AMGraph G,char v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertex[i]==v)
			break;
			
	return i;
}

void DFSTravel(AMGraph G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
		visited[i]=0;
	for(i=0;i<G.vexnum;i++)
		if(visited[i]==0)
			DFS(G,i);
}
void BFSTravel(AMGraph G)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(visited[i]==0)
		{
			BFS(G,i);
		}
	}
}

void DFS(AMGraph G,int i)
{
	int j;
	visited[i]=1;
	printf("%c",G.vertex[i]);
	
	for(j=0;j<G.vexnum;j++)
	{
		if(G.arcs[i][j]<32767&&visited[j]==0)
		DFS(G,j);
	}
}
void BFS(AMGraph G,int i)
{
	visited[i]=1;
	int w;//存放邻接 
	char u;//出队元素 
	QLink Q;
	iniQLink(Q);
	printf("%c",G.vertex[i]);
	EnQueue(Q,G.vertex[i]);
	while(!QueueEmpty(Q))
	{
		DeQueue(Q,u);
		for(w=FisrtVex(G,u);w>=0;w=NextVex(G,u,w))
		{
			if(visited[w]==0)
			{
				printf("%c", G.vertex[w]);
				visited[w]=1;
				EnQueue(Q,G.vertex[w]);
			}
		}
	}
}
void iniQLink(QLink &Q)
{
	Q.Head=(QNode*)malloc(sizeof(QNode));
	Q.Head->next=NULL;
	Q.Rear=Q.Head;
}
void EnQueue(QLink &Q,char e)
{
	QNode *p=(QNode*)malloc(sizeof(QNode));
	if(Q.Head->next==NULL)
	{
		Q.Head->data=e;
		Q.Rear=Q.Head->next;
	}
	else
	{
		p->next=NULL;
		p->data=e;
		Q.Rear->next=p;
		Q.Rear=p;
		Q.Rear=NULL;	
	}
}
void DeQueue(QLink &Q,char &e)
{
	QNode *p=(QNode*)malloc(sizeof(QNode));
	p=Q.Head;
	if(Q.Head->next==Q.Rear)
	{
		Q.Head=Q.Rear;
	}
	else if(Q.Head->next==NULL)
		return;
	else
	{
		Q.Head=p->next;
	}
	e=p->data;
	free(p); 
}
int QueueEmpty(QLink Q)
{
	if(Q.Rear==Q.Head)
	 return 0;//队空
	
	return 1; 
}

int FisrtVex(AMGraph G,char u)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		if(u==G.vertex[i])
			break;
	}
	for(j=0;j<G.vexnum;j++)
	{
		if(G.arcs[i][j]<32767)
			break;
	}
	
	return j;
}

int NextVex(AMGraph G,char u,int w)
{
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		if(u==G.vertex[i])
			break;
	}
	for(j=w+1;j<G.vexnum;j++)
	{
		if(G.arcs[i][j]<32767)
			break;
	}
	
	return j;
}

