#include <iostream>
#include <string>
#include <fstream>
#include<windows.h>
# define SIZE 20

using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

void enter_new();
void out();
void find();
void write_information_in_record();
void reed_information_in_record();

struct Train
{
	string name_Of_Train;
	string name_Of_Place;
	unsigned int name_Of_Days : 2;
	string name_Of_End;
	string name_Of_Start;
};

union Unity
{
	int buff_Int;
}buff;

string Path = "File.txt", block_Informatiom;
ofstream fout;
fstream working_With_Fille;
Train list_Of_Train[SIZE];
int current_size = 0; int choice;

int main()
{
	do
	{
		reed_information_in_record();
		SetConsoleTextAttribute(hColor, 14);
		cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
		SetConsoleTextAttribute(hColor, 7);
		cout << "Enter: " << endl;
		cout << "1 - To enter a new record..." << endl;
		cout << "2 - To output record(s)..." << endl;
		cout << "3 - To find Date..." << endl;
		cout << "4 - To save the record..." << endl;
		cout << "5 - Exit..." << endl;
		cout << "Your variant -> ";
		cin >> choice;

		switch (choice)
		{
		case 1:	enter_new(); break;
		case 2:	out();		break;
		case 3:	find();		break;
		case 4:	write_information_in_record();		break;
		}
	} while (choice != 5);
}

void enter_new()
{
	SetConsoleTextAttribute(hColor, 11);
	cout << "\t\t\t//////ENTER THE INFORMATION...//////\n" << endl;
	SetConsoleTextAttribute(hColor, 7);
	if (current_size < SIZE)
	{
		cout << "You write in line number: ";		// <- показатель какая строка заполняется
		cout << current_size + 1 << endl;

		cout << "Train number: ";			// <- далее заполняется информация
		cin >> list_Of_Train[current_size].name_Of_Train;

		cout << "Place of direction: ";
		cin >> list_Of_Train[current_size].name_Of_Place;

		cout << "Number of Days: ";
		cin >> buff.buff_Int;
		list_Of_Train[current_size].name_Of_Days = buff.buff_Int;

		cout << "Arrival Time(example HH:MM): ";
		cin >> list_Of_Train[current_size].name_Of_End;

		cout << "Departure Time(example HH:MM): ";
		cin >> list_Of_Train[current_size].name_Of_Start;

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


void out()
{
	int sw, n, flag{ 0 };
	SetConsoleTextAttribute(hColor, 11);
	cout << "\n\n\t\t\t//////WITHDRAW LINE...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	cout << "1 - If you want to withdraw 1 line..." << endl;
	cout << "2 - If you want to withdraw all line..." << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << "Enter the number of line: " << endl;   cin >> n;  cout << endl;
		SetConsoleTextAttribute(hColor, 11);
		cout << "Train number: \tPlace of direction: \tNumber of Days: \Arrival Time: \tDeparture Time: \n";
		SetConsoleTextAttribute(hColor, 7);
		cout << list_Of_Train[n - 1].name_Of_Train << "\t\t";
		cout << list_Of_Train[n - 1].name_Of_Place << "\t\t";
		cout << list_Of_Train[n - 1].name_Of_Days << "\t\t";
		cout << list_Of_Train[n - 1].name_Of_End << "\t";
		cout << list_Of_Train[n - 1].name_Of_Start << "\n\n";
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Train number: \tPlace of direction: \tNumber of Days: \Arrival Time: \tDeparture Time: \n";
				SetConsoleTextAttribute(hColor, 7);
			}
			cout << list_Of_Train[i].name_Of_Train << "\t\t";
			cout << list_Of_Train[i].name_Of_Place << "\t\t\t";
			cout << list_Of_Train[i].name_Of_Days << "\t\t";
			cout << list_Of_Train[i].name_Of_End << "\t\t";
			cout << list_Of_Train[i].name_Of_Start << "\n\n";
			flag++;
		}
	}
	system("pause");
	system("cls");
}

void find()
{
	string fin;
	SetConsoleTextAttribute(hColor, 11);
	cout << "\n\n\t\t\t//////FIND THE CITY...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	while (choice != 2)
	{
		int flag = 0;
		cout << "\nWrite CITY: ";  cin >> fin;
		for (int finder = 0; finder < current_size; finder++)
		{
			if (list_Of_Train[finder].name_Of_Place == fin) {
				if (flag == 0)
				{
					SetConsoleTextAttribute(hColor, 11);
					cout << "Train number: \tPlace of direction: \tNumber of Days: \Arrival Time: \tDeparture Time: \n";
					SetConsoleTextAttribute(hColor, 7);
				}
				cout << list_Of_Train[finder].name_Of_Train << "\t\t";
				cout << list_Of_Train[finder].name_Of_Place << "\t\t";
				cout << list_Of_Train[finder].name_Of_Days << "\t\t";
				cout << list_Of_Train[finder].name_Of_End << "\t";
				cout << list_Of_Train[finder].name_Of_Start << "\n\n";
				flag++;
			}
			if (flag == 0 && current_size - 1 == finder)
				cout << "Sorry, there is no such city...\n" << endl;
		}
		cout << "1 - If you want to try one more..." << endl;
		cout << "2 - Exit..." << endl;
		cin >> choice;
	}
	system("cls");
}

void reed_information_in_record()
{
	working_With_Fille.open(Path, fstream::in);
	if (!working_With_Fille.is_open())
	{
		cout << "ERROR!!!...\n";
	}
	else
	{
		while (!working_With_Fille.eof())
		{
			working_With_Fille >> list_Of_Train[current_size].name_Of_Train;

			working_With_Fille >> list_Of_Train[current_size].name_Of_Place;

			working_With_Fille >> buff.buff_Int;
			list_Of_Train[current_size].name_Of_Days = buff.buff_Int;

			working_With_Fille >> list_Of_Train[current_size].name_Of_End;

			working_With_Fille >> list_Of_Train[current_size].name_Of_Start;

			current_size++;
		}
	}
}

void write_information_in_record()
{
	fout.open(Path);
	if (!fout.is_open())
	{
		cout << "ERROR!!!...\n";
	}
	else
	{
		for (int i = 0; i < current_size; i++)
		{
			fout << list_Of_Train[i].name_Of_Train << "\t\t";
			fout << list_Of_Train[i].name_Of_Place << "\t\t";
			fout << list_Of_Train[i].name_Of_Days << "\t\t";
			fout << list_Of_Train[i].name_Of_End << "\t";
			fout << list_Of_Train[i].name_Of_Start << "\n\n";
			
		}
		SetConsoleTextAttribute(hColor, 12);
		cout << "\n\n\t\t\t//////SAVE WAS SUCCESSFUL!!!...//////" << endl;
		SetConsoleTextAttribute(hColor, 7);
		system("pause");
		system("cls");
	}
}