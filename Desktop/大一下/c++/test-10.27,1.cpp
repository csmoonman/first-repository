#include<iostream>
#include<string>
class A{
	//static const int month=4;
	enum{month=4};
	int m_a;
	double m_b;
	std::string m_c;
	int d[month];
public:
	explicit A(const std::string ,const int , const double );
	A();
	~A();
	void show() const;
	const A& top_a(const A& ) const;
}; 

 A::A(const std::string c,const int a,const double b)
{
	m_a=a;
	m_b=b;
	m_c=c;
}

A::A()
{
	m_a=11;
	m_b=11;
	m_c="default";
}

void A::show() const
{
	using std::cout;
	using std::endl;
	cout<<"hello "<<this->m_c<<","<<m_a<<m_b<<endl;
}

const A& A::top_a(const A& A2) const
{
	if(m_a>A2.m_a) return *this;
	
	return A2;
}

A::~A()
{
//	std::cout<<"bye "<<m_c<<std::endl;
}

int main()
{
	A A_[4]={
	A("first",1,1),
	A("second",2,2),
	A("third",3,3),
	};
	
	const A* top=&A_[0];
	for(int a=1;a<4;a++)
		top=&top->top_a(A_[a]);
		
	top->show();
}
