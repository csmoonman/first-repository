#include<iostream>
#include<string>
#include<math.h>
using namespace std;

string BaseConversion(string original, int OBase, int TBase);
bool Check(string original,int OBase);

int main()
{
	while(1)
	{
		int flag;
		string original,o;
		int OBase, TBase;
		cout<<"������Ҫת��������,�س��Խ�����" <<endl;
		cin>>original;
		//����������ԭֵ 
		o=original;
		
		cout<<"����ԭ���ƺ�Ŀ�����(�Կո����)���س��Խ�����";
		(cin>>OBase>>TBase).get();
		
		//���������Ƿ�Ϸ� 
		if(Check(original,OBase)) 
		{
			cout<<TBase<<"������ԭ����Ϊ��"<<BaseConversion(original,OBase,TBase)<<endl;
			cout<<"�Ƿ����ʹ�ã�1/0" <<endl; 
		}
		else	
			cout<<"�������������Ƿ��������룿 1/0"<<endl; 
			
		cin>>flag;
		getchar(); 
		if(flag==0)
		{
			cout<<"��лʹ�ã�";
			break; 
		}
		else system("cls");
	}
}

string BaseConversion(string original, int OBase, int TBase)
{
	string o;
	int r,d=TBase;
	int n=original.size();//λ��
	long long Intor=(long long) original; 
	if(OBase==10)
	{
		int cnt=1;
		int sum=0;
		while(Intor!=0)
		{
			r=Intor%d;
			Intor=Intor/d;
			o=(char)r
			cnt++;
		}
		return sum;
	}
	else if()
	{
		int n=original,sum=0,cnt=0;
		while(n)
		{
			sum=sum+n%(int)pow(10,1)*pow(OBase,cnt);
			cnt++;
			n/=10;
		}
		return BaseConversion(sum,10,TBase);
	}
}

bool Check(string original,int OBase)
{
	string o=original;
	char BaseCh;
	switch(OBase)
	{
		case 1:BaseCh=='1';
		case 2:BaseCh=='2';
		case 3:BaseCh=='3';
		case 4:BaseCh=='4';
		case 5:BaseCh=='5';
		case 6:BaseCh=='6';
		case 7:BaseCh=='7';
		case 8:BaseCh=='8';
		case 9:BaseCh=='9';
		case 10:BaseCh=='a';
		case 11:BaseCh=='b';
		case 12:BaseCh=='c';
		case 13:BaseCh=='d';
		case 14:BaseCh=='e';
		case 15:BaseCh=='f';
		case 16:BaseCh=='g';
		case 17:BaseCh=='h';
		case 18:BaseCh=='i';
		case 19:BaseCh=='j';
		case 20:BaseCh=='k';
		case 21:BaseCh=='l';
		case 22:BaseCh=='m';
		case 23:BaseCh=='n';
		case 24:BaseCh=='o';
		case 25:BaseCh=='p';
		case 26:BaseCh=='q';
		case 27:BaseCh=='r';
		case 28:BaseCh=='s';
		case 29:BaseCh=='t';
		case 30:BaseCh=='u';
		case 31:BaseCh=='v';
	}
	int n=o.size();//n ��λ�� 
	
	for(int i=0;i<n;i++)
		if(o[i]>=BaseCh) return false;
		
	return true;
}
