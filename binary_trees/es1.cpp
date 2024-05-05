# include <cstdlib>
# include <iostream>

using namespace std;

// define the node of the binary tree
struct Node {
    int value;
    Node *right;
    Node *left;
};


void sortedOrder (Node *node) {
    // base case
    if (!node) {
        return;
    }

    sortedOrder (node -> left);
    cout << node -> value << ",";
    sortedOrder (node -> right);
}

void reversedSortedOrder (Node *node) {
    // base case
    if (!node) {
        return;
    }

    reversedSortedOrder(node -> right);
    cout << node -> value << ",";
    reversedSortedOrder (node -> left);
}


// left node does not work
void displayTree (Node *node, int counter) {
    // base case
    if (!node) {
        return;
    }
    displayTree (node -> left, counter + 1);
    cout << "\n";
    for (int i = 0; i < counter; i++) {
        cout << "         ";
    }
    cout << node -> value;
    displayTree (node -> right, counter + 1);
}

void freeMemory (Node *node) {
    // base case
    if (!node) {
        return;
    }
    freeMemory(node -> left);
    freeMemory(node -> right);
    delete node;
}

// alternative method from the text book
Node * addNode (Node *node, int value) {
    // if root
    if (!node) {
        Node *newNode = new Node;
        newNode -> value = value;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    if (node -> value > value) {
        node -> left = addNode(node -> left, value);
    }

    else {
        node -> right = addNode(node -> right, value);
    }

    return node;
}

int main () {
    Node *root = NULL;
    int add = 1;

    while (add) {
        int value;
        cout << "Set the value of the Node: ";
        cin >> value;
        root = addNode(root, value);
        displayTree(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    cout << "Display the nodes in sorted order: " << "\n";
    sortedOrder(root);

    cout << "\n";

    cout << "Display the nodes in reversed sorted order: " << "\n";
    reversedSortedOrder(root);

    freeMemory(root);
}