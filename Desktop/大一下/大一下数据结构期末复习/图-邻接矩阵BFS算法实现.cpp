#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef struct 
{
	char vex[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vexnum;
	int arcsnum;
}AMGragh;

int visited[MAXSIZE]={0};

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

void buildArcs(AMGragh &G,char v,char w)
{
	int vi,wi,i;
	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.vex[i])	
			vi=i;
		if(w==G.vex[i])
			wi=i;
	}
	
	G.arcs[vi][wi]=1;
	G.arcs[wi][vi]=1;
}

void createUDN(AMGragh &G)
{
	int i,j;
	char v,w;
	printf("有多少个顶点？\n");
	printf("有多少条边？\n顶点数 边数\n");
	scanf("%d %d",&G.vexnum,&G.arcsnum);
	getchar();
	
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	}
	
	printf("请输入所有顶点，顶点之间不留空格\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vex[i]);
	}
	getchar();
	for(i=0;i<G.arcsnum;i++)
	{
		printf("请输入第%d条边连接的两个顶点，中间以空格相连\n",i+1);
		scanf("%c %c",&v,&w);
		getchar();
		buildArcs(G,v,w);
	}
}

void BFS_AM(AMGragh G,int v)
{
	printf("%c ",G.vex[v]);
	QLink Q;
	InitQueue(Q);
	visited[v]=1;
	EnQueue(Q,v);
	while(Q.Head!=Q.Rear)
	{
		int w;
		DeQueue(Q,v);
		for(w=0;w<G.vexnum;w++)
		{
			if(G.arcs[v][w]!=0&&visited[w]==0)
			{
				EnQueue(Q,w);
				printf("%c ",G.vex[w]);
				visited[w]=1;
			}
		}	
	}
}

void BFSTraverse(AMGragh G)
{
	int v;
	for(v=0;v<G.vexnum;v++)
	{
		if(visited[v]==0)
			BFS_AM(G,v);
	}
}

int main()
{
	int i,j;
	AMGragh G;
	createUDN(G);
	
	printf("邻接矩阵为：\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(j==(G.vexnum-1))
				printf("%d\n",G.arcs[i][j]);
			else
				printf("%d ",G.arcs[i][j]);
		}
	}
	BFSTraverse(G);
	return 0;
}
