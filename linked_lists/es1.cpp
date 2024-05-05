// doubly linked list

# include <cstdlib>
# include <iostream>

using namespace std;

struct Node {
    int value;
    Node *nextNode;
    Node *prevNode;
};

// the memory cell of the pointer contains NULL
Node *head = NULL;

void displayList (Node *node) {
    Node *current = node;
    while (current != NULL) {
        cout << current -> value << "--> ";
        current = current -> nextNode;
    }
    cout << "*";
    cout << "\n";
}

void addNode (int value) {
    Node *newNode = new Node;
    newNode -> value = value;
    newNode -> nextNode = head;
    newNode -> prevNode = NULL;
    if (head) {
        head -> prevNode = newNode;
    }
    head = newNode;
}

void removeNode (int value) {
    Node *current = head;
    while (current) {
        if (current -> value == value) {
            if (current -> prevNode) {
                current -> prevNode -> nextNode = current -> nextNode;
            }
            else {
                head = current -> nextNode;
            }
            if (current -> nextNode) {
                current -> nextNode -> prevNode = current -> prevNode;
            }
            // remember to deallocate the memory !
            delete current;
        }
        current = current -> nextNode;
    }
}

void addSorted (int value) {
    Node *newNode = new Node;
    newNode -> value = value;
    Node *current = head;

    // if is first Node
    if (!current) {
        newNode -> prevNode = NULL;
        newNode -> nextNode = NULL;
        head = newNode;
        return;
    }

    while (current -> value < newNode -> value) {
        // if is the last Node
        if (!current -> nextNode) {
            newNode -> nextNode = current -> nextNode;
            current -> nextNode = newNode;
            newNode -> prevNode = current;
            return;
        }
        current = current -> nextNode;
    }

    // if newNode goes into head (smallest value)
    if (!current -> prevNode) {
        newNode -> prevNode = current -> prevNode;
        newNode -> nextNode = current;
        head = newNode;
    }

    // if is in the middle
    else {
        current -> prevNode -> nextNode = newNode;
        newNode -> prevNode = current -> prevNode;
        current -> prevNode = newNode;
        newNode -> nextNode = current;
    }
}

void searchNode (int value) {
    Node *current = head;
    while (current) {
        if (current -> value == value) {
            cout << "The node is: " << "(value: " << current -> value << "," << " next: " << current ->nextNode << ")" << "\n";
            return;
        }
        current = current -> nextNode;
    }
    cout << "The node is not present!" << "\n";
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
        addNode(value);
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
        removeNode(value);
        cout << "The list is: " << "\n";
        displayList(head);
        cout << "1 to continue, 0 to exit: ";
        cin >> remove;
    }

    cout << "\n";

    freeList ();

    int addS = 1;
    while (addS) {
        int value;
        cout << "Set a value for the Node: ";
        cin >> value;
        addSorted(value);
        cout << "The list is: " << "\n";
        displayList(head);
        cout << "1 to continue, 0 to exit: ";
        cin >> addS;
    }
    cout << "\n";

    int search = 1;
    while (search) {
        cout << "The list is: " << "\n";
        displayList(head);
        int value;
        cout << "Node to search: ";
        cin >> value;
        searchNode(value);
        cout << "1 to continue, 0 to exit: ";
        cin >> search;
    }

    freeList();
}