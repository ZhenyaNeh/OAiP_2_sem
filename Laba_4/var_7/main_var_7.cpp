#include <iostream>
#include <string>
#include <fstream>
#include<windows.h>
# define SIZE 10

using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

void enter_new();
void del();
void change();
void out();
void find();
void write_information_in_record();
void reed_information_in_record();

struct Flight
{
	char name_Of_Reys[SIZE];
	char name_Of_Place[SIZE];
	char name_Of_Time[SIZE];
	char name_Of_Date[SIZE];
	char name_Of_Price[SIZE];
	char name_Of_People[SIZE];
};

string Path = "File.txt", block_Informatiom;
ofstream fout;
fstream i_Dont_Know;
struct Flight list_Of_Flight[SIZE];
struct Flight bad;
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
	cout << "2 - To delete record..." << endl;
	cout << "3 - To chenge record..." << endl;
	cout << "4 - To output record(s)..." << endl;
	cout << "5 - To find city..." << endl;
	cout << "6 - To save the record..." << endl;
	cout << "7 - Exit..." << endl;
	cout << "Your variant -> ";
	cin >> choice;
	
		switch (choice)
		{
		case 1:	enter_new();break;
		case 2:	del();		break;
		case 3:	change();	break;
		case 4:	out();		break;
		case 5:	find();		break;
		case 6:	write_information_in_record();		break;
		}
	} while (choice != 7);
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
		cout << "Departure time: ";
		cin >> list_Of_Flight[current_size].name_Of_Time;
		cout << "Departure date: ";
		cin >> list_Of_Flight[current_size].name_Of_Date;
		cout << "Tickets price: ";
		cin >> list_Of_Flight[current_size].name_Of_Price;
		cout << "Number of seats: ";
		cin >> list_Of_Flight[current_size].name_Of_People;

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

void change()
{
	int n, per{0};
	SetConsoleTextAttribute(hColor, 11);
	cout << "\n\n\t\t\t//////CHENGE LINE...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	while(per != 2)
	{
		cout << "Enter the number which you want change: "; 
		cin >> n;
		cout << "\n\n";
		do
		{
			cout << "Enter: " << endl;
			cout << "1 - To chenge Flight number..." << endl;
			cout << "2 - To chenge Place of direction..." << endl;
			cout << "3 - To chenge Departure time..." << endl;
			cout << "4 - To chenge Departure date..." << endl;
			cout << "5 - To chenge Tickets price..." << endl;
			cout << "6 - To chenge Number of seats..." << endl;
			cout << "7 - Exit...\n";
			cout << "Your variant -> ";
			cin >> per;
			switch (per)
			{
			case 1: cout << "New Flight number: ";
				cin >> list_Of_Flight[n - 1].name_Of_Reys; break;

			case 2: cout << "New Place of direction: ";
				cin >> list_Of_Flight[n - 1].name_Of_Place; break;

			case 3: cout << "New Departure time: ";
				cin >> list_Of_Flight[n - 1].name_Of_Time; break;

			case 4: cout << "New Departure date: ";
				cin >> list_Of_Flight[n - 1].name_Of_Date; break;

			case 5: cout << "New Tickets price: ";
				cin >> list_Of_Flight[n - 1].name_Of_Price; break;

			case 6: cout << "New Number of seats: ";
				cin >> list_Of_Flight[n - 1].name_Of_People; break;

			
			}
		} while (per != 7);
		cout << "\n If you want chenge new line..." << endl;
		cout << "1 - Yes, i want chenge more lines..." << endl;
		cout << "2 - Exit..." << endl;
		cin >> per;
	}
	system("pause");
	system("cls");
}

void out()
{
	int sw, n, flag{0};
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
		cout << list_Of_Flight[n - 1].name_Of_Price << "\t\t";
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
			cout << list_Of_Flight[i].name_Of_Price << "\t\t";
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
	while (choice !=2)
	{
		int flag = 0;
		cout << "\nWrite a City: ";  cin >> fin;
		for (int finder = 0; finder < current_size; finder++)
		{	
			if (list_Of_Flight[finder].name_Of_Place == fin) {
				if(flag == 0)
				{
					SetConsoleTextAttribute(hColor, 11);
					cout << "Flight number:\tPlace of direction:\tDeparture time:\tDeparture date:\tTickets price:\tNumber of seats:\n";
					SetConsoleTextAttribute(hColor, 7);
				}
				cout << list_Of_Flight[finder].name_Of_Reys << "\t\t";
				cout << list_Of_Flight[finder].name_Of_Place << "\t\t\t";
				cout << list_Of_Flight[finder].name_Of_Time << "\t\t";
				cout << list_Of_Flight[finder].name_Of_Date << "\t";
				cout << list_Of_Flight[finder].name_Of_Price << "\t\t";
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
			i_Dont_Know >> list_Of_Flight[current_size].name_Of_Reys;		// <- далее заполняется информация из файла	
			i_Dont_Know >> list_Of_Flight[current_size].name_Of_Place;
			i_Dont_Know >> list_Of_Flight[current_size].name_Of_Time;
			i_Dont_Know >> list_Of_Flight[current_size].name_Of_Date;
			i_Dont_Know >> list_Of_Flight[current_size].name_Of_Price;
			i_Dont_Know >> list_Of_Flight[current_size].name_Of_People;
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
		for(int i = 0; i < current_size; i++)
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