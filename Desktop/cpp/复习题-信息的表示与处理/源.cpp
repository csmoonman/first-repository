#include<iostream>

using namespace std;

bool is_little_endian();

int main()
{
	int size_n = sizeof (int);
	int x, y;
	int minX,maxY=0;
	int sum = 0;
	cin >> x >> y;
	cin.get();
	unsigned char* px = (unsigned char*)&x;
	unsigned char* py = (unsigned char*)&y;
	
	if (is_little_endian())
	{
		minX = (int) (px[0]);
		for (int i = size_n-1; i > 0; i--)
		{
			maxY = maxY<<8 + (int)(py[i]);
			cout << py[i] << endl;
		}
		sum = maxY << 8 + minX;
	}
	else
	{
		minX = px[size_n - 1];
		for (int i = 1; i < size_n; i++)
		{
			maxY = maxY << 8 + py[i];
		}
		sum = maxY << 8 + minX;
	}
	cout << hex << sum;
}

bool is_little_endian()
{
	int x = 0x12345678;
	unsigned char* ptr;
	int size = sizeof(x);
	ptr = (unsigned char*)&x;

	//printf("%.2x %.2x",ptr[0],ptr[1]);
	//cout<<hex<<x<<endl<<ptr[0]<<endl<<ptr[1]<<endl;
	if (ptr[0] > ptr[1]) return 1;
	else return 1;
}