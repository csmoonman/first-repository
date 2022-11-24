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
	cout<<"添加元素     /1："<<endl;
	cout<<"删除指定元素 /2："<<endl;
	cout<<"打印链表     /3："<<endl;
	cout<<"退出         /0："<<endl;
	cout<<"输入您的选择：";
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
			cout<<"输入有误！"; 
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
	else cout<<"创建失败!"<<endl;
	
	return L;
}

Linklist pop(Linklist &L)
{	
	struct LNode *ptr=new struct LNode;
	
	if(!ptr) cout<<"内存申请失败！"<<endl;
	else
	{
		string s;
		cout<<"输入成员name:";
		getline(cin,s);
		ptr->name=s;
		ptr->next=NULL;
		L.Rear->next=ptr;
		L.Rear=ptr;
		L.Rear->next=NULL;
		cout<<"添加成功！"<<endl; 
	}

	return L; 
}

Linklist deleteNode(Linklist &L)
{
	if(L.Head==L.Rear) cout<<"无元素可删！"<<endl;
	else if(L.Head->next==L.Rear)
	{
		string s;
		cout<<"输入您要删除的成员name：";
		getline(cin,s);
		
		if(s==L.Rear->name)
		{
			pNode ptr=L.Rear;
			L.Rear=L.Head;
			delete ptr;
			cout<<"删除成功"<<endl;
		}
		else cout<<"未能找到！"<<endl;
	}
	else
	{
		string s;
		cout<<"输入您要删除的成员name：";
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
				cout<<"删除成功！"<<endl;
			}
			else
			{
				ptrfront->next=ptrback->next;
				delete ptrback;
			}
		}
		else cout<<"未能找到！"<<endl;
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
	else cout<<"空"<<endl;
}
