# include <cstdlib>
# include <iostream>
# include <algorithm>
# include <cmath>
# include "function_dec.h"

using namespace std;


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

int countNodes (Node *node) {

    if (!node) {
        return 0;
    }

    return 1 + countNodes(node -> left) + countNodes(node -> right);
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
    displayNodes (node -> right, counter + 1);
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


Address *addNode (Address *node, string name, string email) {
    if (!node) {
        Address *newNode = new Address;
        newNode -> name = name;
        newNode -> email = email;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    if (node -> name > name) {
        node -> left = addNode(node -> left, name, email);
    }

    else {
        node -> right = addNode(node -> right, name, email);
    }

    return node;
}

Address *search (Address *node, string name) {
    if (!node) {
        return NULL;
    }

    if (node -> name == name) {
        return node;
    }

    if (node -> name > name) {
        node = search(node -> left, name);
    }

    else {
        node = search(node -> right, name);
    }

    return node;
}


void updateEmail (Address *node, string name, string email) {
    if (!node) {
        cout << "The address you want to update is not present! ";
    }

    if (node -> name == name) {
        node -> email = email;
        cout << "Address successfully updated!";
    }

    if (node -> name > name) {
        updateEmail(node -> left, name, email);
    }

    else {
        updateEmail(node -> right, name, email);
    }
}


Address* findMax (Address *node) {
    if (!node) {
        return NULL;
    }

    if (!(node -> right)) {
        return node;
    }

    return findMax(node -> right);
}


Address* removeMax (Address *node, Address *maxNode) {
    if (!node) {
        return NULL;
    }

    if (node == maxNode) {
        return node -> left;

    }

    node -> right = removeMax(node -> right, maxNode);
    return node;
}


Address* removeNode (Address *node, string name) {
    if (node -> name == name) {
        if (node -> left == NULL) {
            Address *right = node -> right;
            delete node;
            return right;
        }

        if (node -> right == NULL) {
            Address *left = node -> left;
            delete node;
            return left;
        }

        Address *max = findMax(node -> left);
        Address *left = removeMax(node -> left, max);
        max -> right = node -> right;
        max -> left = left;
        delete node;
        return max;
    }
    else if (node -> name > name) {
        node -> left = removeNode(node -> left, name);
    }
    else {
        node -> right = removeNode(node -> right, name);
    }
    return node;
}

void freeMemory (Address *node) {
    if (!node) {
        return;
    }

    freeMemory(node -> left);
    freeMemory(node -> right);
    delete node;
}


void displayAddresses (Address *node, int counter) {
    if (!node) {
        return;
    }
    displayAddresses(node -> left, counter + 1);
    cout << "\n";
    for (int i = 0; i < counter; i++) {
        cout << "     ";
    }
    cout << "Name: " << node -> name << ", " << "Email: " << node -> email;
    displayAddresses(node -> right, counter + 1);
}
