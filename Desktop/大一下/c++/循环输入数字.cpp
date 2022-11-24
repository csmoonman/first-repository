#include<iostream>

int main()
{
	using namespace std;
	int grades[5];
	cout<<"enter the grade,must enter 5 rounds"<<endl;
	int i=0;
	// 输满结束 
	for(i=0;i<5;i++)
	{
		if(i<5)
			cout<<"#"<<i+1<<endl;
		while(!(cin>>grades[i]))
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"please enter a number!"<<endl;	
		}
	}
	for(i=0;i<5;i++)
		cout<<grades[i]<<" ";
	
		
	/*以指定字符结束 
	while(i<5&&cin>>grades[i])
	{
		cout<<++i<<"rounds"<<endl;
	}
	
	for(i=i-1;i>=0;i--)
		cout<<grades[i]<<" ";
	*/
}
