#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
    int key;
    string value;
    Node* next;

    Node(int key, string value) : key(key), value(value), next(nullptr) {}
};

fstream addElement;
string path = "File.txt";
int buffer_Key{};
string buffer_Value;
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

    void add(int key, string value)
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

    string get(int key)
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
        return "not found";
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

    int pos(string value)
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] == nullptr)
            {
                
            }
            else {
                Node* currentNode = table[i];
                while (currentNode != nullptr)
                {
                    if (currentNode->value == value) {
                        return 1;
                    }
                    currentNode = currentNode->next;
                }
            }
        }
        return 0;
    }

    int posbt(char value)
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] == nullptr)
            {

            }
            else {
                Node* currentNode = table[i];
                while (currentNode != nullptr)
                {
                    if (currentNode->value[0] == value) {
                        return 1;
                    }
                    currentNode = currentNode->next;
                }
            }
        }
        return 0;
    }

    void rem(char value)
    {
        int key = 0;
        int index = hash(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr)
        {
            if (temp->value[0] == value)
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

    void workWithFile(int s)
    {
        addElement.open(path, fstream::in);
        if (!addElement.is_open())
        {
            cout << "ERROR!!!...\n";
        }
        else
        {
            for(int i = 0; i < s; i++)
            {
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
    cout << "5 - poisk...\n";
    cout << "6 - dell...\n";
    cout << "0 - Exit...\n";
    cout << "Your variant -> ";

    while (true)
    {
        cin >> variant;
        if (!cin || variant < 0 || variant > 6)
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
    HashTable hashTable(30);
    cout << "write size ";
    int s;
    cin >> s;
    hashTable.workWithFile(s);
    int key{}, res{1};
    string value;
    char test;
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

        case 5:
            cout << "Write element for poisk: ";
            cin >> value;
            if (hashTable.pos(value) == 1)
                cout << "Yesssssss";
            system("pause");
            break;
        case 6:
            cout << "Write key for delete element: ";
            cin >> test;
            while(res == 1)
            {
                hashTable.rem(test);
                res = hashTable.posbt(test);
            }
            system("pause");
            break;

        case 0:  exit(0);
        default: exit(1);
        }
    }
    return 0;
}