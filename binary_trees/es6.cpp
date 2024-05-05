// (name, email) address book (map)
// add, remove, search, update email addresses
// clean the address book at program shut down
// names are the values, comparable with <, >, =

# include <cstdlib>
# include <iostream>

using namespace std;


struct Address {
    string name;
    string email;
    Address *left;
    Address *right;

};


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

int main () {
    Address *root = NULL;
    int add = 1;

    while (add) {
        string name;
        string email;
        cout << "Set the name: ";
        cin >> name;
        cout << "Set the email: ";
        cin >> email;
        root = addNode(root, name, email);
        displayAddresses(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> add;
    }

    int remove = 1;

    while (remove) {
        string name;
        cout << "Set the name of the address to remove: ";
        cin >> name;
        root = removeNode(root, name);
        displayAddresses(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> remove;
    }

    int modify = 1;

    while (modify) {
        string name;
        string email;
        cout << "Set the name of the email to modify: ";
        cin >> name;
        cout << "Type the new email: ";
        cin >> email;
        updateEmail(root, name, email);
        displayAddresses(root, 1);
        cout << "\n";
        cout << "1 to continue, 0 to exit: ";
        cin >> modify;
    }

    int searchAddr = 1;

    while (searchAddr) {
        string name;
        cout << "Set the name of the email to search: ";
        cin >> name;
        Address *node = search(root, name);
        if (node) {
            cout << "Name on the address: " << node -> name << "\n";
            cout << "Email on the address: " << node -> email << "\n";
        }
        else {
            cout << "Address not present!" << "\n";
        }
        cout << "1 to continue, 0 to exit: ";
        cin >> searchAddr;
    }

    freeMemory(root);
}