#include<iostream>
#include<vector>
#include<ctime>

/*Ввести массивы А и В. В массив С перенести четные элементы массива А и нечетные элемента массива 
В. Массив С отсортировать по убыванию, используя алгоритмы сортировок: «пузырек», сортировка Хоара. */

using namespace std;

int partition(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);

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
	for (int i = 0; i < sizeA; i++)
	{
		arrayA.push_back(rand() % 99 + 1);
		cout << " [ " << arrayA[i] << " ] ->";
	}
	cout << " END\n";

	cout << "\nArray-B\n";
	for (int i = 0; i < sizeB; i++)
	{
		arrayB.push_back(rand() % 99 + 1);
		cout << " [ " << arrayB[i] << " ] ->";
	}
	cout << " END\n";


	if (sizeB % 2 == 0)
	{
		sizeC = (sizeA / 2) + (sizeB / 2);
	}
	if (sizeB % 2 != 0)
	{
		sizeC = (sizeA / 2) + (sizeB / 2) + 1;
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
	for (int i = 0; i < maxSize; i++)
	{
		if ((i % 2) != 0 && count < sizeA) //четное 
		{
			count++;
			arrayC.push_back(arrayA.at(i));
			cout << " [ " << arrayC.at(count - 1) << " ] ->";
		}
		if ((i % 2) == 0 && count < sizeB)//нечетное
		{
			count++;
			arrayC.push_back(arrayB.at(i));
			cout << " [ " << arrayC.at(count - 1) << " ] ->";
		}
	}
	cout << " END\n";

	arrayC2 = arrayC;

	clock_t start{ clock() };
	cout << "\n\n\n\t\t\t\t//////////////// METOD BUBBLE... ////////////////\n\n\n";
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

	clock_t end{ clock() };
	double time_spent_sec{ (double)(end - start) / CLOCKS_PER_SEC };
	cout << "\n\n\tTime: \n\t" << time_spent_sec << "sec\n\n\n";

	clock_t start1{ clock() };
	quickSort(arrayC2, 0, sizeC - 1);
	

	cout << "\n\n\n\t\t\t\t//////////////// METOD FAST (HOARA)... ////////////////\n\n\n";
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
	clock_t end1{ clock() };
	double time_spent_sec1{ (double)(end1 - start1) / CLOCKS_PER_SEC };
	cout << "\n\n\tTime: \n\t" << time_spent_sec1 << "sec\n\n\n";
	return 0;
}

int partition(vector<int>& arr, int low, int high) {
	int pivot = arr[(low + high) / 2]; // выбор опорного элемента (pivot)
	while (low <= high) {
		// поиск элементов, которые нужно поменять местами
		while (arr[low] > pivot) {
			low++;
		}
		while (arr[high] < pivot) {
			high--;
		}
		if (low <= high) {
			swap(arr[low], arr[high]); // обмен элементов
			low++;
			high--;
		}
	}
	return low;
}

// функция быстрой сортировки
void quickSort(vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high); // разделение массива
		quickSort(arr, low, pivotIndex - 1); // рекурсивная сортировка левой части массива
		quickSort(arr, pivotIndex, high); // рекурсивная сортировка правой части массива
	}
}