#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define ERROR 0
#define OK 1

//��������Ĵ洢�ṹ
typedef struct LuggageNode 
{
	int num;//������
	char Flight[12];//����� 
	char name[10];//���� 
	char ID[18];//�ο����֤ 
	char status[15];//����״ֵ̬1������ȡ��0����δȡ -1����δ���� 
	LuggageNode* next; 
}LNode,*LNodePtr; 

typedef struct LuggageList
{
	LNodePtr head;
	LNodePtr rear;
}Llist;

typedef int Status;

//������Ĳ��� 
Status  iniList(Llist &L);
void printList(Llist L);//��ӡ�� 

//���ܲ� 
Status deposit(Llist &L,int &num);//�������� ��Ҳ�������ο���Ϣ 
Status takeOut(Llist L,char ID[18]);//ȡ������ 

int main()
{
	Llist L;
	int cnt=1;
	int n;
	char ID[18];
	iniList(L);
	while(1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf("\t\t\t***��ӭʹ��������ȡ����ϵͳ��***\n");
		printf("\t\t\t***--------------------------***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***       1---��������       ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***       2---ȡ������       ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***   3---��ӡĿǰ����״̬   ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t***       0---�˳�ϵͳ       ***\n");
		printf("\t\t\t***                          ***\n");
		printf("\t\t\t        �������Ӧ��ţ�       \n");
		scanf("%d", &n);
		printf("\t\t\t���ڴ���...\n");
		Sleep(500);
		system("cls");
		switch(n)
		{
			case 1:
				deposit(L,cnt);
				break;
			case 2:
				printf("\n\n\n\n");
				printf("\t\t\t�������������֤���룺");
				scanf("%s", ID);
				takeOut(L,ID);
				break;
			case 3:
				printList(L);
				break;
			case 0:
				return OK;
			default:
				printf("\n\n\n\n");
				printf("\t\t\t�������"); 
				system("pause"); 
				break;
		}
	}
	return 0;
} 

//������Ĳ��� 
Status  iniList(Llist &L)
{
	/*ͷ���δ�洢��Ϣ*/
	L.head=(LNodePtr)malloc(sizeof(LNode));
	//δ�ɹ�����ERROR 
	if(!L.head)
		return ERROR;
	L.head->next=NULL;
	L.rear=L.head;
	
	return OK;//��ʼ��� 
}

void printList(Llist L)//��ӡ�� 
{
	system("cls");
	if(L.head->next==NULL)
	{
		printf("\n\n\n\n");
		printf("\t\t\t��δ���������ˣ�\n");
		system("pause");
		return;
	}
	LNodePtr p=L.head->next;
	printf("\n\n\n\n");
	printf("\t\t\t������  �����  ����      ���֤��      ����״̬"); 
	while(p)
	{
		printf("\n");
		printf("\t\t\t%.3d      %s   %s %s    %s\n", p->num, p->Flight, p->name, p->ID, p->status);
		p=p->next;
	}
	system("pause");
}

//���ܲ� 
Status deposit(Llist &L,int &num)//�������� 
{
	LNodePtr p=(LNodePtr)malloc(sizeof(LNode));
	p->next=NULL; 
	p->num=num;
	num++;
	strcpy(p->status,"Unarrival");
	printf("\n\n\n\n");
	printf("\t\t\t���������ĺ����Σ�");
	printf("\n"); 
	printf("\t\t\t");
	scanf("%s" ,p->Flight);
	printf("\t\t\t����������������");
	printf("\n");
	printf("\t\t\t");
	scanf("%s", p->name);
	printf("\t\t\t�������������֤��");
	printf("\n");
	printf("\t\t\t");
	scanf("%s", p->ID);	
	printf("\t\t\t�Ѱ������ˣ�\n");
	system("pause");
	L.rear->next=p;
	L.rear=p;
	L.rear->next=NULL;
	
	return OK;
}

Status takeOut(Llist L,char ID[18])//ȡ������ 
{
	LNodePtr p;

	p=L.head->next;
	char ch;
	char t;
	//��� 
	if(L.head==L.rear)
	{
		printf("\t\t\t��δ����������!\n");
		system("pause");
		return ERROR;
	}
	//������ѯ 
	while(p)
	{
		if(strcmp(ID,p->ID)==0)
		{
			strcpy(p->status,"NotTakenOut");//�ѵ�����Ϊδȡ 
			printf("\n\n\n\n");
			printf("\t\t\t������:%.3d\n\t\t\t����ࣺ%s\n\t\t\t������%s\n\t\t\t���֤���룺%s\n\t\t\t����״̬��%s\n", p->num, p->Flight, p->name, p->ID, p->status);
			system("pause");
			break;
		}
		else
			p=p->next;
	}
	
	if(L.rear->next==p)
	{
		printf("\n\n\n\n");
		printf("δ��ѯ������������Ϣ��\n");
		system("pause");
		return ERROR;
	}

	printf("\t\t\t�Ƿ�ȡ����Y/N:");
	while ((t = getchar()) != '\n' && t != EOF);//������棡��������Ҫ 
	scanf("%c",&ch);

	system("pause");
	printf("\n");
	if(ch=='Y'||ch=='y')
	{
		strcpy(p->status,"TakenOut");//���Ϊ��ȡ�� 
		printf("\t\t\t��ȡ����\n");
		printf("\t\t\t������:%.3d\n\t\t\t����ࣺ%s\n\t\t\t������%s\n\t\t\t���֤���룺%s\n\t\t\t����״̬��%s\n", p->num, p->Flight, p->name, p->ID, p->status);
		system("pause");	
	}
	return OK;
}

