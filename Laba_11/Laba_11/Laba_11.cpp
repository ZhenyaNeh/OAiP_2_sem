#include <iostream>
#include <iomanip>
using namespace std;

struct Tree 
{
    int value;
    Tree* left;
    Tree* right;
};

Tree* createTree(int value);
Tree* insert(Tree* root, int value);
int search(Tree* root, int value);
Tree* remove(Tree* root, int value);
void printTree(Tree* root, int indent);
int countLeaves(Tree* root);
int countLeavesRight(Tree* root);
int sum(Tree* root);
int menu(Tree* root);

int check{}, summ{};

int main() {
    Tree* root = NULL;
    int value{};
    while (true)
    {
        switch (menu(root))
        {
        case 1:  
            cout << "Write element: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2: 
            cout << "Write element for delete: ";
            cin >> value;
            remove(root, value);
            break;
        case 3: 
            cout << countLeaves(root) << "\n";
            system("pause");
            break;
        case 4:
            cout << countLeavesRight(root) << "\n";
            system("pause");
            break;
        case 5:
            cout << "Summ All element: ";
            cout << sum(root) << "\n";
            summ = 0;
            system("pause");
            break;
        case 6:
            cout << "Write element for search: ";
            cin >> value;
            cout << search(root, value) << "\n";
            check = 0;
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
    cout << "2 - Delete element...\n";
    cout << "3 - Nuber of list of tree...\n";
    cout << "4 - Nuber of list of tree(Right)...\n";
    cout << "5 - Summmmm...\n";
    cout << "5 - Poisk col number...\n";
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

Tree* createTree(int value) 
{
    Tree* node = new Tree;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Tree* insert(Tree* root, int value) 
{
    if (root == NULL) 
        return createTree(value);

    if (value < root->value) 
        root->left = insert(root->left, value);

    else 
        root->right = insert(root->right, value);
    return root;
}


Tree* remove(Tree* root, int value) 
{
    if (root == NULL) 
        return root;
    
    if (value < root->value) 
        root->left = remove(root->left, value);
    
    else if (value > root->value) 
        root->right = remove(root->right, value);
    
    else 
    {
        if (root->left == NULL) 
        {
            Tree* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) 
        {
            Tree* temp = root->left;
            delete root;
            return temp;
        }
        Tree* temp = root->right;

        while (temp->left != NULL) 
            temp = temp->left;
        
        root->value = temp->value;
        root->right = remove(root->right, temp->value);
    }
    return root;
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

int countLeaves(Tree* root) 
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int countLeavesRight(Tree* root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->right);
}

int search(Tree* root, int indent)
{
    
    if (root == NULL)
        return 1;
    search(root->right, indent);
    if(indent == root->value)
    {
        check++;
    }
    search(root->left, indent);
    return check;
}

int sum(Tree* root)
{
    if (root == NULL)
        return 1;
    sum(root->right);
    summ += root->value;
    sum(root->left);
    return summ;
}
