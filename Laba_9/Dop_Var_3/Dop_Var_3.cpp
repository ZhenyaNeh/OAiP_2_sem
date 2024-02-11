#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;

struct cycle
{
	int name;
	cycle* next{}, * prev;
};

struct excluded 
{
	int name;
	excluded* next{}, * prev;
};

template<class Type>
void show(Type* s)
{
	Type* t{ s };
	cout << "Cycle:\n";
	while (t)
	{
		cout << "[ " << t->name << " ] -> ";
		t = t->next;
	}
}

excluded* dell(cycle**, cycle**, int);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	cycle* start{ NULL }, * t{ NULL }, * last{ NULL };
	int size{};
	cout << "Enter the number of people: ";
	while (true)
	{
		cin >> size;
		if (!cin || size <= 0)
		{
			cerr << "Error!!!\n";
			cout << "Try again...\n";
			cin.clear();
			cin.ignore(100, '\n');
			continue;
		}
		break;
	}

	for (int i = 0; i < size; i++)
	{
		t = new cycle;
		t->name = rand() % 99;
		if (start == NULL)
		{
			t->prev = NULL;
			start = t;
		}
		else
		{
			last->next = t;
			t->prev = last;
		}
		t->next = NULL;
		last = t;
	}

	show(start);

	int k{};
	cout << "\nEveryone K will be delete!!!\n";
	cout << "Write K <- ";
	cin >> k;
	if (!cin || size <= 0)
	{
		cerr << "Error!!!\n";
		cout << "Try again...\n";
		cin.clear();
		cin.ignore(100, '\n');
		return 0;
	}

	show(dell(&start, &last, k));

	return 0;
}


excluded* dell(cycle** s, cycle** l, int n)
{
	cycle* t{ *s }, * del{};
	excluded* r{ NULL }, * start{ NULL }, * end{ NULL };
	int numb{};

	while (true)
	{
		if (t == *s && t == *l)
		{
			r = new excluded;
			r->name = t->name;

			if (start == NULL)
			{
				start = r;
				r->prev = NULL;
			}
			else
			{
				end->next = r;
				r->prev = end;
			}
			end = r;
			r->next = NULL;

			*s = NULL;
			*l = NULL;
			delete t;

			return start;
		}
		numb++;
		if (numb == n)
		{
			numb = 0;
			if (t == *s)
			{
				(t->next)->prev = NULL;
			}
			else if (t == *l)
			{
				(t->prev)->next = NULL;
			}
			else
			{
				(t->next)->prev = t->prev;
				(t->prev)->next = t->next;
			}
			r = new excluded;

			r->name = t->name;

			if (start == NULL)
			{
				start = r;
				r->prev = NULL;
			}
			else
			{
				end->next = r;
				r->prev = end;
			}
			end = r;
			r->next = NULL;

			del = t;

			if (t == *s)
				*s = t->next;

			if (t == *l)
			{
				*l = t->prev;
				t = *s;
			}
			else
				t = t->next;
			delete del;
		}
		else
		{
			if (t == *l)
				t = *s;
			else
				t = t->next;
		}
	}
}