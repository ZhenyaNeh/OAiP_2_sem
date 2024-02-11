#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Tree
{
    int value;
    string name;
    string rate;
    Tree* left;
    Tree* right;
};

Tree* createTree(int value, string name, string rate);
Tree* insert(Tree* root, int value, string name, string rate);
int search(Tree* root, int value);
int menu(Tree* root);
void printTree(Tree* root, int indent);

int check{}, mts{}, a1{}, life{};

int main() {
    Tree* root = NULL;
    int value{};
    string name, rate;
    while (true)
    {
        switch (menu(root))
        {
        case 1:
            cout << "Write number: ";
            cin >> value;
            cout << "Write name: ";
            cin >> name;
            cout << "Write rate: ";
            cin >> rate;
            root = insert(root, value, name, rate);
            break;
        case 2:
            cout << "Write number for search people: ";
            cin >> value;
            cout << search(root, value) << "\n";
            system("pause");
            break;
            
            break;
        case 3:
            if (mts > a1 && mts > life)
                cout << "The best is !!!MTS!!!\n ";
            if(a1 > mts && a1 > life)
                cout << "The best is !!!A1!!!\n ";
            if(life > mts && life > a1)
                cout << "The best is !!!LIFE!!!\n ";
            system("pause");
            break;
        case 0:  exit(0);
        default: exit(1);
        }
    }

    return 0;
}

int menu(Tree* root)
{
    int variant{};
    system("cls");
    cout << "-----------------TREE-----------------\n\n";
    printTree(root, 0);
    cout << "-----------------TREE-----------------\n\n";
    cout << endl;
    cout << "1 - Write element...\n";
    cout << "2 - Seach people...\n";
    cout << "3 - The best of the best of the best rate...\n";
    cout << "0 - Exit...\n";
    cout << "Your variant -> ";

    while (true)
    {
        cin >> variant;
        if (!cin || variant < 0 || variant > 3)
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

Tree* createTree(int value, string name, string rate)
{
    Tree* node = new Tree;
    node->value = value;
    node->name = name;
    node->rate = rate;
    if (rate == "a1")
        a1++;
    if (rate == "life")
        life++;
    if (rate == "mts")
        mts++;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* insert(Tree* root, int value, string name, string rate)
{
    if (root == NULL)
        return createTree(value, name, rate);

    if (value < root->value)
        root->left = insert(root->left, value, name, rate);

    else
        root->right = insert(root->right, value, name, rate);
    return root;
}

void printTree(Tree* root, int indent)
{
    if (root == NULL)
        return;
    indent += 5;
    printTree(root->right, indent);
    cout << setw(indent) << root->value << ' ' << root->name << ' ' << root->rate << endl;
    printTree(root->left, indent);
}


int search(Tree* root, int indent)
{
    if (root == NULL)
        return 0;
    search(root->right, indent);
    if (indent == root->value)
    {
        cout << root->value << ' ' << root->name << ' ' << root->rate << endl;
    }
    search(root->left, indent);
}
