#include<iostream>

using namespace std;

typedef struct Link
{
	int data;
}*Linklist;

typedef struct LinkHead
{
	Linklist Head;
	Linklist rear;
};

Link* creatlist(LinkHead &L);
void add(Linklist &L,int n);
bool isPrime(int n);

int main()
{
	LinkHead L;
	L.Head = creatlist(L);
	int N;
	cin >> N;
	if(N>=2) add()
	for (int i = 3; i <= sqrt(N); i += 2)
	{
		if (isPrime(i)) add(L.rear, i);
	}
	return 0;
}

Link* creatlist(LinkHead& L)
{

}

void add(Linklist& L,int n)
{

}

bool isPrime(int n)
{

}