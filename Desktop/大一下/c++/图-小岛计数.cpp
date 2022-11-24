#include <stdio.h>
#include <stdlib.h>
#define MVNum 100

int visited[MVNum];

typedef struct{
    char vexs[MVNum];        //��������
    int arcs[MVNum][MVNum]; //�ڽӾ���
    int vexnum,arcnum;      //������������
}AMGraph;

int DFS(AMGraph G, int v);//��vΪ������ͼG��v���ڵ���ͨ������
int  DFSTraverse(AMGraph G);//����ͼG

int LocateVex(AMGraph G,char u)   //��ѯ����u���±�
 {
   int i,count;
   for(i=0;i<G.vexnum;++i)
 if(   u==G.vexs[i]     )       return i;
   return -1;
 }

void CreateUDG(AMGraph &G){
    int i=0,j,count;
    char v1,v2;
     v1=getchar();
    while(v1!='#')
       {
           G.vexs[i]=v1;
           i++;
           v1=getchar();
       }
    G.vexnum=i;
       for(i = 0; i<    G.vexnum;++i)     //��ʼ���ڽӾ�������Ԫ�ؾ�Ϊ0
       for(j = 0; j<    G.vexnum;++j)
         G.arcs[i][j] = 0;
       scanf("\n%c %c",&v1,&v2);
      while(v1!='#'&& v2!='#')
      {
      i = LocateVex(G, v1);
      j = LocateVex(G, v2);
      G.arcs[i][j] = 1;
      G.arcs[j][i] = 1;
      scanf("\n%c %c",&v1,&v2);
      }
  }
int main(){
    AMGraph G;
    CreateUDG(G);
    printf("%d",DFSTraverse(G));
    return 0;
}

/* ����������д�� */

int DFS(AMGraph G, int v)//��vΪ������ͼG��v���ڵ���ͨ������
{
	static int cnt=0;
	int i,j,flag=0;
	int u,indexu;
	for(i=0;i<G.vexnum;i++)
	{
		if(visited[i]==0&&G.arcs[v][i]==1)
		{
			cnt++;
			visited[i]=1;
			DFS(G,i);
		}
	}
	
	
	for(j=0;j<G.vexnum;j++)
		if(G.arcs[v][j]==1)
		{
			flag=1;
			break;
		}
	if(flag==0) cnt++;
	return cnt;
}
int  DFSTraverse(AMGraph G)//����ͼG
{
	int cnt=0;
	for(int j=0;j<G.vexnum;j++)
		visited[j]=0;
	int i;
	for(i=0;i<G.vexnum;i++)
	{
		if(visited[i]==0)
		{
			visited[i]==1;
			cnt = DFS(G,i);
		}
	}
	
	return cnt;
}
