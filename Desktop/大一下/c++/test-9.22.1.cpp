#include<iostream>

struct struct_year
{
	int year;
};

typedef struct struct_year2
{
	int year;
}year1;

int main()
{
	using namespace std;
	struct_year s1,s2,s3;
	s1.year=2019;
	s2.year=2020;
	s3.year=2021;
	const struct_year* py[3]={&s1,&s2,&s3};
	cout<<py[0]->year<<" "<<py[1]->year<<" "<<py[2]->year;
	const struct_year**ppy  = py;
	cout<<endl;
	cout<<(*ppy)->year<<" ";
	cout<<(*(ppy+1))->year<<" ";
	
	struct_year2 s[3];
	s[1].year=2022;
	cout<<s[1].year<<endl;
	
	struct_year *prt=new struct_year[3];
	cin>>(*prt).year>>prt[1].year>>prt[2].year;
	for(int i=0;i<3;i++)
		cout<<(*(prt+i)).year<<" ";
	delete [] prt;
}
