#include<iostream>

using namespace std;

int sum(int, int);
int minys(int, int);
int multiplice(int, int);
int power(int, int);

void main()
{
	setlocale(LC_ALL, "ru");
	int numb_N{}, numb_M{};
	cout << "Enter the N: ";

	while (true)
	{
		cin >> numb_N;
		if (!cin || numb_N < 0)
		{
			cerr << "Error!!!\n";
			cout << "Please, try again...\n";
			continue;
		}
		break;
	}

	cout << "Enter the M: ";
	while (true)
	{
		cin >> numb_M;
		if (!cin || numb_M < 0)
		{
			cerr << "Error!!!\n";
			cout << "Please, try again...\n";
			continue;
		}
		break;
	}

	cout << "\nPlus N and M:\n";
	int N{ numb_N }, M{ numb_M };
	sum(N, M);

	cout << "\nMinus N and M:\n";
	N = numb_N ;
	M = numb_M ;
	minys(N, M);

	cout << "\nMinus N and M:\n";
	N = numb_N;
	M = numb_M;
	multiplice(N, M);

	cout << "\nMinus N and M:\n";
	N = numb_N;
	M = numb_M;
	power(N, M);
}

int sum(int N, int M)
{
	cout << N << " + " << M << " = " << N + M << "\n";
	N++;
	M--;
	if (M > 0)
		sum(N, M);
	else
		return 0;
}

int minys(int N, int M)
{
	cout << N << " - " << M << " = " << N - M << "\n";
	N++;
	M--;
	if (M > 0)
		minys(N, M);
	else
		return 0;
}

int multiplice(int N, int M)
{
	cout << N << " * " << M << " = " << N * M << "\n";
	N++;
	M--;
	if (M > 0)
		multiplice(N, M);
	else
		return 0;
}

int power(int N, int M)
{
	cout << N << " ^ " << M << " = " << pow(N, M) << "\n";
	N++;
	M--;
	if (M > 0)
		power(N, M);
	else
		return 0;
}