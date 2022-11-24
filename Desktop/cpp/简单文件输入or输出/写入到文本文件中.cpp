#include<iostream>
#include<fstream>
#include<cstdlib>

int main()
{
	using namespace std;

	//写入
	/*
	ofstream outFile;
	ofstream fout;

	outFile.open("test.txt");
	fout.open("price");
	char brand[30];
	double a_price,d_price;
	cin.getline(brand, 30);
	(cin >> a_price).get();
	d_price = a_price * 0.53;

	outFile << fixed;
	outFile.precision(3);
	outFile << "brand:" << brand<<endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;
	*/

	//读取文件
	/*
	ifstream inFile;
	ifstream fcin;
	char filename[50];
	char text[50];
	cout << "enter the file name you want:";
	cin.getline(filename, 50);
	inFile.open(filename);
	if (inFile.eof())
		cout << "End of file reached!" << endl;
	else if (inFile.fail())
		cout << "Input terminated by data mismatch!" << endl;
	else
		cout << "Input terminated for unknown reason!" << endl;
	if (!inFile.is_open())
		exit(EXIT_FAILURE);
	while (inFile.getline(text, 50))
		cout << text << endl;
		*/
}