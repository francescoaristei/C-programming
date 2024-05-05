# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <cmath>

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

int ifBalanced (Node *node, int height, bool *balanced) {
    if (!node) {
        return height;
    }

    int left_height = ifBalanced(node -> left, height + 1, balanced);
    int right_height = ifBalanced(node -> right, height + 1, balanced);

    if (abs(left_height - right_height) > 1) {
        *balanced = false;
    }

    return max(left_height, right_height);

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

    bool balanced = true;

    ifBalanced(root, 0, &balanced);

    cout << "Is the tree balanced? ";

    if (balanced) {
        cout << "Yes!";
    }
    else {
        cout << "No!";
    }
    
    freeMemory(root);
}