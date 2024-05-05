# include <cstddef>
# include <iostream>
# include <cstdlib>

using namespace std;

struct Node {
    int value;
    Node *nextNode;
};

Node *head = NULL;


Node* addNode (Node *list, int value) {
    Node *newNode = new Node;
    newNode -> value = value;
    newNode -> nextNode = list;
    head = newNode;
    return newNode;
}

void displayList (Node *node) {
    Node *current = node;
    while (current != NULL) {
        cout << current -> value << "--> ";
        current = current -> nextNode;
    }
    cout << "\n";
}


int main () {
    int add = 1;
    while (add) {
        int value;
        cout << "Set a value for the Node: ";
        cin >> value;
        Node *node = addNode(head, value);
        cout << "The list is: " << "\n";
        displayList(node);
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }
}