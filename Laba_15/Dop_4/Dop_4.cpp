#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Node
{
    int key;
    int value;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

fstream addElement;
string path = "File.txt";
int buffer_Key{}, buffer_Value{};

class HashTable
{
private:
    int size;
    const int SIZEZ = 1000;
    vector<Node*> table;

    int random_a = rand() % (SIZEZ - 1) + 1;
    int random_b = rand() % SIZEZ;

    

    int hash(int key) //универсальная
    {
        return ((random_a * key + random_b) % SIZEZ) % size;
    }

    /*int hash(int key) // модульное хеширование
    {
        return key % size;
    }*/

public:
    HashTable(int size) : size(size)
    {
        table.resize(size, nullptr);
    }

    void add(int key, int value)
    {
        int index = hash(key);
        Node* node = new Node(key, value);

        if (table[index] == nullptr)
        {
            table[index] = node;
        }
        else
        {
            Node* temp = table[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    int get(int key)
    {
        int index = hash(key);
        Node* temp = table[index];

        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void displayHashTable()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "[" << i << "] --> ";
            if (table[i] == nullptr)
            {
                cout << "EMPTY\n";
            }
            else {
                Node* currentNode = table[i];
                while (currentNode != nullptr)
                {
                    cout << "[ " << currentNode->key << ", " << currentNode->value << "\t ] --> ";
                    currentNode = currentNode->next;
                }
                cout << "END\n";
            }
        }
    }

    void workWithFile()
    {
        addElement.open(path, fstream::in);
        if (!addElement.is_open())
        {
            cout << "ERROR!!!...\n";
        }
        else
        {
            while (!addElement.eof())
            {
                addElement >> buffer_Key;
                addElement >> buffer_Value;

                add(buffer_Key, buffer_Value);
            }
        }
        addElement.close();
    }
};


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
    HashTable hashTable(10);
    hashTable.workWithFile();
    int key{};
    int value;
    while (true)
    {
        switch (menu())
        {
        case 1:
            cout << "Write key: ";
            cin >> key;
            cout << "Write element: ";
            cin >> value;
            hashTable.add(key, value);
            break;
        case 2:
            cout << "Write key for delete element: ";
            cin >> key;
            hashTable.remove(key);
            system("pause");
            break;
        case 3:
            cout << "Write key for search element: ";
            cin >> key;
            cout << "Element: " << hashTable.get(key) << "\n";
            system("pause");
            break;
        case 4:
            cout << "<-------------------HASH_TABLE------------------->\n";
            hashTable.displayHashTable();
            system("pause");
            break;

        case 0:  exit(0);
        default: exit(1);
        }
    }
    return 0;
}