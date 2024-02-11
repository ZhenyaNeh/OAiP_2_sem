#include<iostream>

using namespace std;

struct Number_First
{
    int info;
    Number_First* next;
};

struct Number_Second
{
    int info;
    Number_Second* next;
};

struct Number_Third
{
    int info;
    Number_Third* next;
};

enum Variant
{
    delete_First = 1,
    delete_Second,
    delete_Third
};

int min = 99;

template<class Type>
void create(Type** begin, Type** end, int p) //Формирование элементов очереди
{
    Type* t = new Type;

    t->next = NULL;

    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}

template<class Type>
void view(Type* begin) //Вывод элементов очереди 
{
    Type* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n\n";
        return;
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << ' ';
            t = t->next;
        }
        cout << "\n\n";
    }
}


void poisk(Number_First** begin, Number_First** end) //Вывод элементов очереди 
{
    Number_First* t = *begin;
    Number_First* start{}, * finish{}, * dell{};
    int min = 99;
    if (t == NULL)
    {
        cout << "Number is empty\n\n";
        return;
    }
    else
    {
        int i = 0;
        while (t != NULL)
        {
            if (t->info < min)
            {
                min = t->info;
                dell = t;
                i++;
            }
            t = t->next;
        }

        Number_First* newt = *begin;
        while(start != dell)
        {
            start = *begin;
            finish = *end;
            *end = start;
            *begin = start->next;
            start->next = NULL;
            finish->next = start;
        }
        delete dell;
          
        

        cout << "\n\n";
    }
}

template<class Type>
void del(Type** begin) //Удаление
{
    Type* t;
    t = new Type;
    t = *begin;
    *begin = (*begin)->next;
    delete t;
}
void menu();

int main()
{
    Number_First* begin_First = NULL, * end_First, * pointer_First;

    pointer_First = new Number_First;

    int number_Enter, size, flag_First{ 0 }, flag_Second{ 0 }, flag_Third{ 0 }, choice{ 1 };

   
        cout << "Enter size queue = ";
        cin >> size;
        cout << "Enter 1-st number: ";
        cin >> number_Enter;
        pointer_First->info = number_Enter;
        pointer_First->next = NULL;
        begin_First = end_First = pointer_First;

        for(int i = 1; i <= size-1; i++)
        { 
            cout << "Enter " << i + 1 << "-st number: ";
            cin >> number_Enter;
            create(&begin_First, &end_First, number_Enter);
        }
        cout << "You have peaked\n\n";

        view(begin_First);

        poisk(&begin_First, &end_First);



        cout << "First queue: \n";
        view(begin_First);

        
}