#include <iostream>

using namespace std;//тута функцию вычисления хеш на универсальную ииии 9 лаба модульная

struct HashItem
{
    int key;
    int value;
};


const int SIZEZ = 1000;
int random_a = rand() % (SIZEZ - 1) + 1;
int random_b = rand() % SIZEZ;
const int TABLE_SIZE = 10;
HashItem table[TABLE_SIZE];

int hashFunction(int key) //универсальная
{
    return ((random_a * key + random_b) % SIZEZ) % TABLE_SIZE;
}

//int hashFunction(int key) //модульная
//{
//    return key % TABLE_SIZE;
//}

int insert(int key, int value)
{
    int check{};
    int index = hashFunction(key);
    while (table[index].key != 0)
    {
        index = (index + 1) % TABLE_SIZE;
        check++;
        if (check == TABLE_SIZE)
        {
            cout << "Table is full...\n";
            return 0;
        }
    }
    table[index].key = key;
    table[index].value = value;
    return 1;
}

int search(int key)
{
    int check{};
    int index = hashFunction(key);
    while (table[index].key != 0)
    {
        if (table[index].key == key)
        {
            return table[index].value;
        }
        index = (index + 1) % TABLE_SIZE;
        check++;
        if (check == TABLE_SIZE)
        {
            cout << "Table does not have such an element...\n";
            return 0;
        }
    }
    return -1;
}

int dellete(int key)
{
    int infoPlace{}, check{};
    int index = hashFunction(key);
    while (table[index].key != 0)
    {
        if (table[index].key == key)
        {
            infoPlace = table[index].value;
            table[index].key = 0;
            table[index].value = 0;

            int nextIndex = (index + 1) % TABLE_SIZE;
            while (table[nextIndex].key != 0)
            {
                int tempKey = table[nextIndex].key;
                int tempValue = table[nextIndex].value;
                table[nextIndex].key = 0;
                table[nextIndex].value = 0;
                insert(tempKey, tempValue);
                nextIndex = (nextIndex + 1) % TABLE_SIZE;
            }
            return infoPlace;
        }
        index = (index + 1) % TABLE_SIZE;
        check++;
        if (check == TABLE_SIZE)
        {
            cout << "Table does not have such an element...\n";
            return 0;
        }
    }
    return -1;
}

void printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i].key != 0)
        {
            cout << "Key: " << table[i].key << "\t\tValue: " << table[i].value << "\n";
        }
    }
}

int menu()
{
    int variant{};
    system("cls");
    cout << "1 - ADD element...\n";
    cout << "2 - Delete element...\n";
    cout << "3 - Search number...\n";
    cout << "4 - Print HESH-TABLE...\n";
    cout << "0 - Exit...\n";
    cout << "Your variant -> ";

    while (true)
    {
        cin >> variant;
        if (!cin || variant < 0 || variant > 4)
        {
            cerr << "Error!!!\n";
            cout << "Try again...\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }
        break;
    }
    return variant;
}

int main()
{

    int value{}, key{};
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Write key: ";
            cin >> key;
            cout << "Write element: ";
            cin >> value;
            insert(key, value);
            break;
        case 2:
            cout << "Write key for delete element: ";
            cin >> key;
            dellete(key);
            system("pause");
            break;
        case 3:
            cout << "Write key for search element: ";
            cin >> key;
            cout << "Element: " << search(key) << "\n";
            system("pause");
            break;
        case 4:
            cout << "<-------------------HASH_TABLE------------------->\n";
            printTable();
            system("pause");
            break;

        case 0:  exit(0);
        default: exit(1);
        }
    }

    return 0;

    /*insert(1, 10);
    insert(2, 20);
    insert(3, 30);
    insert(4, 7);
    insert(5, 7);
    insert(6, 7);
    insert(7, 7);
    insert(8, 7);
    insert(9, 7);
    insert(10, 7);
    insert(17, 7);
    cout << search(7) << endl;
    cout << dellete(17) << endl;*/
}