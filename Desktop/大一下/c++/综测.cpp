#include<iostream>

int main()
{
	using namespace std;
	
	double sumgra=0,sumcen=0; 
	while(1)
	{
		static int i=1;
		int flag;
		double grade;
		double cen;
		double factor;
		cout<<"�����"<<i<<"�Ƴɼ�(�س�����)" <<endl;
		cin>>grade;
		cin.get();
		cout<<"�����"<<i<<"��ѧ��(�س�����)" <<endl;
		cin>>cen;
		cin.get();
		sumcen+=cen;
		sumgra+= (cen*grade);
		cout<<"�Ƿ�������룿  1/0"<<endl; 
		cin>>flag;
		cin.get();
		if(flag==0) break;
		i++;
	}
	
	cout<<"���Ƴɼ�*ѧ�� ֮�ͣ�"<<sumgra<<endl;
	cout<<"��ѧ�֣�"<<sumcen<<endl;
	cout<<"�۲⣺"<<sumgra/sumcen<<endl; 
	return 0;
}
