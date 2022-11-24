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

int visited[MAXSIZE]={0};

int LocateVex(ALGragh G,char v)
{
	int index,i;
	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.vertices[i].data)
			return i;
	}
	
	return -1;//δ�ҵ�����-1 
}

void createUDG(ALGragh &G)
{
	char v,w;//�洢ÿ�������ӵĶ��� 
	int vi,wi,i;
	printf("�����붥����������(���� ����)��\n");
	scanf("%d %d",&G.vexnum,&G.arcsnum);
	getchar();
	printf("���������ж��㣬֮��û�м�����Իس���������\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vertices[i].data);
		//G.vertices[i].firstarc=(ArcNode*)malloc(sizeof(ArcNode));
		G.vertices[i].firstarc=NULL;
	}
	getchar();
	for(i=0;i<G.arcsnum;i++)
	{
		printf("�������%d���ߣ�v w\n",i+1);
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


void DFS_AL(ALGragh G,int v)//�ӵ�v�����㿪ʼ�����������
{
	printf("%c ",G.vertices[v].data); 
	visited[v]=1;
	int w;
	
	ArcNode* p=G.vertices[v].firstarc;
	
	while(p!=NULL)
	{
		w=p->adjvex;
		if(visited[w]==0)
			DFS_AL(G,w);
		p=p->nextarc;
	}
}

void DFSTraverse(ALGragh G)
{
	int v;
	for(v=0;v<G.vexnum;v++)
		if(visited[v]==0)
			DFS_AL(G,v);
} 

int main()
{
	ALGragh G;
	createUDG(G);
	
	DFSTraverse(G);
	return 0;
}
