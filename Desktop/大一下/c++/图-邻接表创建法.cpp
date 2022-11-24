
#include <stdio.h>
#include <stdlib.h>
#define MVNum 100                                 //最大顶点数
typedef struct ArcNode{                        //表结点
    int adjvex;                                    //邻接点的位置
    struct ArcNode *nextarc;      //指向下一个表结点的指针
  }ArcNode;
typedef struct VNode{
   char data;                                    //顶点信息
   ArcNode *firstarc;         //指向第一个表结点的指针
}VNode, AdjList[MVNum];                 //AdjList表示邻接表类型
typedef struct{
    AdjList vertices;              //头结点数组
    int vexnum, arcnum;     //图的当前顶点数和边数
}ALGraph;
void CreatMGraph(ALGraph &G);/* 创建图 */
void printGraph(ALGraph G);/*输出图 */
int main()
{
    ALGraph G;
    CreatMGraph(G);
    printGraph(G);
    return 0;
}

void printGraph(ALGraph G)
{
    int i;
    ArcNode *p;
    for(i=0;i<G.vexnum;i++)
    {
       printf("%c:",G.vertices[i].data);
       for(p=G.vertices[i].firstarc;p;p=p->nextarc)
           printf(" %c",G.vertices[p->adjvex].data);
       printf("\n");
    }
}

/* 请在这里填写答案 */

int locate(ALGraph G,char v)
{
		for(int i=0;i<G.vexnum;i++)
		{
			if(G.vertices[i].data==v)
				return i;
		}
	return 0;
}
void CreatMGraph(ALGraph &G)//创建图G
{
	scanf("%d %d",&G.vexnum,&G.arcnum);
	getchar();
	for(int i=0;i<G.vexnum;i++)
	{
		scanf("%c",&G.vertices[i].data);
		G.vertices[i].firstarc=NULL;
	}
	getchar();
	char m,n;
	int mindex,nindex;
	for(int i=0;i<G.arcnum;i++)
	{
		ArcNode *p=(ArcNode*)malloc(sizeof(ArcNode));
		ArcNode *q=(ArcNode*)malloc(sizeof(ArcNode));
		scanf("%c%c",&m,&n);
		getchar();
		mindex=locate(G,m);
		nindex=locate(G,n);
		
		p->adjvex=nindex;
		p->nextarc=NULL;
		q->adjvex=mindex;
		q->nextarc=NULL;
		if(G.vertices[mindex].firstarc==NULL)
		{
			G.vertices[mindex].firstarc=p;
		}
		else
		{
			p->nextarc=G.vertices[mindex].firstarc;
			G.vertices[mindex].firstarc=p;
		}
		
		if(G.vertices[nindex].firstarc==NULL)
		{
			G.vertices[nindex].firstarc=q;
		}
		else
		{
			q->nextarc=G.vertices[nindex].firstarc;
			G.vertices[nindex].firstarc=q;
		}
	}
}

