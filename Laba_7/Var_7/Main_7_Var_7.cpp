#include "Header.h"
#include <iostream>
#include <conio.h>
#include <fstream>


using namespace std;
int a{ 0 };

int main()
{ 
    string Path = { "File1.txt" };
    fstream working_Whith_File;
    int i{ 0 }, buff{0};
    
    stack* begin = NULL;
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Enter the element:" << endl;
            begin = addElements(begin);
            i++;
            cout << "Element added" << endl;
            break;
        case 2:
            showStack(begin);
            break;
        case 3:
            deleteStack(&begin);
            break;
        case 4:
            begin = deleteValueMore(begin);
            break;
        case 5:
            working_Whith_File.open(Path, fstream::in);
            if (!working_Whith_File.is_open())
            {
                cout << "error file";
                return 0;
            }
            while (!working_Whith_File.eof())
            {
                working_Whith_File >> buff;
                begin = addElementsFile(begin, buff);
                i++;
            }
            working_Whith_File.close();
            cout << "Element added" << endl;
            break;
        case 6:
            working_Whith_File.open(Path);
            if (!working_Whith_File.is_open())
            {
                cout << "error file";
                return 0;
            }
            for(int j = 0; j < i; j++)
            {
                buff = write_In_File(&begin);
                working_Whith_File << buff <<"\n";
            }
            cout << "Element added" << endl;
            working_Whith_File.close();
            break;
        case 0:
            cout << "Press Enter if you want to exit" << endl;
            if (_getch() == 13) {
                delete begin;
                return 0;
            }
            break;
        default:
            cout << "Choose 1-4 or 0" << endl;
            break;
        }
    }
}