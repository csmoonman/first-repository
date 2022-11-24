#include<new>
#include<iostream>
#pragma warning (disable:4996)

int buffin[100];
struct chaff
{
	char dross[20];
	int slag;
};
int main()
{
	chaff* chaff1 = new(buffin) chaff;
	chaff* chaff2 = new chaff;
	strcpy(chaff1->dross, "first");
	strcpy(chaff2->dross, "second");
	chaff1->slag = 1;
	chaff2->slag = 2;

	using namespace std;
	cout << "buffin : " << (void*)buffin << endl;
	int i = 0;
	while (chaff1->dross[i])
	{
		cout << "chaff1[" << i << "] : " << chaff1->dross[i] << " at : " << (void*)(chaff1->dross[i]) << endl;
		i++;
	}
	i = 0;
	while (chaff2->dross[i])
	{
		cout << "chaff2[" << i << "] : " << chaff2->dross[i] << " at : " << (void*)(chaff2->dross[i]) << endl;;
		i++;
	}
}