#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Tree {
    int value;
    Tree* left;
    Tree* right;
    Tree(int x) : value(x), left(nullptr), right(nullptr) {}
};

void createTree(Tree*& root, int arr[], int& i, int n);
void printTree(Tree* root, int indent);

int main() 
{
    srand(time(NULL));
    int n{}, i{}, arr[20];
    cout << "Enter SIZE: ";
    cin >> n;

    for (int j = 0; j < n; j++)
        arr[j] = rand() % 9 + 1;

    Tree* root = nullptr;
    createTree(root, arr, i, n);
    cout << "-----------------TREE-----------------\n\n";
    printTree(root, 0);
    cout << "-----------------TREE-----------------\n\n";
    return 0;
}

void createTree(Tree*& root, int arr[], int& i, int n)
{
    if (i < n) 
    {
        root = new Tree(arr[i]);
        createTree(root->left, arr, ++i, n);
        if (i < n) 
        {
            root->right = new Tree(arr[i]);
            createTree(root->right, arr, ++i, n);
        }
    }
}

void printTree(Tree* root, int indent)
{
    if (root == NULL)
        return;
    indent += 5;
    printTree(root->right, indent);
    cout << setw(indent) << root->value << endl;
    printTree(root->left, indent);
}

