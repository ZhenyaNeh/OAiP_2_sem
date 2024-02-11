#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<fstream>
using namespace std;

//Создать список, содержащий элементы целого типа. Найти сумму положительных элементов или выдать сообщение, что положительных элементов нет. 

struct List
{
	int numb{};
	List* next{};
};

int add_In_List(List*&);
int delete_List(List*&);
int show_List(List*);
int save_List(List*);
int read_Filre(List*&);
int sum_Negative_Number(List*);

string Path = "File.txt";
fstream working_With_Fille;


int main()
{
	List* first{ NULL };
	HANDLE hColor{ GetStdHandle(STD_OUTPUT_HANDLE) };
	int choice{};

	read_Filre(first);
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(hColor, 14);
		cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
		SetConsoleTextAttribute(hColor, 7);
		cout << "Enter: " << endl;
		cout << "1 - Add new number..." << endl;
		cout << "2 - Delete number..." << endl;
		cout << "3 - Show all number..." << endl;
		cout << "4 - To save the number..." << endl;
		cout << "5 - Summa..." << endl;
		cout << "6 - Exit..." << endl;
		cout << "Your variant -> ";
		cin >> choice;

		if (!cin)
		{
			cout << "It's not a number!!!...\n";
			system("pause");
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		switch (choice)
		{
		case 1:
			add_In_List(first);
			system("pause");
			break;

		case 2:
			if (first == NULL)
				cout << "Error!!!...\nNot such number!!!...\n";
			else if (delete_List(first))
			{
				SetConsoleTextAttribute(hColor, 12);
				cout << "\n\n\t\t\t//////DELETE WAS SUCCESSFUL!!!...//////" << endl;
				SetConsoleTextAttribute(hColor, 7);
			}
			else
				cout << "Error!!!...\nNot such number!!!...\n";
			system("pause");
			break;

		case 3:
			show_List(first);
			system("pause");
			break;

		case 4:
			if (save_List(first))
				cout << "Информация успешно сохранен\n";
			system("pause");
			break;

		case 5:
			sum_Negative_Number(first);
			system("pause");
			break;

		case 6:
			cout << "Exit completed...\n";
			return 0;
			break;

		default:
			cout << "Error!!!...\nNot such number!!!...\n";
			system("pause");
			break;
		}
	}
}

int add_In_List(List*& p)
{
	int numb{};
	cout << "Enter the number: ";
	cin >> numb;
	if (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		return 0;
	}
	List* newP = new List;

	if (newP != NULL)
	{
		newP->numb = numb;
		newP->next = p;
		p = newP;
		cout << "Number add!!!...\n";
	}
	else
		cout << "Error!!!....\n";
	return 0;
}

int delete_List(List*& p)
{
	List* help{}, * adre{}, * tmp{};

	int numb{};
	cout << "Enter the number to be deleted: ";
	cin >> numb;
	if (!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		return 0;
	}

	if (numb == p->numb)
	{
		tmp = p;
		p = p->next;
		tmp = NULL;
		return 1;
	}
	else
	{
		help = p;
		adre = p->next;
		while (adre != NULL && adre->numb != numb)
		{
			help = adre;
			adre = adre->next;
		}
		if (adre != NULL)
		{
			tmp = adre;
			help->next = adre->next;
			free(tmp);
			return 1;
		}
	}

	return 0;
}

int show_List(List* p)
{
	if (p == NULL)
		cout << "Not such number\n";
	else
	{
		cout << "My List: \n";
		while (p != NULL)
		{
			cout << p->numb << '\n';
			p = p->next;
		}
	}
	return 0;
}

int save_List(List* p)
{
	working_With_Fille.open(Path, fstream::out);
	if (!working_With_Fille.is_open())
	{
		cout << "Error!!!...\n";
		return 0;
	}

	while (p)
	{
		working_With_Fille << p->numb << '\n';
		p = p->next;
	}

	working_With_Fille.close();

	return 1;
}

int read_Filre(List*& p)
{
	working_With_Fille.open(Path, fstream::in);
	if (!working_With_Fille.is_open())
	{
		cout << "Error!!!...\n";
		return 0;
	}

	int t{};

	while (!working_With_Fille.eof())
	{
		int help{};
		working_With_Fille >> help;
		if (!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		if (help == 0 && t == 0)
			continue;
		t++;

		List* newP = new List;

		newP->numb = help;
		newP->next = p;
		p = newP;
	}

	working_With_Fille.close();

	return 0;
}

int sum_Negative_Number(List* p)
{
	int sum{};

	if (p == NULL)
		cout << "List empty\n";
	else
	{
		while (p)
		{
			if (p->numb > 0)
				sum += p->numb;
			p = p->next;
		}
	}

	if (sum == 0)
		cout << "Not such number!!!...\n";
	else
		cout << "\nSumma: " << sum << "\n\n";

	return 0;
}