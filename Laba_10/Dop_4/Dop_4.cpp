#include <iostream>
using namespace std;

char getSymbolAtN(int n) 
{
	if (n <= 26)
		return 'A' + n - 1;
	
	else {
		n = n % 26;
		getSymbolAtN(n);
	}
}

int main() {
	int n;
	cout << "Enter the N: ";
	cin >> n;
	cout << getSymbolAtN(n);
	return 0;
}