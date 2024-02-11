#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define SIZE 20

using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

void enter_new();
void del();
void out();
void find();
void write_information_in_record();
void reed_information_in_record();

enum TradePercent
{
	BOYS=1,
	GIRLS
};

struct Form
{
	string name_Of_People;
	unsigned int name_Of_Days : 6;
	unsigned int name_Of_Mount : 4;
	unsigned int name_Of_Year : 12;
	string name_Of_Adres;
	string name_Of_Sex;
};

Form list_Of_Form[SIZE];
Form bad;
TradePercent TradePer;
int current_size = 0; int choice;
int day, mount, year;
fstream working_With_Fille;
string Path = "File.txt";
string buffer;

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
		cout << "2 - To delete record..." << endl;
		cout << "3 - To output record(s)..." << endl;
		cout << "4 - To find of price..." << endl;
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

		cout << "Product Name: ";			// <- далее заполняется информация
		cin >> list_Of_Form[current_size].name_Of_People;

		cout << "Date of Birth: \n";
		cout << "Day: ";
		cin >> day;
		list_Of_Form[current_size].name_Of_Days = day;
		cout << "Mount: ";
		cin >> mount;
		list_Of_Form[current_size].name_Of_Mount = mount;
		cout << "Year: ";
		cin >> year;
		list_Of_Form[current_size].name_Of_Year = year;

		cout << "Name of Adres: ";
		cin >> list_Of_Form[current_size].name_Of_Adres;

		cout << "Sex: \n";
		cout << "Choice Sex...\n";
		cout << "1 <- BOYS ...\n";
		cout << "2 <- GIRLS ...\n";
		cout << "Your variant -> ";
		cin >> choice;

		switch (choice)
		{
		case BOYS:	buffer = "M";	break;
		case GIRLS:	buffer = "W";	break;
		
		}
		list_Of_Form[current_size].name_Of_Sex = buffer;

		current_size++;		// <- увеличение на одну строку
	}
	else
	{
		SetConsoleTextAttribute(hColor, 12);
		cout << "\t\t\t!!!YOU HAVE REACHED THE MAXIMUM NUMBER OF ROWS!!!/n";
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
			list_Of_Form[de1] = list_Of_Form[de1 + 1];
		current_size = current_size - 1;
	}
	if (d == 999)
		for (int i = 0; i < SIZE; i++)
			list_Of_Form[i] = bad;
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
		cout << "Sur Name: \tDate of Birth: \tName of Adres: \tSex: \n";
		SetConsoleTextAttribute(hColor, 7);
		cout << list_Of_Form[n - 1].name_Of_People << "\t";
		cout << list_Of_Form[n - 1].name_Of_Days << ".";
		cout << list_Of_Form[n - 1].name_Of_Mount << ".";
		cout << list_Of_Form[n - 1].name_Of_Year << "\t";
		cout << list_Of_Form[n - 1].name_Of_Adres << "\t";
		cout << list_Of_Form[n - 1].name_Of_Sex << "\n";
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Sur Name: \tDate of Birth: \tName of Adres: \t\tSex: \n";
				SetConsoleTextAttribute(hColor, 7);
			}
			cout << list_Of_Form[i].name_Of_People << "\t\t";
			cout << list_Of_Form[i].name_Of_Days << ".";
			cout << list_Of_Form[i].name_Of_Mount << ".";
			cout << list_Of_Form[i].name_Of_Year << "\t";
			cout << list_Of_Form[i].name_Of_Adres << "\t\t";
			cout << list_Of_Form[i].name_Of_Sex << "\n";
			flag++;
		}
	}
	system("pause");
	system("cls");
}

void find()
{
	int fin;
	SetConsoleTextAttribute(hColor, 11);
	cout << "\n\n\t\t\t//////FIND THE PRODUCT PRICE...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	while (choice != 2)
	{
		int flag = 0;
		cout << "\nWrite a Price: ";  cin >> fin;
		for (int finder = 0; finder < current_size; finder++)
		{
			if (list_Of_Form[finder].name_Of_Year == fin) {
				if (flag == 0)
				{
					SetConsoleTextAttribute(hColor, 11);
					cout << "Sur Name: \tDate of Birth: \tName of Adres: \tSex: \n";
					SetConsoleTextAttribute(hColor, 7);
				}
				cout << list_Of_Form[finder].name_Of_People << "\t";
				cout << list_Of_Form[finder].name_Of_Days << ".";
				cout << list_Of_Form[finder].name_Of_Mount << ".";
				cout << list_Of_Form[finder].name_Of_Year << "\t";
				cout << list_Of_Form[finder].name_Of_Adres << "\t";
				cout << list_Of_Form[finder].name_Of_Sex << "\n";

				flag++;
			}
			if (flag == 0 && current_size - 1 == finder)
				cout << "Sorry, there is no such price...\n" << endl;
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
	working_With_Fille.open(Path, fstream::in);
	if (!working_With_Fille.is_open())
	{
		cout << "ERROR!!!...\n";
	}
	else
	{
		while (!working_With_Fille.eof())
		{
			working_With_Fille >> list_Of_Form[current_size].name_Of_People;		// <- далее заполняется информация из файла	

			working_With_Fille >> day;
			list_Of_Form[current_size].name_Of_Days = day;
			
			working_With_Fille >> mount;
			list_Of_Form[current_size].name_Of_Mount = mount;
			
			working_With_Fille >> year;
			list_Of_Form[current_size].name_Of_Year = year;

			working_With_Fille >> list_Of_Form[current_size].name_Of_Adres;

			working_With_Fille >> list_Of_Form[current_size].name_Of_Sex;

			current_size++;
		}
		working_With_Fille.close();
	}
}

void write_information_in_record()
{
	working_With_Fille.open(Path, fstream::out);
	if (!working_With_Fille.is_open())
	{
		cout << "ERROR!!!...\n";
	}
	else
	{
		for (int i = 0; i < current_size; i++)
		{
			working_With_Fille << list_Of_Form[i].name_Of_People << "\t";
			working_With_Fille << list_Of_Form[i].name_Of_Days << "\t";
			working_With_Fille << list_Of_Form[i].name_Of_Mount << "\t";
			working_With_Fille << list_Of_Form[i].name_Of_Year << "\t";
			working_With_Fille << list_Of_Form[i].name_Of_Adres << "\t";
			working_With_Fille << list_Of_Form[i].name_Of_Sex << "\n";
		}
		working_With_Fille.close();
		SetConsoleTextAttribute(hColor, 12);
		cout << "\n\n\t\t\t//////SAVE WAS SUCCESSFUL!!!...//////" << endl;
		SetConsoleTextAttribute(hColor, 7);
		system("pause");
		system("cls");
	}
}
