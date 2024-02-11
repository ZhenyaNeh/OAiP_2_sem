#include<iostream>
#include<vector>
#include<ctime>

/*Ввести массив А, в массив В скопировать все элементы массива А, имеющие четное значение. 
Массив В от-сортировать по возрастанию, используя алгоритмы сортировок: сортировка Шелла, сортировка выбором.*/

using namespace std;

int main()
{
	srand(time(NULL));
	int sizeA{}, sizeB{}, buffer{};
	cout << "Write SIZE array A: ";
	cin >> sizeA;
	vector<int> arrayA;
	vector<int> arrayB;

	cout << "\nArray-A\n";
	for (int i = 0; i < sizeA; i++)
	{
		arrayA.push_back(rand() % 99 + 1);
		cout << " [ " << arrayA[i] << " ] ->";
	}
	cout << " END\n";

	cout << "\nArray-B\n";
	for (int i = 0; i < sizeA; i++)
	{
		if((arrayA[i] % 2) == 0)
		{
			sizeB++;
			arrayB.push_back(arrayA[i]);
			cout << " [ " << arrayB[sizeB - 1] << " ] ->";
		}
	}
	cout << " END\n";

	vector<int> arrayB2;

	arrayB2 = arrayB;

	cout << "\n\n\n\t\t\t\t//////////////// METOD SHELLL... ////////////////\n\n\n";
	for (int step = sizeB / 2; step > 0; step /= 2)
	{
		for (int i = step; i < sizeB; i++)
		{
			for (int j = i; j >= step; j -= step) {
				if (arrayB2[j] < arrayB2[j - step]) {
					swap(arrayB2[j], arrayB2[j - step]);
				}
			}
		}
	}
	int flag = 1;
	for (int i = 0; i < sizeB; i++) {
		if (flag != 13)
			cout << "\t[" << arrayB2[i] << "]";
		if (flag == 13)
		{
			cout << "\t[" << arrayB2[i] << "]\n\n";
			flag = 0;
		}
		flag++;
	}


	cout << "\n\n\n\t\t\t\t//////////////// METOD COICE... ////////////////\n\n\n";
	int min;
	for (int i = 0; i < sizeB; i++)
	{
		min = i;
		for (int j = i + 1; j < sizeB; j++)
			if (arrayB[min] > arrayB[j])
				min = j;

		if (i != min) {
			swap(arrayB[i], arrayB[min]);
		}
	}
	flag = 1;
	for (int i = 0; i < sizeB; i++) {
		if (flag != 13)
			cout << "\t[" << arrayB[i] << "]";
		if (flag == 13)
		{
			cout << "\t[" << arrayB[i] << "]\n\n";
			flag = 0;
		}
		flag++;
	}

	return 0;
}