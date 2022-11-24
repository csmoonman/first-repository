#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct QIntNode
{
	long long int data;
	struct QIntNode* next;
}QIntNode,*QueueIntPtr;

typedef struct QCharNode
{
	char data;
	struct QCharNode *next;
}QCharNode,*QueueCharPtr;

typedef struct IntQueue
{
	QueueIntPtr front;
	QueueIntPtr rear;
}LinkIntQueue;

typedef struct CharQueue
{
	QueueCharPtr front;
	QueueCharPtr rear;
}LinkCharQueue;

//初始化 
Status IniCharQueue(LinkCharQueue &Q);
Status IniIntQueue(LinkIntQueue &Q);
//
//入队 
void PushCharQueue(LinkCharQueue &Q, char e);
void PushIntQueue(LinkIntQueue &Q,long long  int e);
//
//出队 
Status PopCharQueue(LinkCharQueue &Q, char &e);
Status PopIntQueue(LinkIntQueue &Q, long long int &e);
//

//主函数 
int main()
{
	//初始化 
	LinkIntQueue Qnum;
	LinkCharQueue Qchar;
	IniIntQueue(Qnum);
	IniCharQueue(Qchar);
	
	//存放输入的值 
	char ch;
	
	long long int a,b;
	char tempchar;
	long long int tempint;
	
	ch=getchar();
	
	//读取输入的字符 
	while(ch!=EOF)
	{
		if(ch<='9'&&ch>='0')//处理数字 
		{
			PushIntQueue(Qnum,ch-'0');
			ch=getchar();
			while(ch>='0'&&ch<='9')
			{
				PopIntQueue(Qnum,tempint);
				PushIntQueue(Qnum,tempint*10+ch-'0');
				ch=getchar();
			}
		}
		else if(ch=='-'||ch=='+'||ch=='/'||ch=='*')
		{
			PopIntQueue(Qnum,b);
			PopIntQueue(Qnum,a);
			
			if(ch=='+')
				tempint=a+b;
			else if(ch=='-')
				tempint=a-b;
			else if(ch=='/')
				tempint=a/b;
			else if(ch=='*')
				tempint=a*b%1000000007;
				
			PushIntQueue(Qnum,tempint);
		}
		
		else if(ch=='\n')
			break;
		ch=getchar();
		/*
		{
			tempint=ch-'0';
			ch=getchar();
			if(ch!=' ')
			{
				tempint=tempint*10+ch-'0';
				PushIntQueue(Qnum,tempint);
			}
			else if(ch==' ')
			{	
				PushIntQueue(Qnum,tempint);
			}
		}
		
		else if(ch==' ')//处理空格 
		{
			ch=getchar();
		}
		else if(ch=='-'||ch=='+'||ch=='/'||ch=='*')//处理符号 
		{
			tempchar=ch;
			
			PushCharQueue(Qchar,tempchar);
			ch=getchar(); 
		}
		*/
	}
	
	/*
	while(Qchar.front!=Qchar.rear)
	{
		PopIntQueue(Qnum,b);
		PopIntQueue(Qnum,a);
		PopCharQueue(Qchar,ch);
		if(ch=='+')
			PushIntQueue(Qnum,a+b);
		else if(ch=='-')
			PushIntQueue(Qnum,a-b);
		else if(ch=='/')
			PushIntQueue(Qnum,a/b);
		else if(ch=='*')
			PushIntQueue(Qnum,a*b);
	}

	PopIntQueue(Qnum,tempint);
	tempint=tempint%1000000007;
	*/
	printf("%lld", tempint);
	return 0;
}

//初始化 
Status IniCharQueue(LinkCharQueue &Q)
{
	Q.front=(QueueCharPtr)malloc(sizeof(QCharNode)*100);
	
	Q.rear=Q.front;
	Q.front->next=NULL;
	return OK;
}
Status IniIntQueue(LinkIntQueue &Q)
{
	Q.front=(QueueIntPtr)malloc(sizeof(QIntNode)*100);
	
	if(!Q.front)
		return ERROR;
		
	Q.rear=Q.front;
	Q.front->next=NULL;
	return OK;
}
//

//入队 
void PushCharQueue(LinkCharQueue &Q, char e)
{
	QueueCharPtr s;
	s=(QueueCharPtr)malloc(sizeof(QCharNode));
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}
void PushIntQueue(LinkIntQueue &Q, long long int e)
{
	QueueIntPtr s;
	s=(QueueIntPtr)malloc(sizeof(QIntNode));
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
}
//

//出队 
Status PopCharQueue(LinkCharQueue &Q, char &e)
{
	QueueCharPtr s;
	s=(QueueCharPtr)malloc(sizeof(QCharNode));
	if(Q.front==Q.rear)
		return ERROR;
	if(Q.front->next==Q.rear)
	{
		e=Q.rear->data;
		s=Q.rear;
		Q.rear=Q.front;
	}
	else
	{
		s=Q.front->next;
		e=s->data;
		Q.front->next=s->next;
	}
	
	free(s);
	return OK;
}
Status PopIntQueue(LinkIntQueue &Q,long long  int &e)
{
	QueueIntPtr s;
	s=(QueueIntPtr)malloc(sizeof(QIntNode));
	if(Q.front==Q.rear)
		return ERROR;
	if(Q.front->next==Q.rear)
	{
		e=Q.rear->data;
		s=Q.rear;
		Q.rear=Q.front;
	}
	else
	{
		s=Q.front->next;
		while(s->next !=Q.rear)
			s=s->next;
		QueueIntPtr temp=s;
		s=Q.rear;
		Q.rear=temp;
		
		e=s->data;
	}
	
	free(s);
	return OK;
}
//
