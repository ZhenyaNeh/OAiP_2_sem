#include <iostream>
#include <string>
#include <fstream>
#include<windows.h>
#define SIZE 30

using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

void enter_new();
void find();
void reed_information_in_record();

struct SANATORIY
{
	char name[SIZE];
	char location[SIZE];
	char profile[SIZE];
	char num_Of_Places[SIZE];

};

string Path = "File.txt", block_Informatiom;
ofstream fout;
fstream i_Dont_Know;
struct SANATORIY list_Of_Sanatoriy[SIZE];
struct SANATORIY bad;
int current_size = 0; int choice;

int main()
{
	reed_information_in_record();
	do
	{
		SetConsoleTextAttribute(hColor, 14);
		cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
		SetConsoleTextAttribute(hColor, 7);
		cout << "Enter: " << endl;
		cout << "1 - To enter a new record..." << endl;
		cout << "2 - To find..." << endl;
		cout << "3 - Exit..." << endl;
		cout << "Your variant -> ";
		cin >> choice;

		switch (choice)
		{
		case 1:	enter_new(); break;
		case 2:	find();		break;
		}
	} while (choice != 3);
}

void enter_new()
{
	SetConsoleTextAttribute(hColor, 11);
	cout << "\t\t\t//////ENTER THE INFORMATION...//////\n" << endl;
	SetConsoleTextAttribute(hColor, 7);
	if (current_size < SIZE)
	{
		cout << "You write in line number: " << current_size + 1 << endl;		// <- показатель какая строка заполняется

		cout << "Name: ";			// <- далее заполняется информация
		cin >> list_Of_Sanatoriy[current_size].name;
		cout << "Location: ";
		cin >> list_Of_Sanatoriy[current_size].location;
		cout << "Profile(in this line you mast write: relaxation or prevention or recovery): ";//<- 100% что я забуду как это пререводится, отдых, профилактика, восстановление
		cin >> list_Of_Sanatoriy[current_size].profile;
		cout << "Amount of places: ";
		cin >> list_Of_Sanatoriy[current_size].num_Of_Places;

		current_size++;		// <- увеличение на одну строку
	}
	else
	{
		SetConsoleTextAttribute(hColor, 12);
		cout << "\t\t\t!!!YOU HAVE REACHED THE MAXIMUM NUMBER OF ROWS!!!";
		SetConsoleTextAttribute(hColor, 7);
	}
	system("pause");
	system("cls");
}

void find()
{
	SetConsoleTextAttribute(hColor, 11);
	cout << "\n\n\t\t\t//////PROFILE DISTRIBUTION...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);

	string relax = "relaxation";
	string prev = "prevention";
	string recov = "recovery";

	string name_Alesya = "Alesya";
	string name_Vetraz = "Vetraz";
	string name_Pines = "Pines";
	string name_Berezina = "Bereza";

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	SetConsoleTextAttribute(hColor, 12);
	cout << "\n\n\t\t\t//////PROFILE RELAXATION...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	int flag = 0;
	for (int finder = 0; finder < current_size; finder++)
	{
		if (list_Of_Sanatoriy[finder].profile == relax)
		{

			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Name: \tLocation: \tAmount of places:\n";
				SetConsoleTextAttribute(hColor, 7);
			}

			if (list_Of_Sanatoriy[finder].name == name_Alesya)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Berezina)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Pines)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Vetraz)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}
			flag++;
		}
		if (flag == 0 && current_size - 1 == finder)
			cout << "Sorry, there is no such profile...\n" << endl;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	SetConsoleTextAttribute(hColor, 12);
	cout << "\n\n\t\t\t//////PROFILE PREVENTION...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	flag = 0;
	for (int finder = 0; finder < current_size; finder++)
	{
		if (list_Of_Sanatoriy[finder].profile == prev)
		{

			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Name: \tLocation: \tAmount of places:\n";
				SetConsoleTextAttribute(hColor, 7);
			}

			if (list_Of_Sanatoriy[finder].name == name_Alesya)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Berezina)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Pines)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Vetraz)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}
			flag++;
		}
		if (flag == 0 && current_size - 1 == finder)
			cout << "Sorry, there is no such profile...\n" << endl;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	SetConsoleTextAttribute(hColor, 12);
	cout << "\n\n\t\t\t//////PROFILE RECOVERY...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	flag = 0;
	for (int finder = 0; finder < current_size; finder++)
	{
		if (list_Of_Sanatoriy[finder].profile == recov)
		{

			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Name: \tLocation: \tAmount of places:\n";
				SetConsoleTextAttribute(hColor, 7);
			}

			if (list_Of_Sanatoriy[finder].name == name_Alesya)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Berezina)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Pines)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}

			if (list_Of_Sanatoriy[finder].name == name_Vetraz)
			{
				cout << list_Of_Sanatoriy[finder].name << "\t";
				cout << list_Of_Sanatoriy[finder].location << "\t\t";
				cout << list_Of_Sanatoriy[finder].num_Of_Places << "\n\n\n";
			}
			flag++;
		}
		if (flag == 0 && current_size - 1 == finder)
			cout << "Sorry, there is no such profile...\n" << endl;
	}

	system("pause");
	system("cls");
}

void reed_information_in_record()
{
	i_Dont_Know.open(Path, fstream::in);
	if (!i_Dont_Know.is_open())
	{
		cout << "ERROR!!!...\n";
	}
	else
	{
		while (!i_Dont_Know.eof())
		{
			i_Dont_Know >> list_Of_Sanatoriy[current_size].name;		// <- далее заполняется информация из файла	
			i_Dont_Know >> list_Of_Sanatoriy[current_size].location;
			i_Dont_Know >> list_Of_Sanatoriy[current_size].profile;
			i_Dont_Know >> list_Of_Sanatoriy[current_size].num_Of_Places;
			current_size++;
		}
	}
}
/*3. Определить структуру для представления информации о наличии санаторных путевок,
содержащую следующие поля: Название санатория, Место расположения, Лечебный профиль,
Количество путевок. Представить введенные данные в виде таблицы, сгруппировав их по
лечебным профилям санаториев. В пределах каждой группы данные отсортировать по названиям
санаториев. Организовать поиск информации и вывод результатов. */