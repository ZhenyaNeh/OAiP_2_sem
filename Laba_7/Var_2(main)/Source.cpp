#include "Header.h"
#include <iostream>

using namespace std;

int menu() {
    cout << "1 - add element" << endl;
    cout << "2 - show stack" << endl;
    cout << "3 - clear stack" << endl;
    cout << "4 - delete first negative valua" << endl;
    cout << "5 - read file" << endl;
    cout << "6 - write in file" << endl;
    cout << "0 - exit" << endl;
    int choise;
    input(choise);
    return choise;
}

stack* addElements(stack* begin)
{
    int inf;
    input(inf);
    stack* t = new stack;
    t->inf = inf;
    t->next = begin;
    return t;
}

stack* addElementsFile(stack* begin, int buff)
{
    stack* t = new stack;
    t->inf = buff;
    t->next = begin;
    return t;
}

void showStack(stack* begin)
{
    cout << "--------------Stack--------------" << endl;
    stack* t = begin;
    while (t != NULL)
    {
        cout << "\t\t" << t->inf << endl;
        t = t->next;
    }
    cout << endl;
}

void deleteStack(stack** begin)
{
    while ((*begin) != NULL)
    {
        stack* t = *begin;
        (*begin) = (*begin)->next;
        delete t;
    }
    cout << "Stack cleared" << endl;
}

void input(int& a)
{
    while (true)
    {
        cin >> a;
        if (cin.good())
            break;
        cout << "Wrong input" << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
}

stack* deleteFirstNegativeValue(stack* begin)
{
    bool check = false;
    stack* t = begin;
    stack* p = begin->next;
    for (; p; p = p->next)
        if (p->inf < 0)
        {
            t = p;
            check = true;
            break;
        }
    if (check)
    {
        p = begin;
        if (p != t)
        {
            while (p->next != t)
                p = p->next;
            p->next = t->next;
        }
        else
            begin = t->next;
        delete t;
        return begin;
    }
    else
    {
        cout << "Stack dosn't has element more 100!!!\n";
        return begin;
    }
}

int write_In_File(stack** begin)
{
    if ((*begin) == NULL)
    {
        cout << "Steck clear!" << endl;
        return -1;
    }
    else
    {
        stack* t = (*begin);
        int a = (*begin)->inf;
        (*begin) = (*begin)->next;
        delete t;
        return a;
    }
}