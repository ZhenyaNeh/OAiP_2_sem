﻿#include<iostream>
#include<fstream>
#include<Windows.h>

using namespace std;

struct text
{
	string ttext{};
	text* next{};
};

int output(text*, string);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	text* begin{ NULL }, * end{ NULL }, * newP{ NULL };

	string adres{ "Input.txt" };
	string adres2{ "Output.txt" };

	ifstream file_1;
	int first{};
	char ch{};

	file_1.open(adres);
	if (!file_1.is_open())
	{
		cout << "Error\n";
		return 0;
	}

	while (!file_1.eof())
	{
		string word{}, number{};
		while (file_1.get(ch))
		{
			if (ch == '\n')
				break;
			else if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
				number += ch;
			else
				word += ch;
		}
		word += '\t';
		word += number;

		newP = new text;
		newP->ttext = word;
		newP->next = NULL;
		if (first == 0)
		{
			first++;
			begin = end = newP;
		}
		else
		{
			end->next = newP;
			end = newP;
		}
	}

	file_1.close();

	output(begin, adres2);

	return 0;
}

int output(text* begin, string adres2)
{
	if (begin == NULL)
	{
		cout << "File is empty\n";
		return 0;
	}

	text* t = begin ;

	ofstream file_2;
	file_2.open(adres2);
	if (!file_2.is_open())
	{
		cout << "Error file\n";
		return 0;
	}

	while (t)
	{
		file_2 << t->ttext << '\n';
		t = t->next;
	}

	file_2.close();

	return 0;
}