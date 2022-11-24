#include<iostream> 
#include<string>
#include<cstdlib>
using namespace std;

typedef struct LNode
{
	string name;
	struct LNode* next;
}*pNode;

struct Linklist
{
	struct LNode* Head;
	struct LNode* Rear;
};

Linklist create(Linklist &L);
Linklist pop(Linklist &L);
Linklist deleteNode(Linklist &L);
void print(Linklist L);
void menu(Linklist& L);

int main()
{
	struct Linklist L;
	L=create(L);
	
	while(1)
	{
		menu(L);
	}
	
	return 0;
}

//main function 
void menu(Linklist& L)
{
	int key;
	cout<<"���Ԫ��     /1��"<<endl;
	cout<<"ɾ��ָ��Ԫ�� /2��"<<endl;
	cout<<"��ӡ����     /3��"<<endl;
	cout<<"�˳�         /0��"<<endl;
	cout<<"��������ѡ��";
	cin>>key;
	cin.get();
	switch(key)
	{
		case 1:
			L=pop(L);
			break;
		case 2:
			L=deleteNode(L);
			break;
		case 3:
			print(L);
			break;
		case 0:
			exit(0);
			break;
		default:
			cout<<"��������"; 
	}
	for(int i=0;i<2000000000;i++);
	system("cls");
}

//basic function
Linklist create(Linklist &L)
{
	L.Head=new struct LNode;
	if(L.Head) 
	{
		L.Head->next=NULL;
		L.Rear=L.Head;
	}
	else cout<<"����ʧ��!"<<endl;
	
	return L;
}

Linklist pop(Linklist &L)
{	
	struct LNode *ptr=new struct LNode;
	
	if(!ptr) cout<<"�ڴ�����ʧ�ܣ�"<<endl;
	else
	{
		string s;
		cout<<"�����Աname:";
		getline(cin,s);
		ptr->name=s;
		ptr->next=NULL;
		L.Rear->next=ptr;
		L.Rear=ptr;
		L.Rear->next=NULL;
		cout<<"��ӳɹ���"<<endl; 
	}

	return L; 
}

Linklist deleteNode(Linklist &L)
{
	if(L.Head==L.Rear) cout<<"��Ԫ�ؿ�ɾ��"<<endl;
	else if(L.Head->next==L.Rear)
	{
		string s;
		cout<<"������Ҫɾ���ĳ�Աname��";
		getline(cin,s);
		
		if(s==L.Rear->name)
		{
			pNode ptr=L.Rear;
			L.Rear=L.Head;
			delete ptr;
			cout<<"ɾ���ɹ�"<<endl;
		}
		else cout<<"δ���ҵ���"<<endl;
	}
	else
	{
		string s;
		cout<<"������Ҫɾ���ĳ�Աname��";
		getline(cin,s);
		pNode ptrfront=L.Head;
		pNode ptrback=ptrfront->next;	
		while(ptrback->name!=s)
		{
			ptrback=ptrback->next;
			ptrfront=ptrfront->next;
		}
		
		if(ptrback!=NULL)
		{
			if(ptrback->next==NULL)
			{
				L.Rear=ptrfront;
				ptrfront->next=NULL;
				delete ptrback;
				cout<<"ɾ���ɹ���"<<endl;
			}
			else
			{
				ptrfront->next=ptrback->next;
				delete ptrback;
			}
		}
		else cout<<"δ���ҵ���"<<endl;
	}
	
	return L;
}
void print(Linklist L)
{
	if(L.Head!=L.Rear)
	{
		pNode ptr=L.Head->next;
		while(ptr!=NULL)
		{
			cout<<ptr->name<<" ";
			ptr=ptr->next;	
		}
		cout<<endl;
	}
	else cout<<"��"<<endl;
}
