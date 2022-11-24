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
		cout<<"输入第"<<i<<"科成绩(回车结束)" <<endl;
		cin>>grade;
		cin.get();
		cout<<"输入第"<<i<<"科学分(回车结束)" <<endl;
		cin>>cen;
		cin.get();
		sumcen+=cen;
		sumgra+= (cen*grade);
		cout<<"是否继续键入？  1/0"<<endl; 
		cin>>flag;
		cin.get();
		if(flag==0) break;
		i++;
	}
	
	cout<<"各科成绩*学分 之和："<<sumgra<<endl;
	cout<<"总学分："<<sumcen<<endl;
	cout<<"综测："<<sumgra/sumcen<<endl; 
	return 0;
}
