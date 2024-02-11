#include<iostream>
#include<ctime>

using namespace std;
//var 12
int negativeElements(int *randomArray, int SIZE);

int negativeElements(int* randomArray,int SIZE)
{
	bool check = true;
	for (int i = 0; i < SIZE; i++)
	{
		if (randomArray[i] < 0) {
			check = false;
			cout << "Array hase negativ velue...\n";
			break;
		}
	}
	if (check)
		return 0;
	if (!check)
		return 1;
}
int min(int count, ...)
{
	int SIZE = count;
	int* value = &count;
	int sumBit = 2;
	int* randomArray = new int[SIZE];
	int* myArray = new int[SIZE];
	cout << "ARRAY:\n";
	for (int i = 0; i < count; i++) {
		value += 2;
		randomArray[i] = *value;
		myArray[i] = randomArray[i];
		cout << randomArray[i] << "\n";
	}
	cout << "\n";
	if (negativeElements(randomArray, SIZE) == 1) {
		for (int i = 0; i < SIZE; i++) {
			if (*(randomArray + i) < 0) {

				for (int j = i; j < SIZE; j++)
					*(randomArray + j) = *(myArray + j + 1);
				*(randomArray + SIZE - 1) = 0;
				for (int k = 0; k < SIZE; k++)
					*(myArray + k) = *(randomArray + k);
				i--;
			}
		}
		cout << "New array: \n";
		for (int i = 0; i < SIZE; i++)
			cout << *(randomArray + i) << "\n";
		cout << "\n";
	}
	else
		cout << "Array dont hase negativ velue...\n\n";
	return 0;
}
void main()
{
	min(5, 1, -3, -7, 9, 6);
	min(6, 3, 7, 9, 6, 2, 4);
	min(7, 3, 7, -9, -6, -2, 9, 8);
}

/*начало negativeElements
	инициализируем булевую переменную check и присваеваем ей true
	начало массива 
		условие  i = 0; i < SIZE; i++
		если randomArray[i] < 0
			переменной check присваеваем false
			выводим Array hase negativ velue...
			выходим из цмкла

	конец цикла
	если check равен true
		возвращаем 0
	если check равен false
		возвращаем 0
конец*/

/* начало
	инициализируем SIZE присваеваем count
	инициализируем* value присваеваем  &count
	инициализируем sumBit присваеваем  2
	инициализируем* randomArray присваеваем  new int[SIZE];
	инициализируем* myArray присваеваем  new int[SIZE]
	выводим ARRAY
	начало цикла i = 0; i < count; i++
		value прибавляем 2
		randomArray[i] присваеваем   *value
		myArray[i] присваеваем   randomArray[i]
		выводим randomArray[i]
	

	если negativeElements(randomArray, SIZE) == 1
		начало цикла 
			условие i = 0; i < SIZE; i++
			если *(randomArray + i) < 0

				начало цикла 
					условие j = i; j < SIZE; j++
					переменной *(randomArray + j) присваеваем *(myArray + j + 1)
				переменной *(randomArray + SIZE - 1 присваеваем 0
				начало цикла
					условие k = 0; k < SIZE; k++
					переменной *(myArray + k) присваеваем  *(randomArray + k)
				уменьшаем I на 1
		выводим New array:
		начало цикла
			условие i = 0; i < SIZE; i++
			вывод *(randomArray + i) 

	иначе
		выводи Array dont hase negativ velue...
	возвращаем 0
	
конец*/

/* начало Main
	min(5, 1, -3, -7, 9, 6)
	min(6, 3, 7, 9, 6, 2, 4)
	min(7, 3, 7, -9, -6, -2, 9, 8)
*/