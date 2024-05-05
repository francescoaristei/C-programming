// recursive linked list.
// assumption: unique values for each node.

# include <cstdlib>
# include <iostream>

using namespace std;


struct Node {
    int value;
    Node *nextNode;
};

Node *head = NULL;


void addNode (Node *node, int value) {
    // first node
    if (!node) {
        Node *newNode = new Node;
        newNode -> value = value;
        newNode -> nextNode = NULL;
        head = newNode;
        return;
    }

    // last node reached
    else if (!node -> nextNode) {
        Node *newNode = new Node;
        newNode -> value = value;
        newNode -> nextNode = NULL;
        node -> nextNode = newNode;
        return;
    }

    addNode (node -> nextNode, value);
}

void removeNode (Node *node, int value) {
    // if is the head
    if (head -> value == value) {
        head = head -> nextNode;
        return;
    }

    // other cases
    if (node -> nextNode -> value == value) {
        node -> nextNode = node -> nextNode -> nextNode;
        return;
    }
    removeNode(node -> nextNode, value);
}

void displayList (Node *head) {
    Node *current = head;
    while (current) {
        cout << current -> value << " --> ";
        current = current -> nextNode;
    }
    cout << "*";
    cout << "\n";
}

void freeList () {
    Node *current = head;
    Node *toDelete = current;
    while (current) {
        current = current -> nextNode;
        delete toDelete;
        toDelete = current;
    }
}


int main () {
    int add = 1;
    while (add) {
        int value;
        cout << "Set a value for the Node: ";
        cin >> value;
        addNode(head, value);
        cout << "The list is: " << "\n";
        displayList(head);
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    cout << "\n";

    int remove = 1;
    while (remove) {
        int value;
        cout << "Set the value of the Node to remove: ";
        cin >> value;
        removeNode(head, value);
        cout << "The list is: " << "\n";
        displayList(head);
        cout << "1 to continue, 0 to exit: ";
        cin >> remove;
    }
    cout << "\n";

    freeList();

}