#include <iostream>
#include <fstream>
#include<string>
#define n 20
using namespace std;

struct student
{
	string sur_Name;
	string name;
	string father_Name;
	string leeson_name[5]{ "Matem","Fizika","OAIP","KPO","Kyar" };
	int year{};
	int kyrs{};
	int number_Of_Group{};
	int marks[5]{};
	student* next;
	student* prev;
};

student* add();
int dob(student*, student**, student**);
int sort(student*, student*);
int show(student*);
int average_Marks(student*);
int old_young(student*);
int theBestOfTheBestOfTheBest(student*);

void main()
{
	student* phead{ NULL };
	student* plast{ NULL };
	setlocale(LC_ALL, "ru");
	int var{};
	while (true)
	{
		system("cls");
		show(phead) ? cout << "\n" : cout << "lists empty\n\n\n";

		cout << "---------------CHOICE THE VARIANT---------------\n";
		cout << "1 - Add a new student\n";
		cout << "2 - Show centrl assecc grup\n";
		cout << "3 - Show oldest and youngest student\n";
		cout << "4 - Show a best student in the group\n";
		cout << "0 - End\n";
		cin >> var;

		if (!cin)
		{
			cout << "This is not number\n";
			system("pause");
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}

		switch (var)
		{
		case 1:
			if (dob(add(), &phead, &plast))
				sort(phead, plast);
			cout << "Student add\n";
			system("pause");
			break;

		case 2:
			if (phead != NULL)
				average_Marks(phead);
			else
				cout << "list empty\n";
			system("pause");
			break;

		case 3:
			if (phead != NULL)
				old_young(phead);
			else
				cout << "list empty\n";
			system("pause");
			break;

		case 4:
			if (phead != NULL)
				theBestOfTheBestOfTheBest(phead);
			else
				cout << "list empty\n";
			system("pause");
			break;

		case 0:
			cout << "End\n";
			return;
			break;

		default:
			cout << "error\n";
			system("pause");
			break;
		}
	}
}

student* add()
{
	int check{};
	student* newP = new student;
	cout << "Enter the Sername:\t";
	cin >> newP->sur_Name;
	cout << "Enter the Name:\t";
	cin >> newP->name;
	cout << "Enter the Father Name:\t";
	cin >> newP->father_Name;

	while (true)
	{
		cout << "Enter the Year Of Bithday: \t";
		cin >> check;
		if (check > 2023 || check < 1950)
		{
			cerr << "Error!!!\n";
			cout << "Try again...";
			continue;
		}
		break;
	}
	newP->year = check;

	while (true)
	{
		cout << "Enter the kyrs (1-4):\t";
		cin >> check;
		if (!cin || check < 1 || check > 4)
		{
			cerr << "Error!!!\n";
			cout << "Try again...";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		break;
	}
	newP->kyrs = check;

	while (true)
	{
		cout << "Enter the group (1-5):\t";
		cin >> check;
		if (!cin || check < 1 || check > 5)
		{
			cerr << "Error!!!\n";
			cout << "Try again...";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		break;
	}
	newP->number_Of_Group = check;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter " << i + 1 << "-th marks: ";
		cin >> newP->marks[i];
	}

	newP->next = NULL;
	newP->prev = NULL;

	return newP;
}

int dob(student* p, student** phead, student** plast)
{
	if (*plast == NULL)
	{
		p->next = NULL;
		p->prev = NULL;
		*plast = p;
		*phead = p;
		return 0;
	}
	else
	{
		student* e{ *plast };
		e->next = p;
		p->next = NULL;
		p->prev = e;
		*plast = p;
		return 1;
	}
}

int sort(student* phead, student* plast)
{
	student* p = plast;
	student* a = p;
	student* z = p->prev;
	int kyrs = p->kyrs;
	while (z)
	{
		if (a->kyrs < z->kyrs)
		{
			swap(a->sur_Name, z->sur_Name);
			swap(a->name, z->name);
			swap(a->father_Name, z->father_Name);
			swap(a->year, z->year);
			swap(a->kyrs, z->kyrs);
			swap(a->number_Of_Group, z->number_Of_Group);
			swap(a->marks, z->marks);

			z = z->prev;
			a = a->prev;
		}
		else
			break;
	}

	a = p;
	z = a->prev;

	while (z)
	{
		if (a->kyrs == kyrs && z->kyrs == kyrs)
		{
			if (int(a->sur_Name[0]) < int(z->sur_Name[0]))
			{
				swap(a->sur_Name, z->sur_Name);
				swap(a->name, z->name);
				swap(a->father_Name, z->father_Name);
				swap(a->year, z->year);
				swap(a->kyrs, z->kyrs);
				swap(a->number_Of_Group, z->number_Of_Group);
				swap(a->marks, z->marks);
			}
		}

		z = z->prev;
		a = a->prev;
	}

	return 0;
}

int show(student* phead)
{
	if (phead == NULL)
		return 0;

	student* p = phead;
	while (p)
	{
		cout << p->sur_Name << ' ' << p->name << ' ' << p->father_Name << ' ' << p->year << "\t" << p->kyrs <<"-st kyrs\t" << p->number_Of_Group << "-st grup   marks:" << p->marks[0] << p->marks[1] << p->marks[2] << p->marks[3] << p->marks[4] << '\n';
		p = p->next;
	}
	return 1;

}

int average_Marks(student* phead)
{
	student* t = phead;
	double average[5][5]{}, numb[5]{};
	int help{};

	while (t)
	{
		help = t->number_Of_Group - 1;

		for (int i = 0; i < 5; i++)
		{
			average[help][i] += t->marks[i];
		}
		numb[help]++;
		t = t->next;
	}
	cout << "\n\n\n";
	for (int i = 0; i < 5; i++)
	{
		if (average[i][0] == 0)
			cout << "list " << i + 1 << " is empty\n";
		else
		{
			cout << "grup " << i + 1 << ":\n\n";

			for (int j = 0; j < 5; j++)
			{
				if (j == 0 || j == 1)
					cout << phead->leeson_name[j] << ":\t" << average[i][j] / numb[i] << '\n';
				else
					cout << phead->leeson_name[j] << ":\t" << average[i][j] / numb[i] << '\n';
			}
		}
		cout << "\n\n";
	}

	return 0;
}

int old_young(student* phead)
{
	if (phead->next == NULL)
	{
		cout << "Student only one:\t" << phead->sur_Name << '\n';
		return 0;
	}

	string older{}, younger{};
	int old{ 3000 }, young{ };
	student* t{ phead };

	while (t)
	{
		if (t->year < old)
		{
			old = t->year;
			older = t->sur_Name;
		}
		
		if (t->year > young)
		{
			young = t->year;
			younger = t->sur_Name;
		}
		t = t->next;
	}

	cout << "The Older Student Is:\t" << older << " - " << old << "\n";
	cout << "The Younger Student Is:\t" << younger << " - " << young << "\n";
	return 0;
}

int theBestOfTheBestOfTheBest(student* phead)
{
	student* t{ phead };

	double centr{}, best[5]{};
	string best_name[5]{};

	while (t)
	{
		for (int i = 0; i < 5; i++)
			centr += t->marks[i];

		centr /= 5;

		if (centr > best[t->number_Of_Group - 1])
		{
			best[t->number_Of_Group - 1] = centr;
			best_name[t->number_Of_Group - 1] = t->sur_Name;
		}

		t = t->next;
	}

	for (int i = 0; i < 5; i++)
	{
		if (best[i] != 0)
		{
			cout << "\nThe best of the best of the best student in " << i + 1 << "-st grup is:\t" << best_name[i] << '\n';
		}
		else
			cout << "\n Sorry!!! " << i + 1 << "- st grup is empty\n";
	}

	return 0;
}