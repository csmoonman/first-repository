#include<stdio.h>
#define MAXSIZE 100 
typedef struct
{
	char data[MAXSIZE];
	int acrs[MAXSIZE][MAXSIZE];
	int vexnum,arcnum;
}AMGragh;

typedef struct
{
	int  lowcost;
	char adjvex;
}closeedge[MAXSIZE];

int Locate(AMGragh G,char v)
{
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(v==G.data[i])
			return i;
	}
	
	return -1;
}

void createAMG(AMGragh &G)
{
	printf("请输入顶点数和边数，顶点数 边数:\n");
	scanf("%d %d",&G.vexnum,&G.arcnum);
	getchar();
	int i,j;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			G.acrs[i][j]=32767;
			G.acrs[j][i]=32767;
		}
	}
	
	printf("请输入所有顶点，顶点之间没有间隔:\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.data[i]);
	}
	getchar();
	
	int vi,wi;
	char v,w;
	for(i=0;i<G.arcnum;i++)
	{
		printf("请输入第%d条边所连的两个顶点 :v w\n",i+1);
		scanf("%c %c",&v,&w);
		getchar();
		vi=Locate(G,v);
		wi=Locate(G,w);

		if(vi<0||wi<0)
			printf("您的输入有误！\n");
		else
		{
			printf("请输入这条边的权值：\n");
			int t;
			scanf("%d",&t);
			getchar();

			G.acrs[vi][wi]=t;
			G.acrs[wi][vi]=t;	
		}
	}
}

void MiniSpanTree_Prim(AMGragh G,char u)//从u顶点开始 
{

	closeedge Closedge;
	int i,j;
	int k=Locate(G,u);
	for(i=0;i<G.vexnum;i++)
		if(i!=k)
		{
			Closedge[i].adjvex=u;
			Closedge[i].lowcost=G.acrs[k][i];
		}
	Closedge[k].lowcost=0;
	for(i=1;i<G.vexnum;i++)
	{
		int min=32767;
		for(j=0;j<G.vexnum;j++)
		{
			if(Closedge[j].lowcost!=0&&Closedge[j].lowcost<min)
			{
				min=Closedge[j].lowcost;
				k=j;
			}
		}
		char u0=Closedge[k].adjvex;
		char v0=G.data[k];
		if(u0!=v0)	printf("%c--%c\n",u0,v0); 
		Closedge[k].lowcost=0;
		Closedge[k].adjvex=v0; 
		for(j=0;j<G.vexnum;j++)
		{
			if(G.acrs[k][j]<Closedge[j].lowcost)
			{
				Closedge[j].lowcost=G.acrs[k][j];
				Closedge[j].adjvex=v0;
			}
		}
	}
}

int main()
{
	int i,j;
	AMGragh G;
	createAMG(G);
	MiniSpanTree_Prim(G,G.data[1]);
	
	printf("\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(j==G.vexnum-1)
				printf("%7d\n",G.acrs[i][j]);
			else
				printf("%7d ",G.acrs[i][j]);
		}
	}
	
	return 0;
}
