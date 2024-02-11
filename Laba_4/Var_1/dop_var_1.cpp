#include <iostream>
#include <stdio.h>
#include <string>
#define MAXSIZE 50
using namespace std;
// Nehaychik Evgeny Vladimirovich
void enter_new();
void show_struct();
void pass_ex();
void per_of_pass();

struct exam {
    string fullName;
    int numberOfExams;
    int marks[MAXSIZE];
};

int current_size = 0;
int choice;
struct exam student[MAXSIZE];
int main()
{
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter:" << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Determine pass exam or not(all marks >= 3)..." << endl;
    cout << "4 - Determine persent of student, who pass all exams(all marks >= 3)..." << endl;
    cout << "5 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    do 
    {
        switch (choice) 
        {
            case 1:enter_new(); break;
            case 2: show_struct(); break;
            case 3: pass_ex(); break;
            case 4: per_of_pass(); break;
        }
    } while (choice != 5);
}

void enter_new() 
{
    cout << "Enter the following:" << endl;
    if (current_size < MAXSIZE)
    {
        cout << "Full name: " << endl;
        cin.ignore();
        getline(cin, student[current_size].fullName);
        cout << endl;
        cout << "Amount of exams: " << endl;
        cin >> student[current_size].numberOfExams;
        cout << endl;
        cout << "Marks" << endl;
        for (int i = 0; i < student[current_size].numberOfExams; i++) 
        {
            cin >> student[current_size].marks[i]; cout << " ";
        }
        cout << endl;
        current_size++;
    }
    else 
    {
        cout << "error!";
    }
    system("pause");
    system("cls");
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter:" << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Determine pass exam or not(all marks >= 3)..." << endl;
    cout << "4 - Determine persent of student, who pass all exams(all marks >= 3)..." << endl;
    cout << "5 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    cout << endl;
}

void show_struct() 
{
    bool flag = false;
    for (int i = 0; i < current_size; i++) 
    {
        if(!flag)
        {
            cout << "Full Name: \t\t\tAmount Of Exams: \tMarks:\n";
            flag = true;
        }
        cout << student[i].fullName << "\t\t";
        cout << student[i].numberOfExams << "\t\t";
        for (int j = 0; j < student[i].numberOfExams; j++) 
        {
            cout << student[i].marks[j] << " ";
        }
        cout << "\n\n";
    }
    system("pause");
    system("cls");
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter:" << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Determine pass exam or not(all marks >= 3)..." << endl;
    cout << "4 - Determine persent of student, who pass all exams(all marks >= 3)..." << endl;
    cout << "5 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    cout << endl;
}

void pass_ex() 
{
    bool flag = false;
    for (int i = 0; i < current_size; i++)
    {
        if (!flag)
        {
            cout << "Full Name: \t\t\tAmount Of Exams: \tMarks:\n";
            flag = true;
        }
        cout << student[i].fullName << "\t\t";
        cout << student[i].numberOfExams << "\t\t";
        for (int j = 0; j < student[i].numberOfExams; j++)
        {
            cout << student[i].marks[j] << " ";
        }
        cout << "\n\n";
    }
    bool pass = true;
    for (int i = 0; i < current_size; i++) 
    {
        pass = true;
        for (int j = 0; j < student[i].numberOfExams; j++) 
        {
            if (student[i].marks[j] < 3)
            {
                pass = false;
                break;
            }
            else 
                continue; 
        }
        if (pass)
            cout << i + 1 << "-th student pass all exams" << endl;
        else 
            cout << i + 1 << "-th student not pass all exams" << endl;
    }
    system("pause");
    system("cls");
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter:" << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Determine pass exam or not(all marks >= 3)..." << endl;
    cout << "4 - Determine persent of student, who pass all exams(all marks >= 3)..." << endl;
    cout << "5 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    cout << endl;
}
void per_of_pass() 
{
    bool flag = false;
    for (int i = 0; i < current_size; i++)
    {
        if (!flag)
        {
            cout << "Full Name: \t\t\tAmount Of Exams: \tMarks:\n";
            flag = true;
        }
        cout << student[i].fullName << "\t\t";
        cout << student[i].numberOfExams << "\t\t";
        for (int j = 0; j < student[i].numberOfExams; j++)
        {
            cout << student[i].marks[j] << " ";
        }
        cout << "\n\n";
    }
    bool pass;
    int counter = 0;
    float persent_of_pass;
    for (int i = 0; i < current_size; i++) 
    {
        pass = true;
        for (int j = 0; j < student[i].numberOfExams; j++)
        {
            if (student[i].marks[j] < 3) 
            {
                pass = false;
                break;
            }
            else 
                continue;
        }
        if (pass) 
            counter++;
    }
    float counter2 = counter;
    float cur = current_size;
    persent_of_pass = (counter2 / cur) * 100;
    cout << persent_of_pass << " persent of student pass all exams" << endl;
    system("pause");
    system("cls");
    cout << "\t\t\t//////CHOOSE AN OPTION...//////\n" << endl;
    cout << "Enter:" << endl;
    cout << "1 - To enter new element of struct..." << endl;
    cout << "2 - To show struct..." << endl;
    cout << "3 - Determine pass exam or not(all marks >= 3)..." << endl;
    cout << "4 - Determine persent of student, who pass all exams(all marks >= 3)..." << endl;
    cout << "5 - Exit..." << endl;
    cout << "Your variant -> ";
    cin >> choice;
    cout << endl;
}