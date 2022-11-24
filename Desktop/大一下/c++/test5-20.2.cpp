#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef struct {
  int *base;
  int front;    //��ͷ
  int rear;    //��β
}SqQueue;

void InitQ(SqQueue &Q,int N);
void AddQ(SqQueue &Q, int x );
Status DeleteQ(SqQueue &Q,int &e);
void printQ(SqQueue Q);  //�������Ԫ�ؼ����±�λ��

int N;
int main()
{
        int x,e,i;
    SqQueue Q;
        scanf("%d",&N);     //����ѭ�����пռ��С  
    InitQ(Q,N);
        for(i=0;i<5;i++){     
        scanf("%d",&x);
        AddQ(Q,x);
    }
    printQ(Q);   //��������еĸ�Ԫ��
    for(i=0;i<5;i++){       
        if(DeleteQ(Q,e)==OK) printf("%d is out.\n",e); 
    }
    for(i=0;i<5;i++){  
        scanf("%d",&x);
            AddQ(Q,x);
    }
    printQ(Q);
    return 0;
}
void printQ(SqQueue Q){   
    int i;
    i=Q.front;
    while(i!=Q.rear){
         printf("%d(%d) ",Q.base[i],i);
         i=(i+1)%N;
    }
    printf("\n");
}

/* ����������д�� */
void InitQ(SqQueue &Q,int N)
{
    Q.base=(int *)malloc(N*sizeof(int)); 

    Q.front=0;
	Q.rear=0;

}

void AddQ(SqQueue &Q, int x )
{
    if(Q.front!=(Q.rear+1)%N)  
	{
		Q.base[Q.rear]=x; 
    	Q.rear=(Q.rear+1)%N;
	}
		else
	{
		printf("Queue Full\n");
	}

}

Status DeleteQ(SqQueue &Q,int &e)
{
	if(Q.front==Q.rear)  
		printf("Queue Empty\n");
        return ERROR;
        
    e=Q.base[Q.front];  
    Q.front=(Q.front+1)%N;  
    
    return OK;
}

