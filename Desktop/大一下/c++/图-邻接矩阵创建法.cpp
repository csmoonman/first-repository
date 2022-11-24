#include <stdio.h>
#define MVNum 100                 //最大顶点数
typedef struct{
  char vexs[MVNum];           //存放顶点的一维数组
  int arcs[MVNum][MVNum];     //邻接矩阵
  int vexnum,arcnum;          //图的当前顶点数和边数
}MGraph;
void CreatMGraph(MGraph &G);/* 创建图 */
void printGraph(MGraph G);/*输出图 */
int locate(MGraph G,char v);//返回顶点v的下标

int main()
{
    MGraph G;
    CreatMGraph(G);//创建图G
    printGraph(G);//打印该图
    return 0;
}

void printGraph(MGraph G)//打印图
{
    int i,j;
    for(i=0;i<G.vexnum;i++)
    {
       printf("%c:",G.vexs[i]);
       for(j=0;j<G.vexnum;j++)
          if (G.arcs[i][j])  printf(" %c",G.vexs[j]);
       printf("\n");
    }
}

/* 请在这里填写答案 */
void CreatMGraph(MGraph &G)
{
	scanf("%d %d", &G.vexnum,&G.arcnum); 
	getchar();
	for(int i=0;i<G.vexnum;i++)
		scanf("%c", &G.vexs[i]);
	getchar();
	for(int i=0;i<G.vexnum;i++)
	{
		for(int j=0;j<G.vexnum;j++)
		{
			G.arcs[i][j]=0;
		}
	}
	
	for(int i=0;i<G.arcnum;i++)
	{
		char m,n;
		int mindex,nindex;
		scanf("%c%c", &m,&n);
		getchar();
		mindex=locate(G,m);
		nindex=locate(G,n);
		G.arcs[mindex][nindex]=1;
		G.arcs[nindex][mindex]=1;
	}
	
}
int locate(MGraph G,char v)//返回顶点v的下标
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.vexs[i]==v)
			return i;
	}
	return 0;
}

