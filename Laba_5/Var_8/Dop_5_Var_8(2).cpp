#include <iostream>
#include <string>
#include <fstream>
#include<windows.h>
# define SIZE 20

using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

void enter_new();
void del();
void out();
void find();
void write_information_in_record();
void reed_information_in_record();

enum Price_Of_Flight
{
	FIFTY = 50,
	SEVENTYFIVE = 75,
	ONEHUNDRED = 100,
	ONEHUNDRED_TWENTY = 120,
	ONEHUNDREDT_WENTYFIVE = 125,
	ONEHUNDRED_FIFTY = 150
};

struct Flight
{
	string name_Of_Reys;
	string name_Of_Place;
	string name_Of_Time;
	string name_Of_Date;
	unsigned int name_Of_Price : 8;
	unsigned int name_Of_People : 7;

};

union Unity
{
	int buff_Int;
}buff;

string Path = "File.txt", block_Informatiom;
ofstream fout;
fstream working_With_Fille;
struct Flight list_Of_Flight[SIZE];
struct Flight bad;
int current_size = 0; int choice;
int price, seats;

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
		cout << "2 - To delete record..." << endl;
		cout << "3 - To output record(s)..." << endl;
		cout << "4 - To find Date..." << endl;
		cout << "5 - To save the record..." << endl;
		cout << "6 - Exit..." << endl;
		cout << "Your variant -> ";
		cin >> choice;

		switch (choice)
		{
		case 1:	enter_new(); break;
		case 2:	del();		break;
		case 3:	out();		break;
		case 4:	find();		break;
		case 5:	write_information_in_record();		break;
		}
	} while (choice != 6);
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

		cout << "Flight number: ";			// <- далее заполняется информация
		cin >> list_Of_Flight[current_size].name_Of_Reys;

		cout << "Place of direction: ";
		cin >> list_Of_Flight[current_size].name_Of_Place;

		cout << "Departure time(example HH:MM): ";
		cin >> list_Of_Flight[current_size].name_Of_Time;

		cout << "Departure date(example: DD.MM.YY ): ";
		cin >> list_Of_Flight[current_size].name_Of_Date;

		cout << "Tickets price: ";
		cout << "Choice Price...\n";
		cout << "1 <- 50$...\n";
		cout << "2 <- 75$...\n";
		cout << "3 <- 100$...\n";
		cout << "4 <- 120$...\n";
		cout << "5 <- 125$...\n";
		cout << "6 <- 150$...\n";
		cin >> choice;

		switch (choice)
		{
		case 1:	buff.buff_Int = FIFTY;	break;
		case 2:	buff.buff_Int = SEVENTYFIVE;	break;
		case 3:	buff.buff_Int = ONEHUNDRED;	break;
		case 4:	buff.buff_Int = ONEHUNDRED_TWENTY;	break;
		case 5:	buff.buff_Int = ONEHUNDREDT_WENTYFIVE;	break;
		case 6:	buff.buff_Int = ONEHUNDRED_FIFTY;	break;
		}
		list_Of_Flight[current_size].name_Of_Price = buff.buff_Int;

		cout << "Number of seats: ";
		cin >> buff.buff_Int;
		list_Of_Flight[current_size].name_Of_People = buff.buff_Int;

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

void del()
{
	int d;
	SetConsoleTextAttribute(hColor, 11);
	cout << "\t\t\t//////DELETE...//////\n" << endl;
	SetConsoleTextAttribute(hColor, 7);
	cout << "\nWrite number of the line to be deleted (if you want delete all lines enter 999)" << endl;
	cin >> d;
	if (d != 999)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_Of_Flight[de1] = list_Of_Flight[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 999)
		for (int i = 0; i < SIZE; i++)
			list_Of_Flight[i] = bad;
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
		cout << "Flight number:\tPlace of direction:\tDeparture time:\tDeparture date:\tTickets price:\tNumber of seats:\n";
		SetConsoleTextAttribute(hColor, 7);
		cout << list_Of_Flight[n - 1].name_Of_Reys << "\t\t";
		cout << list_Of_Flight[n - 1].name_Of_Place << "\t\t\t";
		cout << list_Of_Flight[n - 1].name_Of_Time << "\t\t";
		cout << list_Of_Flight[n - 1].name_Of_Date << "\t";
		cout << list_Of_Flight[n - 1].name_Of_Price << "$\t\t";
		cout << list_Of_Flight[n - 1].name_Of_People << "\n\n";
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Flight number:\tPlace of direction:\tDeparture time:\tDeparture date:\tTickets price:\tNumber of seats:\n";
				SetConsoleTextAttribute(hColor, 7);
			}
			cout << list_Of_Flight[i].name_Of_Reys << "\t\t";
			cout << list_Of_Flight[i].name_Of_Place << "\t\t\t";
			cout << list_Of_Flight[i].name_Of_Time << "\t\t";
			cout << list_Of_Flight[i].name_Of_Date << "\t";
			cout << list_Of_Flight[i].name_Of_Price << "$\t\t";
			cout << list_Of_Flight[i].name_Of_People << "\n\n";
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
		cout << "\nWrite a date(example: DD.MM.YY ): ";  cin >> fin;
		for (int finder = 0; finder < current_size; finder++)
		{
			if (list_Of_Flight[finder].name_Of_Place == fin) {
				if (flag == 0)
				{
					SetConsoleTextAttribute(hColor, 11);
					cout << "Flight number:\tPlace of direction:\tDeparture time:\tDeparture date:\tTickets price:\tNumber of seats:\n";
					SetConsoleTextAttribute(hColor, 7);
				}
				cout << list_Of_Flight[finder].name_Of_Reys << "\t\t";
				cout << list_Of_Flight[finder].name_Of_Place << "\t\t\t";
				cout << list_Of_Flight[finder].name_Of_Time << "\t\t";
				cout << list_Of_Flight[finder].name_Of_Date << "\t";
				cout << list_Of_Flight[finder].name_Of_Price << "$\t\t";
				cout << list_Of_Flight[finder].name_Of_People << "\n\n";
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
			working_With_Fille >> list_Of_Flight[current_size].name_Of_Reys;		// <- далее заполняется информация из файла	
			working_With_Fille >> list_Of_Flight[current_size].name_Of_Place;
			working_With_Fille >> list_Of_Flight[current_size].name_Of_Time;
			working_With_Fille >> list_Of_Flight[current_size].name_Of_Date;
			working_With_Fille >> buff.buff_Int;
			list_Of_Flight[current_size].name_Of_Price = buff.buff_Int;
			working_With_Fille >> buff.buff_Int;
			list_Of_Flight[current_size].name_Of_People = buff.buff_Int;
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
			fout << list_Of_Flight[i].name_Of_Reys << "\t";		// <- далее заполняется информация в файл	
			fout << list_Of_Flight[i].name_Of_Place << "\t\t";
			fout << list_Of_Flight[i].name_Of_Time << "\t";
			fout << list_Of_Flight[i].name_Of_Date << "\t";
			fout << list_Of_Flight[i].name_Of_Price << "\t";
			fout << list_Of_Flight[i].name_Of_People << "\n";
		}
		SetConsoleTextAttribute(hColor, 12);
		cout << "\n\n\t\t\t//////SAVE WAS SUCCESSFUL!!!...//////" << endl;
		SetConsoleTextAttribute(hColor, 7);
		system("pause");
		system("cls");
	}
}