#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define SIZE 20

using namespace std;

HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);

void enter_new();
void out();
void find();
void write_information_in_record();
void reed_information_in_record();

enum TradePercent
{
	FIVE = 5,
	SEVEN = 7,
	ELEVEN = 11,
	TWENTY = 20,
	TWENTYFIVE = 25,
	THIRTY = 30
};

struct Stock
{
	string name_Of_Product;
	unsigned int name_Of_Price : 12;
	unsigned int name_Of_Amount : 7;
	unsigned int name_Of_TradePercent : 5;
};

union Unity 
{
	int buff_Int;
}buff;


Stock list_Of_Product[SIZE];
TradePercent TradePer;
int current_size = 0; int choice;
fstream working_With_Fille;
string Path = "File.txt";

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
		cout << "2 - To output record(s)..." << endl;
		cout << "3 - To find of price..." << endl;
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

		cout << "Product Name: ";
		cin >> list_Of_Product[current_size].name_Of_Product;// <- далее заполняется информация
		

		cout << "Product Price: ";
		cin >> buff.buff_Int;
		list_Of_Product[current_size].name_Of_Price = buff.buff_Int;

		cout << "Amount Of Product: ";
		cin >> buff.buff_Int;
		list_Of_Product[current_size].name_Of_Amount = buff.buff_Int;

		cout << "Trade Percent: \n";
		cout << "Choice Percent...\n";
		cout << "1 <- 5% ...\n";
		cout << "2 <- 7% ...\n";
		cout << "3 <- 11% ...\n";
		cout << "4 <- 20% ...\n";
		cout << "5 <- 25%...\n";
		cout << "6 <- 30%...\n";
		cin >> choice;

		switch (choice)
		{
		case 1:	buff.buff_Int = FIVE;	break;
		case 2:	buff.buff_Int = SEVEN;	break;
		case 3:	buff.buff_Int = ELEVEN;	break;
		case 4:	buff.buff_Int  = TWENTY;	break;
		case 5:	buff.buff_Int  = TWENTYFIVE;	break;
		case 6:	buff.buff_Int  = THIRTY;	break;
		}
		list_Of_Product[current_size].name_Of_TradePercent = buff.buff_Int;

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
		cout << "Product Name: \tProduct Price: \tAmount Of Product: \tTrade Percent: \n";
		SetConsoleTextAttribute(hColor, 7);
		cout << list_Of_Product[n - 1].name_Of_Product << "\t\t";
		cout << list_Of_Product[n - 1].name_Of_Price << "$\t\t";
		cout << list_Of_Product[n - 1].name_Of_Amount << "\t\t";
		cout << list_Of_Product[n - 1].name_Of_TradePercent << "%\n";
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			if (flag == 0)
			{
				SetConsoleTextAttribute(hColor, 11);
				cout << "Product Name: \tProduct Price: \tAmount Of Product: \tTrade Percent: \n";
				SetConsoleTextAttribute(hColor, 7);
			}
			cout << list_Of_Product[i].name_Of_Product << "\t\t";
			cout << list_Of_Product[i].name_Of_Price << "$\t\t";
			cout << list_Of_Product[i].name_Of_Amount << "\t\t\t";
			cout << list_Of_Product[i].name_Of_TradePercent << "%\n";
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
	cout << "\n\n\t\t\t//////FIND THE PRODUCT PRICE...//////" << endl;
	SetConsoleTextAttribute(hColor, 7);
	while (choice != 2)
	{
		int flag = 0;
		cout << "\nWrite a Product: ";  cin >> fin;
		for (int finder = 0; finder < current_size; finder++)
		{
			if (list_Of_Product[finder].name_Of_Product == fin) {
				if (flag == 0)
				{
					SetConsoleTextAttribute(hColor, 11);
					cout << "Product Name: \tProduct Price: \tAmount Of Product: \tTrade Percent: \n";
					SetConsoleTextAttribute(hColor, 7);
				}
				cout << list_Of_Product[finder].name_Of_Product << "\t\t";
				cout << list_Of_Product[finder].name_Of_Price << "$\t\t";
				cout << list_Of_Product[finder].name_Of_Amount << "\t\t\t";
				cout << list_Of_Product[finder].name_Of_TradePercent << "%\n";

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
			working_With_Fille >> list_Of_Product[current_size].name_Of_Product;		// <- далее заполняется информация из файла	

			working_With_Fille >> buff.buff_Int;
			list_Of_Product[current_size].name_Of_Price = buff.buff_Int;

			working_With_Fille >> buff.buff_Int;
			list_Of_Product[current_size].name_Of_Amount = buff.buff_Int;

			working_With_Fille >> buff.buff_Int;
			list_Of_Product[current_size].name_Of_TradePercent = buff.buff_Int;

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
			working_With_Fille << list_Of_Product[i].name_Of_Product << "\t";		// <- далее заполняется информация в файл	
			working_With_Fille << list_Of_Product[i].name_Of_Price << "\t\t";
			working_With_Fille << list_Of_Product[i].name_Of_Amount << "\t";
			working_With_Fille << list_Of_Product[i].name_Of_TradePercent << "\t";
		}
		working_With_Fille.close();
		SetConsoleTextAttribute(hColor, 12);
		cout << "\n\n\t\t\t//////SAVE WAS SUCCESSFUL!!!...//////" << endl;
		SetConsoleTextAttribute(hColor, 7);
		system("pause");
		system("cls");
	}
}
