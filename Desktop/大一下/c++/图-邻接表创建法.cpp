
#include <stdio.h>
#include <stdlib.h>
#define MVNum 100                                 //��󶥵���
typedef struct ArcNode{                        //����
    int adjvex;                                    //�ڽӵ��λ��
    struct ArcNode *nextarc;      //ָ����һ�������ָ��
  }ArcNode;
typedef struct VNode{
   char data;                                    //������Ϣ
   ArcNode *firstarc;         //ָ���һ�������ָ��
}VNode, AdjList[MVNum];                 //AdjList��ʾ�ڽӱ�����
typedef struct{
    AdjList vertices;              //ͷ�������
    int vexnum, arcnum;     //ͼ�ĵ�ǰ�������ͱ���
}ALGraph;
void CreatMGraph(ALGraph &G);/* ����ͼ */
void printGraph(ALGraph G);/*���ͼ */
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

/* ����������д�� */

int locate(ALGraph G,char v)
{
		for(int i=0;i<G.vexnum;i++)
		{
			if(G.vertices[i].data==v)
				return i;
		}
	return 0;
}
void CreatMGraph(ALGraph &G)//����ͼG
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

