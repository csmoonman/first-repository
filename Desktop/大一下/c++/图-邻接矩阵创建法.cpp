#include <stdio.h>
#define MVNum 100                 //��󶥵���
typedef struct{
  char vexs[MVNum];           //��Ŷ����һά����
  int arcs[MVNum][MVNum];     //�ڽӾ���
  int vexnum,arcnum;          //ͼ�ĵ�ǰ�������ͱ���
}MGraph;
void CreatMGraph(MGraph &G);/* ����ͼ */
void printGraph(MGraph G);/*���ͼ */
int locate(MGraph G,char v);//���ض���v���±�

int main()
{
    MGraph G;
    CreatMGraph(G);//����ͼG
    printGraph(G);//��ӡ��ͼ
    return 0;
}

void printGraph(MGraph G)//��ӡͼ
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

/* ����������д�� */
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
int locate(MGraph G,char v)//���ض���v���±�
{
	for(int i=0;i<G.vexnum;i++)
	{
		if(G.vexs[i]==v)
			return i;
	}
	return 0;
}

