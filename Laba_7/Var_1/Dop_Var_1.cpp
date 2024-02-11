#include<iostream>
#include<Windows.h>

using namespace std;

struct stack
{
	char simbl{};
	stack* next{};
};

int add(stack*&, int, char*);
int read(stack*&, int);

int main()
{
	stack* first{ NULL };
	int numb{};
	char text[100];
	cout << "enter the text:\t";
	gets_s(text);
	numb = strlen(text);
	if (numb <= 0)
	{
		cout << "error\n";
		return 0;
	}
	if (numb % 2 == 1)
	{
		cout << "error\n";
		return 0;
	}

	add(first, numb, text);
	read(first, numb);

	cout << "\nEnd\n";
	return 0;
}

int add(stack*& p, int n, char* t)
{
	stack* newP;
	for (int i = 0; i < n; i++)
	{
		newP = new stack;
		newP->simbl = t[i];
		newP->next = p;
		p = newP;
	}
	return 0;
}

int read(stack*& begin, int n)
{
	stack* element;
	char* word;
	int i{}, j{};
	word = new char[n / 2];

	while (begin)
	{
		element = begin;
		begin = begin->next;

		if (i < n / 2)
		{
			word[j] = element->simbl;
			j++;
		}
		if (i >= n / 2)
		{
			cout << element->simbl;
		}
		i++;
		delete element;
	}
	for (int i = 0; i < (n / 2); i++)
	{
		cout << word[i];
	}

	return 0;
}