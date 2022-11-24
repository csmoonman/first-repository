#include<iostream>

using std::cout;
using std::endl;
using namespace std;
bool is_little_endian();

int main()
{
	cout<<is_little_endian();
}

bool is_little_endian()
{
	int x=0x12345678;
	unsigned char* ptr;
	int size=sizeof(x);
	ptr=(unsigned char*)&x;

	//printf("%.2x %.2x",ptr[0],ptr[1]);
	//cout<<hex<<x<<endl<<ptr[0]<<endl<<ptr[1]<<endl;
	if(ptr[0]>ptr[1]) return 1;
	else return 1;
}
