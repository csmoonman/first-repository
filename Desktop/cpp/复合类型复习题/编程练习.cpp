#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

/* 1:
int main()
{
	vector<string> s(4);
	char grade;
	cout << "what is your first name? ";
	getline(cin,s[1]);
	cout << endl << "what is your last name? ";
	getline(cin, s[0]);
	cout << endl << "what letter grade do you deserve? ";
	grade = cin.get();
	cin.get();
	cout << endl << "what is your age? ";
	getline(cin, s[3]);

	cout << "Name: " << s[0] << "," << s[1] << endl;
	cout << "Grade: " << (char)(grade+1) << endl;
	cout << "Age: " << s[3] << endl;
}
*/

/* 3¡¢4
int main()
{
	char firstname[20];
	char lastname[42];
	string firststring;
	string laststring;
	cout << "Enter your first name:";
	cin.getline(firstname, 20);
	cout << "Enter you last name:";
	cin.getline(lastname, 20);
	strncat(lastname, ", ",22);
	strncat(lastname, firstname,20);
	cout << endl << lastname << endl;
	firststring = firstname;
	laststring = lastname;
	cout << firststring + ", " + laststring<<endl;
}
*/


/* 5¡¢6¡¢9
struct candyBar
{
	char brand[20];
	double weight;
	int calorie;
};
int main()
{
	candyBar snack = { "Mocha Munch",2.3,350 };
	cout << snack.brand << "   " << snack.weight << "   " << snack.calorie << endl;
	candyBar Mycandy[3] = {
		{"Big",2.3,333},
		{"big",2.3,444},
		{"dick",2.3,555}
	};
	for (int i = 0; i < 3; i++)
	{
		cout << Mycandy[i].brand << "   " << Mycandy[i].weight << "   " << Mycandy[i].calorie << endl;
	}

	//9
	candyBar* Yourcandy= new candyBar[3];
	for (int i = 0; i < 3; i++)
	{
		Yourcandy[i].weight = 13.3;
		Yourcandy[i].calorie = 111;
	}
	strncpy(Yourcandy[0].brand, "My", 20);
	strncpy(((Yourcandy+1))->brand, "Big", 20);
	strncpy((*(Yourcandy + 2)).brand, "Dick", 20);

	for (int i = 0; i < 3; i++)
		cout << Yourcandy[i].brand << "   " << Yourcandy[i].weight << "   " << Yourcandy[i].calorie << endl;

	delete[] Yourcandy;
	return 0;
}
*/






