# include <iostream>
# include <cstdlib>

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

void displayNode (Node *node, int counter) {
    if (!node) {
        return;
    }

    displayNode(node -> left, counter + 1);
    cout << "\n";
    for (int i = 0; i < counter; i++) {
        cout << "     ";
    }
    cout << node -> value;
    displayNode(node -> right, counter + 1);
}

Node** increaseArray (int dim, Node **nodeArr) {
    Node **newNodeArr = new Node*[2*dim];
    for (int i = 0; i < dim; i++) {
        newNodeArr[i] = nodeArr[i];
    }

    for (int i = dim; i < 2*dim; i++) {
        newNodeArr[i] = NULL;
    }

    return newNodeArr;
}


// DOES NOT WORK: If you allocate memory with the new to create nodeArr, then the 'delete' will delete
// the memory allocated for these pointers, not the memory allocated to the Node objects to which these pointers point.
// Creating a new array, does not work.
void freeMemory (Node *node) {
    // initial dim = 3 (root, left, right)
    int dim = 3;

    // pointer to an array of pointers, each pointer points to an instance of the struct Node
    Node **nodeArr = new Node* [dim];

    // to iterate over the array
    int pointer = 0;
    int counter = 0;

    // initially the root
    nodeArr[counter] = node;
    counter += 1;

    while (pointer < counter) {
        if (counter == dim || counter == dim - 1) {
            nodeArr = increaseArray(dim, nodeArr);
            dim = 2*dim;
        }

        if (nodeArr[pointer] -> left) {
            nodeArr[counter] = nodeArr[pointer] -> left;
            counter += 1;
        }

        if (nodeArr[pointer] -> right) {
            nodeArr[counter] = nodeArr[pointer] -> right;
            counter += 1;
        }
        pointer += 1;
    }

    counter = 0;

    while (nodeArr[counter]) {
        delete nodeArr[counter];
        counter += 1;
    }

    delete nodeArr;
}


int main () {
    Node *root = NULL;
    int add = 1;

    while (add) {
        int value;
        cout << "Set the value of the node: ";
        cin >> value;
        root = addNode(root, value);
        displayNode(root, 0);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }


    freeMemory(root);
    cout << "\n";

    cout << "The root is: ";
    if (!root) {
        cout << "NULL!";
    }
    else {
        cout << "not NULL!";
    }
}