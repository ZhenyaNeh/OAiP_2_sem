#include <iostream>
#include <iomanip>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
};

void printTree(Node* root, int indent = 0) {
    if (root == NULL)
        return;

    indent += 4;

    printTree(root->right, indent);

    cout << setw(indent-2) << "➘" << setw(2) << root->value << endl;

    printTree(root->left, indent);
}

int main() {
    Node* root = new Node{ 1, new Node{2, new Node{4}, new Node{5}}, new Node{3} };

    printTree(root);

    return 0;
}