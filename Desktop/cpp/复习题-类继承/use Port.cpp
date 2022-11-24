#include<iostream>
#include"Port.h"

using namespace std;

int main()
{
	Port p1 = Port("p1", "p1", 20);
	VintagePort p2 = VintagePort("p2", 30, "Old", 2022);
	Port* ppd[2] = { &p1,&p2 };

	cout << "use p1 and p2 to show : \n";
	p1.show();
	cout << endl;
	p2.show();
	cout << endl;

	cout << "use ppd to show: \n";
	ppd[0]->show();
	cout << endl;
	ppd[1]->show();
	cout << endl;

	cout << "p1 and p2 use operator<< :" << endl;
	cout << p1 << endl << p2 << endl;
	cout << "ppd use operator<<: " << endl;
	cout << *ppd[0] << endl << *ppd[1] << endl;

	p1 += 2;
	p1 -= 13;
	cout << p1;
}