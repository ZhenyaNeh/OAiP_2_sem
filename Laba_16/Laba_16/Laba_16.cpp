#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

int partition(vector<int> arrayC2, int start, int end);
void quicksort(vector<int> arrayC2, int start, int end);

int main()
{
	srand(time(NULL));
	int sizeA{}, sizeB{}, sizeC{}, buffer{};
	cout << "Write SIZE array A: ";
	cin >> sizeA;
	cout << "Write SIZE array B: ";
	cin >> sizeB;
	vector<int> arrayA;
	vector<int> arrayB;

	cout << "\nArray-A\n";
	for(int i = 0; i < sizeA; i++ )
	{
		arrayA.push_back(rand() % 99 + 1);
		cout << " [ " << arrayA[i] << " ] ->";
	}
	cout << " END\n";

	cout << "\nArray-B\n";
	for(int i = 0; i < sizeB; i++ )
	{
		arrayB.push_back(rand() % 99 + 1);
		cout << " [ " << arrayB[i] << " ] ->";
	}
	cout << " END\n";


	if(sizeB % 2 == 0)
	{
		sizeC = (sizeA / 2) + (sizeB / 2);
	}
	if(sizeB % 2 != 0)
	{
		sizeC = (sizeA / 2) + (sizeB / 2) +1 ;
	}

	int maxSize{};
	if (sizeB > sizeA) 
	{
		maxSize = sizeB;
	}
	else
	{
		maxSize = sizeA;
	}

	vector<int> arrayC;
	vector<int> arrayC2;

	int count{};

	cout << "\nArray-C\n";
	for(int i = 0; i < maxSize; i++)
	{
		if ((i % 2) != 0 && count < sizeA) //четное 
		{
			count++;
			arrayC.push_back(arrayA.at(i));
			cout << " [ " << arrayC.at(count - 1) << " ] ->";		
		}
		if ((i % 2) == 0 && count < sizeB )//нечетное
		{
			count++;
			arrayC.push_back(arrayB.at(i));
			cout << " [ " << arrayC.at(count - 1) << " ] ->";
		}
	}
	cout << " END\n";

	arrayC2 = arrayC;

	cout << "\n\n\n//////////////// METOD BUBBLE... ////////////////\n\n\n";
	for (int i = 0; i < sizeC - 1; i++) {
		for (int j = 0; j < sizeC - i - 1; j++) {
			if (arrayC.at(j) < arrayC.at(j + 1)) {
				swap(arrayC.at(j), arrayC.at(j + 1));
			}
		}
	}
	int flag = 1;
	for (int i = 0; i < sizeC; i++) {
		if (flag != 13)
			cout << "\t[" << arrayC[i] << "]";
		if (flag == 13)
		{
			cout << "\t[" << arrayC[i] << "]\n\n";
			flag = 0;
		}
		flag++;
	}


	quicksort(arrayC2, 0, sizeC - 1);

	cout << "\n\n\n\t\t\t\t//////////////// METOD FAST... ////////////////\n\n\n";
	flag = 1;
	for (int i = 0; i < sizeC; i++) {
		if (flag != 13)
			cout << "\t[" << arrayC2[i] << "]";
		if (flag == 13)
		{
			cout << "\t[" << arrayC2[i] << "]\n\n";
			flag = 0;
		}
		flag++;
	}

	return 0;
}

int partition(vector<int> arrayC2, int start, int end)
{
	int pivot = arrayC2[end];
	int pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (arrayC2[i] <= pivot)
		{
			swap(arrayC2[i], arrayC2[pIndex]);
			pIndex++;
		}
	}

	swap(arrayC2[pIndex], arrayC2[end]);

	return pIndex;
}

void quicksort(vector<int> arrayC2, int start, int end)
{
	if (start >= end) {
		return;
	}

	int pivot = partition(arrayC2, start, end);

	quicksort(arrayC2, start, pivot - 1);
	quicksort(arrayC2, pivot + 1, end);
}