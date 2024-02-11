#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct stack {
	int inf;
	stack* next;
};

stack* addElements(stack* begin, int j);
void deleteMinValue(stack* begin);
void showStack(stack* begin);

int number_Word[20], i{0};

int main()
{
	stack* begin = NULL;

	string Path = { "File.txt" };
	
	fstream working_Whith_File;

	working_Whith_File.open(Path, fstream::in);
	if (!working_Whith_File.is_open())
	{
		cout << "error file";
		return 0;
	}
	while (!working_Whith_File.eof())
	{
		char stroke[50];
		working_Whith_File.getline(stroke, 50);
		number_Word[i] = strlen(stroke);
		i++;
	}
	working_Whith_File.close();

	for (int j = 0; j < i; j++)
		begin = addElements(begin, j);
	
	showStack(begin);
	deleteMinValue(begin);
	
}

stack* addElements(stack* begin, int j)
{
	stack* t = new stack;
	t->inf = number_Word[j];
	t->next = begin;
	return t;
}

void showStack(stack* begin)
{
	cout << "--------------Stack--------------" << endl;
	stack* t = begin;
	while (t != NULL)
	{
		cout << "\t\t" << t->inf << endl;
		t = t->next;
	}
	cout << endl;
}
void deleteMinValue(stack* begin)
{
	int check{ 1 };
	stack* t = begin;
	stack* p = begin->next;
	for (; p; p = p->next)
		if (p->inf < t->inf)
		{
			t = p;
	
		}
	p = begin;
	if (p != t)
	{
		while (p->next != t)
		{
			p = p->next;
			check++;
		}
		p->next = t->next;
		check++;
	}
	delete begin;
	cout << "Min stroke: "<< check <<"\nCol symbol: "<< t->inf <<"\n";
	
}