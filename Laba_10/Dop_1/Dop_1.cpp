#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void generate(string stroke, int length, char max_digit, ofstream& file);

int main() 
{
    int numb;
    cout << "Enter the A: ";
    cin >> numb;

    ofstream file("File.txt");
    if (!file.is_open()) 
    {
        cout << "Error!!!" << endl;
        return 1;
    }

    generate("", numb, '0' + numb, file);

    file.close();
    return 0;
}

void generate(string stroke, int length, char max_digit, ofstream& file)
{
    if (length == 0) 
        cout << stroke << endl;
    
    else 
    {
        for (char digit = '0'; digit < max_digit; digit++) 
            generate(stroke + digit, length - 1, max_digit, file);
        
    }
}