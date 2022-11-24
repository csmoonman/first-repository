#include"vect.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double diretion;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distant (q to quit): ";
	while (cin >> target)
	{

		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		int N;
		int max = 0;
		int min = 99999;
		int sumsteps = 0;
		cout << "How mant do you want to try : ";
		(cin >> N).get();
		for (int i = 0; i < N; i++)
		{
			while (result.magval() < target)
			{
				diretion = rand() % 360;
				step.reset(dstep, diretion, Vector::POL);
				result = result + step;
				steps++;
			}
			if (max < steps) max = steps;
			if (min > steps) min = steps;
			sumsteps += steps;
			
			cout << "After " << steps << " steps, the subject has the following location:\n";
			cout << result << endl;
			result.polar_mode();
			cout << "or\n" << result << endl;
			cout << "Average outward distance per step = " << result.magval() / steps << endl;
			steps = 0;
			result.reset(0.0, 0.0);
		}
		ofstream fout;
		fout.open("vector.txt");
		if (!fout.is_open())
		{
			cout << "Cant open this txt!\n";
			break;
		}
		fout << "max steps : " << max << " ,  min steps : " << min << endl;
		fout << "average steps : " << sumsteps / (N * 1.0);
		fout.close();
		
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}