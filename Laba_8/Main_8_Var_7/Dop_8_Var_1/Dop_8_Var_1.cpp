#include<iostream>
using namespace std;
struct Item
{
	int data;
	Item* next;
};
Item* head, * tail;

struct Item1
{
	int data;
	Item1* next;
};
Item1* head1, * tail1;


bool isNull(void)    //Проверка на пустоту
{
	return (head == NULL);
}
bool isNull1(void)    //Проверка на пустоту
{
	return (head1 == NULL);
}
void deletFirst()   //Извлечение элемента из начала
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		Item* p = head;
		head = head->next;
		delete p;
	}
}
void getFromHead()  //Получение элемента из начала
{
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
		cout << "Начало = " << head->data << endl;
}
void insertToQueue(int x)  //Добавление элемента в очередь 
{
	Item* p = new Item;      //новый указатель 
	p->data = x;
	p->next = NULL;
	Item* v = new Item;      //указатель для нового числа
	Item* p1 = new Item;
	Item* p2 = new Item;
	int i = 0;               //флажок
	if (isNull())
		head = tail = p;
	else
	{
		p2 = head;
		p1 = head;
		while (p1 != NULL)  //пока очередь не закончится
		{
			if (i == 1)
			{
				if (x <= p1->data)  //число меньше, чем в очереди
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;      // следующее число
			}
			else
			{
				if (x <= p1->data)
				{
					v->data = x;
					v->next = p1;
					head = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail->next = p;
			tail = p;
		}
	}
}

void printQueue()             //Вывод очереди
{
	Item* p = new Item;
	if (isNull())
		cout << "Очередь пуста" << endl;
	else
	{
		cout << "Очередь = ";
		p = head;
		while (!isNull())
		{
			if (p != NULL)
			{
				cout << p->data << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

void clrQueue()           //Очистка очереди
{
	while (!isNull()) deletFirst();
}



void insertToQueue1 (int x)  //Добавление элемента в очередь 
{
	Item1* p = new Item1;      //новый указатель 
	p->data = x;
	p->next = NULL;
	Item1* v = new Item1;      //указатель для нового числа
	Item1* p1 = new Item1;
	Item1* p2 = new Item1;
	int i = 0;               //флажок
	if (isNull1())
		head1 = tail1 = p;
	else
	{
		p2 = head1;
		p1 = head1;
		while (p1 != NULL)  //пока очередь не закончится
		{
			if (i == 1)
			{
				if (x >= p1->data)  //число меньше, чем в очереди
				{
					v->data = x;
					v->next = p1;
					p2->next = v;
					return;
				}
				p2 = p2->next;      // следующее число
			}
			else
			{
				if (x >= p1->data)
				{
					v->data = x;
					v->next = p1;
					head1 = v;
					return;
				}
			}
			p1 = p1->next;
			i = 1;
		}
		if (p1 == NULL)
		{
			tail1->next = p;
			tail1 = p;
		}
	}
}

void printQueue1()             //Вывод очереди
{
	Item1* p = new Item1;
	if (isNull1())
		cout << "Очередь пуста" << endl;
	else
	{
		cout << "Очередь = ";
		p = head1;
		while (!isNull1())
		{
			if (p != NULL)
			{
				cout << p->data << "->";
				p = p->next;
			}
			else
			{
				cout << "NULL" << endl;
				return;
			}
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int i = 1, choice = 1, z; head = NULL;  tail = NULL;
	while (choice != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - добавить элемент ex_2" << endl;
		cout << "3 - получить элемент с начала" << endl;
		cout << "4 - извлечь элемент с начала" << endl;
		cout << "5 - вывести элементы" << endl;
		cout << "6 - очистить очередь" << endl;
		cout << "0 - выход" << endl;
		cout << "Выберите действие  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите элемент:  ";
			cin >> z;
			insertToQueue(z);
			system("cls");
			printQueue();
			break;
		case 2: cout << "Введите элемент:  ";
			cin >> z;
			insertToQueue1(z);
			system("cls");
			printQueue1();
			break;
		case 3: getFromHead(); break;
		case 4: deletFirst();  break;
		case 5: printQueue();  break;
		case 6: clrQueue();    break;
		}
	}
	return 0;
}
