#include<iostream>

using namespace std;

double sum(int, double, int);

void main()
{
	setlocale(LC_ALL, "ru");
	int numb{}, x{};
	double Y{};
	cout << "Enter the N: ";

	while (true)
	{
		cin >> numb;
		if (!cin || numb < 0)
		{
			cerr << "Error!!!\n";
			cout << "Please, try again...\n";
			continue;
		}
		break;
	}

	cout << "Enter the X: ";
	while (true)
	{
		cin >> x;
		if (!cin || x < 0)
		{
			cerr << "Error!!!\n";
			cout << "Please, try again...\n";
			continue;
		}
		break;
	}

	Y = sum(numb, Y, x);
	cout << Y;
}

double sum(int numb, double Y, int x)
{

	Y += sin(numb * x);
	numb--;
	if (numb != 0)
		return sum(numb, Y, x);
	else
		return Y;
}