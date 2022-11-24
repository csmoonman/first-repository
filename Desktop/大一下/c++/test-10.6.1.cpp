#include<iostream>

template <typename T>
void Swap(T& a,T&b);

struct job
{
	char name[20];
	double salary;
	int age;
};

template <>void Swap<job>(job &j1,job& j2);
//void Swap(job&j1 ,job &j2);

int main()
{
	int a,b;
	a=1,b=2;
	Swap(a,b);
	std::cout<<a<<" "<<b<<std::endl;
	
	//use Swap(char& a,char& b);
	char x='a';
	char y='A';
	Swap(x,y);
	std::cout<<x<<" "<<y<<std::endl;
	
	job li={"lilei",1000.2,20};
	job wang={"wangxuefu",1021.3,23};
	Swap(li,wang);
	std::cout<<li.name<<" "<<li.salary<<" "<<li.age<<std::endl;
 	std::cout<<wang.name<<" "<<wang.salary<<" "<<wang.age<<std::endl;
 }
  
template <typename T>
void Swap(T& a,T &b)
{
	T temp=a;
	a=b;
	b=temp;
}

template<> void Swap(job& j1,job& j2)
{
	Swap(j1.salary,j2.salary);
	Swap(j1.age,j2.age);
}


