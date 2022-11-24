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
	printf("�ж��ٸ����㣿\n");
	printf("�ж������ߣ�\n������ ����\n");
	scanf("%d %d",&G.vexnum,&G.arcsnum);
	getchar();
	
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
			G.arcs[i][j]=0;
	}
	
	printf("���������ж��㣬����֮�䲻���ո�\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vex[i]);
	}
	getchar();
	for(i=0;i<G.arcsnum;i++)
	{
		printf("�������%d�������ӵ��������㣬�м��Կո�����\n",i+1);
		scanf("%c %c",&v,&w);
		getchar();
		buildArcs(G,v,w);
	}
}

void DFS_AM(AMGragh G,int v)
{
	printf("%c ",G.vex[v]);
	visited[v]=1;
	int w;
	for(w=0;w<G.vexnum;w++)
	{
		if(G.arcs[v][w]!=0&&visited[w]==0)
			DFS_AM(G,w);
	}
}

void DFSTraverse(AMGragh G)
{
	int v;
	for(v=0;v<G.vexnum;v++)
	{
		if(visited[v]==0)
			DFS_AM(G,v);
	}
}

int main()
{
	int i,j;
	AMGragh G;
	createUDN(G);
	
	printf("�ڽӾ���Ϊ��\n");
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
	DFSTraverse(G);
	return 0;
}
