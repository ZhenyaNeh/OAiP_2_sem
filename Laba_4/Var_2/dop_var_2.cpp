#include <iostream>
#include <string>
#define MAXSIZE 30

using namespace std;

void enter_new();
void show_struct();


struct TRAIN {
    char destination[MAXSIZE];
    char numberOfTrain[MAXSIZE];
    string time;
};

int const tr_count = 8;
struct TRAIN train[tr_count];
int choice;
int current_size = 0;

int main()
{
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter: " << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    do 
    {
        switch (choice) 
        {
        case 1:enter_new(); break;
        case 2: show_struct(); break;
        }
    } while (choice != 3);
}
void enter_new() 
{
    cout << "\t\t\t//////ENTER THE DATA...//////\n" << endl;
    if (current_size < tr_count) 
    {
        cout << current_size + 1 << "th Destination Way: \n";
        cin >> train[current_size].destination;

        cout << "\nNumber Of Train: \n";
        cin >> train[current_size].numberOfTrain;
        
        cout << "\nTime(example HH:MM)\n";
        cin.ignore();
        getline(cin, train[current_size].time);

        cout << endl;
        current_size++;
    }
    else 
        cout << "error!";
    system("pause");
    system("cls");
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter: " << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    cout << endl;
}

void show_struct() 
{
    struct TRAIN buff;
    char* minimal = buff.destination;
    struct TRAIN buff_time;
    string time_s = buff_time.time;
    int k;
    int times[tr_count];

    cout << "\t\t\t!!!All TRAIN!!!\n";
    bool flag = false;
    for (int i = 0; i < current_size; i++)
    {
        if (flag == false)
        {
            cout << "Destination Way: \tNumber Of Train: \tTime\n";
            flag = true;
        }
        cout << train[i].destination << " \t\t\t";
        cout << train[i].numberOfTrain << " \t\t\t";
        cout << train[i].time << "\n\n";
    }

    cout << "Enter a time -> ";
    cin.ignore();
    getline(cin, time_s);
    cout << "\n\n";

    for (int i = 0; i < current_size; i++) 
    {
        int j, u;
        bool Found = false;
        for (u = 0; u <= i; u++) 
        {
            Found = false;
            for (int n = 0; n < i; n++)
            {
                if (u == times[n])
                {
                    Found = true;
                    break;
                }
                else 
                {
                    Found = false;
                    continue;
                }
            }
            if (not Found) 
                break;      
        }
        if (not Found)
        {
            minimal = train[u].destination;
            k = u;
        }
        for (j = 1; j < current_size; j++) 
        {
            bool found = false;
            for (int n = 0; n < i; n++) 
            {
                if (j == times[n]) 
                {
                    found = true;
                    break;
                }
                else 
                {
                    found = false;
                    continue;
                }
            }
            if (not found) 
            {
                for (int g = 0; g < MAXSIZE; g++) 
                {
                    if (minimal != train[j].destination) 
                    {
                        if (minimal[g] < train[j].destination[g])                        
                            break;                       
                        else if (minimal[g] > train[j].destination[g]) 
                        {
                            minimal = train[j].destination;
                            k = j;
                            break;
                        }
                        else 
                            continue;                     
                    }
                    else 
                        break;                   
                }
            }
        }
        times[i] = k;
    }
    bool FOUND = false;
    flag = false;
    for (int i = 0; i < current_size; i++) 
    {
        bool found = false;
        int time_entered = stoi(time_s.substr(0, 2));
        int time_i = stoi(train[times[i]].time.substr(0, 2));
        if (time_entered < time_i) 
        {
            found = true;
        }
        else if (time_entered == time_i) 
        {
            int time_entered = stoi(time_s.substr(3, 2));
            int time_i = stoi(train[times[i]].time.substr(3, 2));
            if (time_entered <= time_i) 
            {
                found = true;
            }
        }
        else 
        {
            found = false;
        }
        if (found) 
        {
            FOUND = true;
            if (!flag)
            {
                cout << "Destination Way: \tNumber Of Train: \tTime\n";
                flag = true;
            } 
            cout << train[times[i]].destination <<" \t\t\t";
            cout << train[times[i]].numberOfTrain << " \t\t\t";      
            cout << train[times[i]].time << "\n\n";
        }
    }
    if (not FOUND) 
        cout << "!!!There is no train after this time!!!" << endl;    
    system("pause");
    system("cls");
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter:" << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    cout << endl;
}


/*. Описать структуру с именем TRAIN, содержащую поля: названия пункта назначения, номер поезда,
время отправления. Написать программу, выполняющую ввод с клавиатуры данных в массив, состоящий 
из восьми элементов типа TRAIN (записи должны быть размещены в алфавитном порядке по названиям 
пунктов назначения); вывод на экран информации о поездах, отправляющихся после введенного с 
клавиатуры времени (если таких поездов нет, то вывести сообщение об этом).*/
