#include<iostream>

using namespace std;

int main()
{
	int a[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 5; j++)
		{
			cout << a[i][j] << " ";
			if (j == 4) cout << endl;
		}

	return 0;
}