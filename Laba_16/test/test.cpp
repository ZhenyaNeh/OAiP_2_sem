#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(NULL));
    int sizeA{}, sizeB{}, sizeC{};
    cout << "Write SIZE array A: ";
    cin >> sizeA;
    cout << "Write SIZE array B: ";
    cin >> sizeB;
    vector<int> arrayA;
    vector<int> arrayB;

    cout << "\nArray-A\n";
    for (int i = 0; i < sizeA; i++)
    {
        arrayA.push_back(rand() % 99 + 1);
        cout << " [ " << arrayA[i] << " ] ->";
    }
    cout << " END\n";

    cout << "\nArray-B\n";
    for (int i = 0; i < sizeB; i++)
    {
        arrayB.push_back(rand() % 99 + 1);
        cout << " [ " << arrayB[i] << " ] ->";
    }
    cout << " END\n";

    vector<int> arrayC;

    for (int i = 0; i < sizeA; i++)
    {
        if (arrayA[i] % 2 != 0)
        {
            arrayC.push_back(arrayA[i]);
        }
    }

    for (int i = 0; i < sizeB; i++)
    {
        if (arrayB[i] % 2 == 0)
        {
            arrayC.push_back(arrayB[i]);
        }
    }

    sizeC = arrayC.size();

    cout << "\nArray-C\n";
    for (int i = 0; i < sizeC; i++)
    {
        cout << " [ " << arrayC[i] << " ] ->";
    }
    cout << " END\n";

    sort(arrayC.rbegin(), arrayC.rend());

    cout << "\n\nSorted Array-C :\n";
    for (int i = 0; i < sizeC; i++)
    {
        cout << " [ " << arrayC[i] << " ] ->";
    }
    cout << " END\n";

    vector<int> arrayC2;
    arrayC2 = arrayC;

    cout << "\n\n\n\t\t\t\tBUBBLE METHOD \n\n\n";
    for (int i = 0; i < sizeC - 1; i++)
    {
        for (int j = 0; j < sizeC - i - 1; j++)
        {
            if (arrayC.at(j) < arrayC.at(j + 1))
            {
                swap(arrayC.at(j), arrayC.at(j + 1));
            }
        }
    }
    int flag = 1;
    for (int i = 0; i < sizeC; i++)
    {
        if (flag != 13)
            cout << "\t[" << arrayC[i] << "]";
        if (flag == 13)
        {
            cout << "\t[" << arrayC[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }

    cout << "\n\n\n\t\t\t\t SHELL METHOD \n\n\n";
    for (int step = sizeC / 2; step > 0; step /= 2)
    {
        for (int i = step; i < sizeC; i++)
        {
            for (int j = i; j >= step; j -= step)
            {
                if (arrayC2[j] > arrayC2[j - step])
                {
                    swap(arrayC2[j], arrayC2[j - step]);
                }
            }
        }
    }
    flag = 1;
    for (int i = 0; i < sizeC; i++)
    {
        if (flag != 13)
            cout << "\t[" << arrayC2[i] << "]";
        if (flag == 13)
        {
            cout << "\t[" << arrayC2[i] << "]\n\n";
            flag = 0;
        }
        flag++;
    }

    return 0;
}