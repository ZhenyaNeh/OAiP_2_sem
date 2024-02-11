#pragma once

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