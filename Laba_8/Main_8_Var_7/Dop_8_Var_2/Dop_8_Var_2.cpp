#include<iostream>

using namespace std;

struct element
{
	int numb{};
	element* next{};
};

void read(element*);
void sdvig(element**, element**, int);

int main()
{
	element* begin{ NULL }, * end{ NULL }, * new_Element{ NULL };

	int size{}, max{ -999999 }, index{};
	bool check = true;

	while (check)
	{
		cout << "Enter the size:\t";
		cin >> size;
		if (!cin || size <= 0)
		{
			cout << "Error!!!\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
			check = false;
	}

	for (int i = 0, t{}; i < size; i++)
	{
		cout << i + 1 << " -st number: ";
		cin >> t;
		if (!cin)
		{
			cout << "Error!!!\n";
			cin.clear();
			cin.ignore(100, '\n');
			i--;
			continue;
		}
		if (t > max)
		{
			max = t;
			index = i;
		}
		new_Element = new element;
		new_Element->numb = t;
		new_Element->next = NULL;
		if (i == 0)
			begin = end = new_Element;
		else
		{
			end->next = new_Element;
			end = new_Element;
		}
	}

	system("cls");

	read(begin);
	cout << "\n\n\n";
	sdvig(&begin, &end, index);

	read(begin);

	return 0;
}

void read(element* begin)
{
	element* for_Read = begin;
	cout << "Queue";
	while (for_Read)
	{
		cout << " -> " << for_Read->numb;
		for_Read = for_Read->next;
	}
}

void sdvig(element** begin, element** end, int n)
{
	element* start, * finish;

	for (int i = 0; i < n; i++)
	{
		start = *begin;
		finish = *end;
		*end = start;
		*begin = start->next;
		start->next = NULL;
		finish->next = start;
	}
}