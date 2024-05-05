# include <cstdlib>
# include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
};

Node* addNode (Node *node, int value) {
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


void displayNodes (Node *node, int counter) {
    if (!node) {
        return;
    }

    displayNodes(node -> left, counter + 1);
    cout << "\n";
    for (int i = 0; i < counter; i++) {
        cout << "     ";
    }
    cout << node -> value;
    displayNodes(node -> right, counter + 1);
}


void freeMemory (Node *node) {
    if (!node) {
        return;
    }
    freeMemory(node -> left);
    freeMemory(node -> right);
    delete node;
}

int maxOfMin (Node *node) {
    if (!node -> right) {
        return node -> value;
    }

    return maxOfMin(node -> right);
}

int minOfMax (Node *node) {
    if (!node -> left) {
        return node -> value;
    }

    return minOfMax(node -> left);

}

bool checkSorted (Node *node) {
    if (!node) {
        return true;
    }

    return (maxOfMin(node -> left) < node -> value) && (minOfMax(node -> right) > node -> value);
}

int main () {
    Node *root = NULL;
    int add = 1;

    while (add) {
        int value;
        cout << "Set the value of the node: ";
        cin >> value;
        root = addNode(root, value);
        displayNodes(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    cout << "Is the tree sorted? ";
    if (checkSorted(root)) {
        cout << "Yes!";
    }
    else {
        cout << "No!";
    }

    
    freeMemory(root);
}