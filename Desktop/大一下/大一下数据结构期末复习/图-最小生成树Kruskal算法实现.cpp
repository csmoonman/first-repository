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
	char head;
	char rear;
	int weight;
}Edge[MAXSIZE],EdgeNode;

int vexset[MAXSIZE];
Edge edge;

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
	printf("�����붥�����ͱ����������� ����:\n");
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
	
	printf("���������ж��㣬����֮��û�м��:\n");
	for(i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.data[i]);
	}
	getchar();
	
	int vi,wi;
	char v,w;
	for(i=0;i<G.arcnum;i++)
	{
		printf("�������%d������������������ :v w\n",i+1);
		scanf("%c %c",&v,&w);
		getchar();
		vi=Locate(G,v);
		wi=Locate(G,w);

		if(vi<0||wi<0)
			printf("������������\n");
		else
		{
			printf("�����������ߵ�Ȩֵ��\n");
			int t;
			scanf("%d",&t);
			getchar();
			edge[i].weight=t;
			edge[i].head=G.data[vi];
			edge[i].rear=G.data[wi];
			G.acrs[vi][wi]=t;
			G.acrs[wi][vi]=t;	
		}
	}
}

void sort(AMGragh G,Edge &edge)
{
	int i;
	int k;
	int j;
	for(i=0;i<G.arcnum;i++)
	{
		k=i;
		for(j=i+1;j<G.arcnum;j++)
			if(edge[j].weight<edge[k].weight) k=j;
		if(k!=i)
		{
			EdgeNode t=edge[i];
			edge[i]=edge[k];
			edge[k]=t;
		}
	}
	
	for(i=0;i<G.arcnum;i++)
		printf("%c--%c :%d\n",edge[i].head,edge[i].rear,edge[i].weight);
}

void MiniSpanTree_Kruskal(AMGragh G)//��u���㿪ʼ 
{
	int v1,v2,i,j;
	int vs1,vs2;
	for(i=0;i<G.vexnum;i++)
		vexset[i]=i;
	sort(G,edge);
	for(i=0;i<G.arcnum;i++)
	{
		v1=Locate(G,edge[i].head);
		v2=Locate(G,edge[i].rear);
		vs1=vexset[v1];
		vs2=vexset[v2];
		if(vs1!=vs2)
		{
			printf("%c--%c\n",edge[i].head,edge[i].rear);
			for(j=0;j<G.vexnum;j++)
			{
				if(vexset[j]==vs2) vexset[j]=vs1;
			}
		}
	}
}

int main()
{
	int i,j;
	AMGragh G;
	createAMG(G);
	MiniSpanTree_Kruskal(G);
	
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
