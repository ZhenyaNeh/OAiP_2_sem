#include <iostream>
#include <vector>

using namespace std;
int check{};

void generate_Permutations(vector<int>& array_Of_Permutations, int start, int end) 
{
    if (start == end) 
    {
        cout << ++check << "-st: ";
        for (int i = 0; i < array_Of_Permutations.size(); i++) 
        {
            
            cout << array_Of_Permutations[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        for (int i = start; i <= end; i++) 
        {
            swap(array_Of_Permutations[start], array_Of_Permutations[i]);
            generate_Permutations(array_Of_Permutations, start + 1, end);
            swap(array_Of_Permutations[start], array_Of_Permutations[i]);
        }
    }
}

int main()
{
    int numb{0};
    cout << "Enter the array Size: ";

    while (true)
    {
        cin >> numb;
        if (!cin || numb < 0)
        {
            cerr << "Error!!!\n";
            cout << "Please, try again...\n";
            continue;
        }
        break;
    }

    vector<int> array_Of_Permutations(numb);
    for (int i = 0; i < numb; i++) 
        array_Of_Permutations[i] = i + 1;

    generate_Permutations(array_Of_Permutations, 0, numb - 1);

    return 0;
}