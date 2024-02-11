#include<iostream>
#include"Header.h"

using namespace std;

int main()
{
    Number_First* begin_First = NULL, * end_First, * pointer_First;
    Number_Second* begin_Second = NULL, * end_Second, * pointer_Second;
    Number_Third* begin_Third = NULL, * end_Third, * pointer_Third;
    
    pointer_First = new Number_First;
    pointer_Second = new Number_Second;
    pointer_Third = new Number_Third;

    int number_Enter, size, flag_First{ 0 }, flag_Second{ 0 }, flag_Third{ 0 }, choice{1};

    while(choice != 0)
    {
        cout << "Enter size queue = ";
        cin >> size;

        for (int i = 0; i < size; i++)
        {
            cout << "Enter " << i + 1 << "-st number: ";
            cin >> number_Enter;

            if (number_Enter > 0) {
                if (flag_First == 0)
                {
                    pointer_First->info = number_Enter;
                    pointer_First->next = NULL;
                    begin_First = end_First = pointer_First;
                    flag_First++;
                }
                else
                    create(&begin_First, &end_First, number_Enter);
            }
            if (number_Enter < 0) {
                if (flag_Second == 0)
                {
                    pointer_Second->info = number_Enter;
                    pointer_Second->next = NULL;
                    begin_Second = end_Second = pointer_Second;
                    flag_Second++;
                }
                else
                    create(&begin_Second, &end_Second, number_Enter);
            }
            if (number_Enter == 0) {
                if (flag_Third == 0)
                {
                    pointer_Third->info = number_Enter;
                    pointer_Third->next = NULL;
                    begin_Third = end_Third = pointer_Third;
                    flag_Third++;
                }
                else
                    create(&begin_Third, &end_Third, number_Enter);

            }
        }
        cout << "You have peaked\n\n";

        cout << "First queue: \n";
        view(begin_First);

        cout << "Second queue: \n";
        view(begin_Second);

        cout << "Thirth queue: \n";
        view(begin_Third);

        while(choice != 0)
        {
            menu();
            cin >> choice;

            switch(choice)
            {
                case delete_First:
                    cout << "Delete First:\n";
                    del(&begin_First);
                    cout << "First queue: \n";
                    view(begin_First);
                    cout << "\n";
                    break;

                case delete_Second:
                    cout << "Delete Second:\n";
                    del(&begin_Second);
                    cout << "Second queue: \n";
                    view(begin_Second);
                    cout << "\n";
                    break;

                case delete_Third:
                    cout << "Delete Third:\n";
                    del(&begin_Third);
                    cout << "Thirth queue: \n";
                    view(begin_Third);
                    cout << "\n";
                    break;

                default:
                    cout << "Exit complite!!!";
                    break;
            }
        }
    }
    return 0;
}
